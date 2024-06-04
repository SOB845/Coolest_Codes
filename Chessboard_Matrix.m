% This function yields an n*n binary matrix
% Its enteries represent colours of a chessboard (White square = 1, Black square = 0)
% E.g: Chess(5) = [1 0 1 0 1; 0 1 0 1 0; 1 0 1 0 1; 0 1 0 1 0; 1 0 1 0 1]

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

end
