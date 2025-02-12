%Daniel Taylor, 12/11/2024, Intro to Autonomous Vehicles Final Project

%load scenenario data files
load('Final_Project_Driving_ScenarioMATFile.mat');
refPose=data.ActorSpecifications.Waypoints;

%Define reference points
xRef=refPose(:,1);
yRef=-refPose(:,2);

%Define vehicle parameters
X_o=xRef(1);
Y_o=yRef(1);

%Calculating reference pose vectors
%calculate distance vectors
distmatrix= squareform(pdist(refPose));
distancesteps=zeros(length(refPose)-1,1);
for i=2:length(refPose)
distancesteps(i-1,1)=distmatrix(i,i-1);
end
totalDistance=sum(distancesteps);
distbp=cumsum([0;distancesteps]);
gradbp=linspace(0,totalDistance,50);
%Linearize X and Y
xRef2=interp1(distbp,xRef,gradbp);
yRef2=interp1(distbp,yRef,gradbp);
yRef2s=smooth(gradbp,yRef2);
xRef2s=smooth(gradbp,xRef2);
plot(gradbp,xRef2s)
xlabel('distance')
ylabel('x')
plot(gradbp,yRef2s)
xlabel('distance')
ylabel('y')

%calculate theta vector
thetaRef=zeros(length(gradbp),1);
for i=2:length(gradbp)
thetaRef(i,1)=atan2d((yRef2(i)-yRef2(i-1)),(xRef2(i)-xRef2(i-1)));
end
thetaRefs=smooth(gradbp,thetaRef);
psi_o=thetaRefs(1)*(pi/180);%initial yaw angle
plot(gradbp,thetaRefs)
xlabel('distance')
ylabel('theta')

%create direction vector
direction=ones(length(gradbp),1);

%Calculate curvature vector
curvature=getCurvature(xRef2,yRef2);
plot(gradbp,curvature)
xlabel('distance')
ylabel('curvature')

%Curvature function

function curvature=getCurvature(xRef,yRef)
% calculate gradient
DX=gradient(xRef);
D2X=gradient(DX);
DY=gradient(yRef);
D2Y=gradient(DY);
curvature=(DX.*D2Y-DY.*D2X)./(DX.^2+DY.^2).^(3/2);
end

