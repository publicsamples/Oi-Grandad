// =============================================================================
//      Live concatenative granular processing
// =============================================================================
//
// This software implements non-overlapping granulation with rectangular 
// windowing, i.e., concatenative granular processing live.
//
// The main concerns with concatenative granulation are the artefacts due to
// the interconnection of uncorrelated sonic fragments, which  result in signal
// discontinuities. 
//
// Reducing low-order derivatives discontinuities is key to drastically reduce
// artefacts. This technique deploys zeroth and first-order derivative
// analysis with Lagrange polynomoials for a smooth transition between grains.
//
// For best results, the algorithm should run at 192 kHz sample rate and
// it should be compiled in double-precision.
// 
// For feature requests and bug reports, please email 
//      sanfilippo.dario at gmail dot com.
//
// Copyright (C) Dario Sanfilippo 2021.
// =============================================================================

import("stdfaust.lib");

declare name "Concatenative Granular Processing";
declare author "Dario Sanfilippo";
declare copyright "Copyright (C) 2021 Dario Sanfilippo 
    <sanfilippo.dario@gmail.com>";
declare version "1.0";
declare license "MIT license";

// -----------------------------------------------------------------------------
//      Lagrange interpolation
// -----------------------------------------------------------------------------
lagrange_h(N, x_vals, idx) = par(n, N + 1, prod(k, N + 1, f(n, k)))
    with {
        vals(i) = ba.take(i + 1, x_vals);
        f(n, k) = ((idx - vals(k)) * (n != k) + (n == k)) / 
            ((vals(n) - vals(k)) + (n == k));
    };
lagrangeN(N, x_vals, idx) = lagrange_h(N, x_vals, idx) ,
                            si.bus(N + 1) : si.dot(N + 1);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Fractional index tables
// -----------------------------------------------------------------------------
frwtable(N, S, init, w_idx, x, r_idx) =
    lagrangeN(N, x_vals, f_idx, par(i, N + 1, y_vals(i_idx - int(N / 2) + i)))
    with {
        x_vals = par(i, N + 1, i);
        y_vals(j) = rwtable(S, init, w_idx, x, int(ma.modulo(j, S)));
        f_idx = ma.frac(r_idx) + int(N / 2);
        i_idx = int(r_idx);
    };
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Buffer definitions
// -----------------------------------------------------------------------------
ibuffer(r_idx, x) = rwtable(size, .0, index, x, int(ma.modulo(r_idx, size))); 
fbuffer(r_idx, x) = frwtable(5, size, .0, index, x, r_idx);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Maths
// -----------------------------------------------------------------------------
zc(x) = x * x' < 0; 
up(x) = diff(x) > 0; 
down(x) = diff(x) < 0; 
diff(x) = x - x'; 
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      One-pole low-pass
// -----------------------------------------------------------------------------
lp1p(cf, x) = fi.pole(b, x * (1 - b))
    with {
        b = exp(ma.PI * -cf);
    };
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Time transposition processing
// -----------------------------------------------------------------------------
pos(x) = os.phasor(size, t_fact) + buff_pos + pos_async
    with {
        pos_async = lp1p(t_cf, x) * t_depth;
    };
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Pitch transposition processing
// -----------------------------------------------------------------------------
ptc(x) = p_fact + ptc_async <: 
    ba.if(<(0), max(-16, min(-1 / 16)), min(16, max(1 / 16)))
    with {
        ptc_async = lp1p(p_cf, x) * p_depth;
    };
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Input processing for live or looped buffer
// -----------------------------------------------------------------------------
input(x) =  +(x * (1 - r)) ~ 
            (de.delay(size - 1, size - 1) * r);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Buffer size and writing pointer definition
