function [totENR] = total_ENR(Graph,i,resVect)
% Total effective node resistance: R_i
% R_i = (n-1)*rho_i^2*pinvLap(i,i) - 2*rho_i*sum(rho_j*pinvLap(i,j))+sum(rho_j^2*pinvLap(j,j))

n = numnodes(Graph);
L = full(laplacian(Graph));
pinvLap = pinv(L);
rho_i = resVect(i);

% This section uses the Matlab feature of indexing
d = diag(pinvLap);
index = true(1,n);
index(i) = false;
S2 = sum(resVect(index) .* pinvLap(i, index)); %resVect(index) deletes ith index from resVect

totENR = (n-1)*(rho_i^2)*pinvLap(i,i) - (2*rho_i*S2) + sum(resVect(index).^2 .* transpose(d(index)));
end
