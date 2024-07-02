
m1 = 0.032; % Mass [Kg]
L0 = 0.06; 
L1 = 0.035 ; % half Pendulum Length [m]
g=9.81; %Gravitational acceleration [m/s^2] 
I0 = 220e-3 ;
J1 = 76e-2 ;

A = [0 , 1 , 0 , 0;
     0 , 0 , (-g*m1*m1*L1*L1*L0)/(I0*(J1+m1*L1*L1) + J1*m1*L0*L0) , 0;
    0 , 0 , 0 , 1;
    0 , 0 , (m1*L1*g*(I0+m1*L0*L0))/(I0*(J1+m1*L1*L1) + J1*m1*L0*L0) , 0];
B= [0;
    (J1+m1*L1*L1)/(I0*(J1+m1*L1*L1) + J1*m1*L0*L0); 
    0; 
    (-m1*L1*L0)/(I0*(J1+m1*L1*L1) + J1*m1*L0*L0);
    ];

C= eye(4); 
%D=[0; 0 ; 0 ; 0 ]; 
%eig(A)
%Section 2: Free Response
%K= [0,0,0,0]

%Section 3: Forced Response
%K = place(A,B,[-1,-3,-5.0,0])
%K = place(A,B,[-10,-30,-20.0,0])
Q = [1 0 0 0;  %table angle Theta0
    0 20 0 0;  %table velocity Theta0_dot
    0 0 500 0;  %pendulum angle Theta1
    0 0 0 500]; %pendulum velocity Theta1_dot

R = 1;

K = lqr(A,B,Q,R);
%K = [-10.0   -115.741561581931 3874.52575218962  398.631042564539];


x0 = [ 0; 0;0.174; 0];       % initial condition 
ref = [0; 0; 0; 0];      % reference position
