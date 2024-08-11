function [simple_ENR] = effective_node_resistance(i,j,resVect,Graph)
%Calculates ENR (R_ij) of the nodes i & j
% 'Graph' can be generated using FER function
n = numnodes(Graph);
ei = zeros(n,1);
ej = zeros(n,1);

ei(i,1) = 1;
ej(j,1) = 1;
rho_i = resVect(i);
rho_j = resVect(j);

L = full(laplacian(Graph));
pinvLap = pinv(L);
% ENR = transpose((rho_i*ei) - (rho_j*ej))*pinvLap*((rho_i*ei)-(rho_j*ej));
simple_ENR = (rho_i)^2*(pinvLap(i,i))-2*rho_i*rho_j*pinvLap(i,j)+ (rho_j)^2*(pinvLap(j,j));

% assignin('base','ENR',ENR);
assignin('base','simple_ENR',simple_ENR);
end