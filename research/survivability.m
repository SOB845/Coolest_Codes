function [sigmarray] = survivability(Rs,Ft)
sigmarray = []; % Array to hold each sigma_t(node)
Rsum = sum(Rs); % sum of all all ENRs = total ENR

for node = 1:length(Rs)
    psi = Rs(node)/Rsum;
    sigmarray(1,node) = (1-psi)*Ft^(-1);
end
end