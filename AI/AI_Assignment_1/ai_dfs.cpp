#include<bits/stdc++.h>
 
using namespace std ;
const int N=1e3+2;
vector<vector<int>> v(N);
vector<int> vis(N);

void dfs(int u)
{
    vis[u]=1;
    
    cout<<u<<" ";
    for(auto i:v[u]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    return;
}

int main( )
{
    
    // cout<<"Enter number of nodes: ";
    int n;cin>>n;
    // cout<<"Enter number of edges: ";
    int m;cin>>m;
    for(int i=0;i<m;i++) 
    {
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    return 0 ;
}  
