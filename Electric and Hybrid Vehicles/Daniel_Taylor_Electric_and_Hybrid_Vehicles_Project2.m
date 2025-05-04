%Assignment 4 – Daniel Taylor 
 
%variables needed 
k = 1.107;   %perukert coefficient, unitless 
c10 = 42;    %Amphour (Ah)
t = 10;      %hours

%discharge capacity with T = 10 
%meaning that with T = 10, it is 10 hours to discharge 42A 

%find the actual current being used
actualCurrent = c10/t; %should be 4.2
peukertCapacity = (actualCurrent^k)*t;
 
%PART 1 
%Calculate and plot the battery effective capacity for a discharge current range from 4A to 43A 
 
%range of 4-43 with jumps of current by 0.25A (what rawa said she wanted in class) 
I = 4:0.25:43;

%time matrix (same size as current range) intialized with zeros
time = zeros(size(I));
%capacity matrix initialized with zeros
effectiveCapacity = zeros(size(I));
 

%for loop
%Cp = (I^k) * t, so t = Cp/I^k
for x = 1:length(I)
    % at each step, find the Time (using peukert model)
    time(x) = peukertCapacity/((I(x))^k);
    % using that time, find the effective capacity for each current
    effectiveCapacity(x) = (time(x) * I(x));
end

 
%plot peukert capacity figure 
plot(I, effectiveCapacity, 'LineWidth', 1.5); 
title('Effective Capacity vs. Current');
xlabel('Current (A)'); 
ylabel('Effective Capacity (Ah)'); 
grid on; 
