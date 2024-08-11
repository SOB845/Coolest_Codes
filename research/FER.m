function [Adj_Matrix] = FER(nodesNum)
%FER: Fast Erdos-Renyi model

Graph = rand(nodesNum) < 0.5;
Graph = triu(Graph,1);
Adj_Matrix = Graph + Graph';

G = graph(Adj_Matrix);
H = plot(G);
assignin('base','G',G); % Saves the graph to workspace
assignin('base','G_plot',H);
end

