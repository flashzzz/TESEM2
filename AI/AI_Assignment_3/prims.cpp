#include<bits/stdc++.h>
using namespace std ;

class prims{
	int V;
	vector<vector<pair<int,int>>>adj;
	void addedge(int i,int j,int wt);

	public:
		void getvertices();
		void create_min_span_tree(int x);
};

void prims::getvertices(){
	cin>>V;
	adj = vector<vector<pair<int,int>>>(V);
	int x,y,z;
	while(1){
		cin>>x>>y>>z;
		if(x==-1 || y==-1)break;
		addedge(x,y,z);
	}
}

void prims::addedge(int i,int j,int wt){
	adj[i].push_back(make_pair(j,wt));
	adj[j].push_back(make_pair(i,wt));
}

void prims::create_min_span_tree(int node =0){
	vector<bool>visited(V,false);
	int itr = V;
	int cost=0;
	while(itr--){
		cout<<node<<" ";
		int mindist=INT_MAX;
		visited[node]=true;
		for(int i=0;i<V;i++){
			if(visited[i]){
				for(int j=0;j<adj[i].size();j++){
					if(!visited[adj[i][j].first]){
						if(adj[i][j].second<=mindist){
							mindist = adj[i][j].second;
							node=adj[i][j].first;
						}
					}
				}
			}
		}
		if(mindist<100)cost+=mindist;
	}

	cout<<"\ncost : "<<cost;

}

int main(){
	prims p;
	p.getvertices();
	p.create_min_span_tree();

// 6
// 0 1 12
// 0 2 8
// 0 5 3
// 1 2 5
// 2 3 6
// 2 4 1
// 3 4 9
// 4 5 3
// -1 -1 3
}