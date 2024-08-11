function [totENR] = total_ENR(Graph,i,resVect)
%UNTITLED2 Summary of this function goes here
% formula: (n-1)*rho_i^2*pinvLap(i,i) - 2*rho_i*sum(rho_j*pinvLap(i,j))+sum(rho_j^2*pinvLap(j,j))

n = numnodes(Graph);
rho_i = resVect(i);

L = full(laplacian(Graph));
pinvLap = pinv(L);

Srho_j = sum(resVect)-rho_i;
Sigma = sum(pinvLap,'all')-sum(pinvLap(i,:),'all');

totENR = (n-1)*(rho_i^2)*pinvLap(i,i)-(2*rho_i*Srho_j*Sigma)+(sum(resVect.^2)-(rho_i)^2)*(trace(pinvLap)-pinvLap(i,i));
end

