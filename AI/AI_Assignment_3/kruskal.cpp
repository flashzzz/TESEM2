#include<bits/stdc++.h>
using namespace std ;

class Edge{
	public:
		int u,v,wt;
};

class kruskals{
	int V;int E;
	vector<Edge>adj;
	void addedge(int i,int j,int wt);

	public:
		void getvertices();
		void create_min_span_tree();
};

void kruskals::getvertices(){
	cin>>V;
	E=0;
	int x,y,z;
	while(1){
		cin>>x>>y>>z;
		if(x==-1 || y==-1)break;
		E++;
		addedge(x,y,z);
	}
}

void kruskals::addedge(int i,int j,int w){
	Edge e;
	e.u = i;
	e.v = j;
	e.wt = w;
	adj.push_back(e);
}

bool cmp(Edge x,Edge y){
	return ( x.wt > y.wt ) ;
}


void kruskals::create_min_span_tree(){
	set<int>s;
	int e=0;
	int i=E-1;
	int cost=0;
	sort(adj.begin(),adj.end(),cmp);cout<<endl;
	while(e<V-1){
		if(s.find(adj[i].u)==s.end() || s.find(adj[i].v)==s.end()){
			s.insert(adj[i].u); s.insert(adj[i].v);
			cout<<adj[i].u<<" ------------------ "<<adj[i].v<<endl;
			cost += adj[i].wt;
			e++;
		}
		adj.pop_back();
		i--;
	}
	cout<<"Cost : "<<cost;
}

int main(){
	kruskals p;
	p.getvertices();
	p.create_min_span_tree();

// 6
// 0 1 7
// 0 2 8
// 1 2 3
// 1 4 6
// 2 3 3
// 2 4 4
// 3 4 2
// 3 5 2
// 4 5 5
// -1 -1 3


// cost = 17
}