function [Adj_Matrix] = Erdos_Renyi(S)

Adj_Matrix = zeros(S);

for m = 1:S
    for n = 1:S
        if m == n
            continue
        else
            Adj_Matrix(m,n) = randi([0,1]); % A random binary matrix, may not be symmetric
        end
    end
end

% Next section ensures symmetry of the generated matrix
for i = 1:S
    for j = 1:S
        if i == j
            continue
        elseif Adj_Matrix(i,j) ~= Adj_Matrix(j,i)
            Adj_Matrix(i,j) = Adj_Matrix(j,i);
        else
            continue
        end
    end
end

G = graph(Adj_Matrix);
L = full(laplacian(G)); % Laplacian matrix in its full (non-sparse) form
assignin('base','G',G); % Saves the graph to workspace
assignin('base','L',L); 
plot(G)

end
