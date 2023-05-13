// Time Complexity : O(V^2)    with adjacency matrix
// Time Complexity : O((V+E)logV)   with adjacency list

#include<bits/stdc++.h>
using namespace std ;

class dijkstra{
	int V;
	vector<vector<pair<int,int>>>adj;
	void addedge(int i,int j,int wt);

	public:
		void getvertices();
		void min_dist_to_all(int x);
};

void dijkstra::getvertices(){
	cin>>V;
	adj = vector<vector<pair<int,int>>>(V);
	int x,y,z;
	while(1){
		cin>>x>>y>>z;
		if(x==-1 || y==-1)break;
		addedge(x,y,z);
	}
}

void dijkstra::addedge(int i,int j,int wt){
	adj[i].push_back(make_pair(j,wt));
	adj[j].push_back(make_pair(i,wt));
}

void dijkstra::min_dist_to_all(int node =0){
    vector<int>dist(V,INT_MAX);
    vector<bool>visited(V,false);
    dist[node]=0;
    int xyz;
    int j=0;
    while(j<V-1){
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i].first]){
                dist[adj[node][i].first] = min(dist[adj[node][i].first], dist[node]+adj[node][i].second);
            }
        }
        visited[node]=true;
        xyz = INT_MAX;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dist[i] <= xyz){
                    node = i;
                    xyz = dist[i];
                }
            }
        }
        j++;
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    

}

int main(){
	dijkstra d;
	d.getvertices();
	d.min_dist_to_all();

// 6
// 0 1 4
// 0 2 5
// 1 2 11
// 1 4 7
// 1 3 9
// 2 4 3
// 3 4 13
// 3 5 2
// 4 5 6
// -1 -1 3
}