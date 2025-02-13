% parameters
Co = 0.009;
CD = 0.2;
m = 692;
AF = 2;
C1 = 1.75e-6;
p = 1.16;
g = 9.81;
beta = 0;
vi = 0;
vf = 60 * 0.447;
%range for time, 0 seconds to 10 seconds
t = [0:10];

%velocity profile
v_t = 20 * log((0.282*t) + 1);
%acceleration
a_t = diff(v_t);

%PART A - FINDING FTR AND PTR

%sum of Forces = ma
%Ftr - Faero - Froll - Fg = ma
%level road, so Fg, Potential = 0
%Ftr = ma + Froll + Faero
Froll = m * g * cos(beta) * (Co * (C1 * v_t.^2));
Faero = 0.5 * p * CD * AF * (v_t.^2);
Ftr = m*a_t + Froll(1:end-1) + Faero(1:end-1); 

%Ptr = Ftr * V
Ptr = v_t(1:end-1).*Ftr;

%plotting velocity, power, force vs. Time
subplot(4,1,1);
plot(t(1:end-1), v_t(1:end-1));
xlabel("Time (s)")
ylabel("Velocity (m/s)")

subplot(4,1,2);
plot(t(1:end-1), Ptr);
xlabel("Time(s)");
ylabel("Power (W)");

subplot(4,1,3);
plot(t(1:end-1), Ftr);
xlabel("Time(s)");
ylabel("Force (N)");

%PART B - Calculate ΔeTR. How much of ΔeTR is ΔKE? How much is Eloss?
% eTR = Ekinetic + Epotential + Eloss, Epotential = 0
%eTR = Ekinetic + Eloss

Ekinetic = 0.5 * m * v_t.^2;
Eloss = trapz(v_t.*(Froll + Faero), t);
eTR = Ekinetic + Eloss; 

%percentKE = EkineticDisc/eTR;
%percentEloss = ElossDisc/eTR;

%plotting energy vs time
subplot (4,1,4);
plot(t(1:end-1), eTR(1:end-1));
xlabel("Time(s)");
ylabel("Energy (J)");