// -----------------------------------------------------------------------------
size = 192000 * 10; 
index = ba.period(size);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Concatenative granulation function
// -----------------------------------------------------------------------------
CGP(len, pos, pitch, x) =   loop ~ 
                            _ : ! , 
                                _
    with {
        loop(y) =   grain , 
                    Lgrain
            with {
                // Non-interpolated output
                grain = fbuffer(offset + line, x);
                // Trigger function
                t = loop ~ 
                    _ 
                    with {
                        loop(reset) = 
                            (fi.pole(1 - reset, 1) >= 
                                ba.sAndH(1 - 1' + reset, len)) & zc(y);
                    };
                // Trigger-locked pitch variations
                pitch_sah = ba.sAndH(1 - 1' + t, pitch);
                // Pitch transposition function
                line = fi.pole(1 - t, 1 - t) * pitch_sah;
                // Grain position processing
                offset = ba.sAndH(t, zc_sel + corr) 
                    with {
                        dir = ma.signum(pitch_sah);
                        zc_sel =    ba.if(  diff(y) * dir > 0, 
                                            zc_up(pos, x), 
                                            zc_down(pos, x));
                        zc_up(read, x) = 
                            ibuffer(read, ba.sAndH(zc(x) & up(x), index)); 
                        zc_down(read, x) = 
                            ibuffer(read, ba.sAndH(zc(x) & down(x), index)); 
                        corr = y_diff / safe_den(x_diff) + (dir - 1) / 2
                            with {
                                y_diff = diff(y);
                                x_diff = ibuffer(zc_sel, diff(x));
                                safe_den(den) = ba.if(  den < 0,
                                                        min(0 - ma.EPSILON, den),
                                                        max(ma.EPSILON, den));
                            };
                    };
                // Switching section (interpolation)
                Lgrain = ba.if( lline < L, 
                                lagrangeN(N, x_vals, lline, y_vals), 
                                grain)
                    with {
                        N = 5;
                        halfp = (N + 1) / 2;
                        // X-axis spacing
                        x_vals = par(i, N + 1, (i - halfp) * 
                            (i < halfp) + (i + L - halfp) * (i >= halfp));
                        // Interpolation points
                        y_vals =    l_points , 
                                    r_points
                            with {
                                l_points = 
                                    par(i, halfp, 
                                        ba.sAndH(t, y @ (halfp - 1 - i)));
                                r_points = 
                                    par(i, halfp, 
                                        fbuffer(offset + (L + i) * pitch_sah, x));
                            };
                        // Interpolation index
                        lline = min(L, +(1 - t)) ~ 
                                *(1 - t);
                    };
            };
    };
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      GUI parameters
// -----------------------------------------------------------------------------
L = int(hslider("[00]Interpolation length (samples)", 16, 4, 64, 1));
len = hslider("[01]Grain length (ms)", 100, 1, 6400, 0.001) * ma.SR / 1000;
buff_pos = hslider("[02]Buffer position", 0, 0, 1, .000001) * size;
t_fact = hslider("[03]Time transposition", 1, -16, 16, .000001) * 
    (ma.SR / size);
t_cf = hslider("[04]Time async degree", 0, 0, 1, .000001);
t_depth = hslider("[05]Time async depth", 0, 0, size, .000001);
p_fact = hslider("[06]Pitch transposition", 1, -16, 16, .000001);
p_cf = hslider("[07]Pitch async degree", 0, 0, 1, .000001);
p_depth = hslider("[08]Pitch async depth", 0, 0, 1000, .000001);
r = checkbox("[09]Freeze buffer");
vol = hslider("[10]Volume", 0, 0, 1, .000001);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//      Main process
// -----------------------------------------------------------------------------
process(x1, x2) =   (   loop1 ~ 
                        _) * vol , 
                    (   loop2 ~ 
                        _) * vol
    with {
        loop1(fb) = CGP(len, pos(fb), ptc(fb), input(x1));
        loop2(fb) = CGP(len, pos(fb), ptc(fb), input(x2));
    };
// -----------------------------------------------------------------------------