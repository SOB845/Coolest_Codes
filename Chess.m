function [ Z ] = Chess(n)
Z = zeros(n);

for i = 1:n
    for j = 1:n
        if rem(i,2) == 0
            
            if rem(j,2) == 0
                Z(i,j)=1;
            else
                Z(i,j)=0;
            end
            
        else
            if rem(j,2) == 0
                Z(i,j) = 0;
            else
                Z(i,j) = 1;
            end
        end
    end
end
disp(Z)
end

