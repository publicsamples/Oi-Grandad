1. Replacing the std::sin() seed hash with a cheap deterministic integer hash

2. Cache pitch-mode multipliers per grain where possible
 	- getPitchModeMul() still does pow() and sin() in some modes
	- some of that can be precomputed per grain or only updated when params change

3. Reduce trig in window calculation
	- morphedWindow() / tukey() still uses cos() per grain per sample
	- this is a real hotspot
	- a LUT or cheaper window approximation could help a lot
	- this one has more sonic risk than the hash change, but still can be done carefully

4. Precompute scale-mode ratios
	- scale modes currently call pow(2.0, semis / 12.0)
	- that can be table-driven easily
	- essentially zero downside

5. Simplify read-phase wrap handling
	- the while (grain.readPhase >= grainSize) and < 0.0 loops are probably not the main issue, but can be tightened to branchy clamp/wrap logic if bounds are known

6. Avoid per-sample lambdas / repeated branch setup
	- the getQStyleReadPhase lambda inside the grain loop is probably not catastrophic, but flattening some of that logic may help a little
