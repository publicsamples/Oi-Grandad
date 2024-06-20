import("stdfaust.lib");
import("owl.lib");

vca_a = hslider("VCA_A[OWL:A]",0,0,1,0.001);
vca_b = hslider("VCA_B[OWL:B]",0,0,1,0.001);
env1_scale = hslider("ENV_SCALE1[OWL:C]",1, 0.5, 5, 0.01);
env2_scale = hslider("ENV_SCALE2[OWL:D]",1, 0.5, 5, 0.01);
b1 = button("A_MUTE[OWL:B1]") : ba.impulsify : ba.toggle;
b2 = button("B_MUTE[OWL:B2]") : ba.impulsify : ba.toggle;

env1_out = hbargraph("ENV_A>[OWL:F]", 0, 1);
env2_out = hbargraph("ENV_B>[OWL:G]", 0, 1);

env1 = _ <:attach(_, abs : si.smoo * env1_scale : env1_out);
env2 = _ <:attach(_, abs : si.smoo * env2_scale : env2_out);

process = (vca_a * (1-b1) * _), (vca_b * (1-b2) * _) : env1, env2;

