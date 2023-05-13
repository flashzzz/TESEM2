#include<bits/stdc++.h>
 
using namespace std ;
const int N=1e3+2;
vector<vector<int>> v(N);
vector<int> vis(N,0);

void bfs(int u)
{

    queue<int> q;
    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(auto i : v[cur]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
            }
        }
    }
    // return;
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
        v[b].push_back(a);}
	bfs(1);
	return 0;
}
 
