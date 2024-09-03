%{ Copyright (c) 2020, Lu Ce All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution
* Neither the name of  nor the names of its
  contributors may be used to endorse or promote products derived from this
  software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%}


function hc = harmoniccentrality(G,s)
%hc = harmoniccentrality(G,s)
%G is a graph, directed or no
%select is a vector of zeros and ones
%s is an optional string, in for incloseness, out for outcloseness
%
%21 February 2018, Richard S.J. Tol

n = size(G.Nodes,1);
dist = distances(G);
invdist = dist.^-1;
for i=1:n
    invdist(i,i)=0;
end

if ~exist('s')
    hc = (n-1)*sum(invdist,2);
elseif s(1)=='o'
    hc = (n-1)*sum(invdist,2);
elseif s(1)=='i'
    hc = (n-1)*sum(invdist,1)';
else
    hc = 0;
end

end
       
