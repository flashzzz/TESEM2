#include<bits/stdc++.h>
using namespace std ;

int q=1; 

bool is_safe(vector<vector<int>>ans, int i, int j, int n){
    for(int x=0;x<n;x++){
        for(int y=0;y<=i;y++){
            if(ans[x][y]==1 && (x==j || y==i || x-y == j-i || x+y == i+j)){
                return false;
            }
        }
    }
    return true;
}


void nqueens(vector<vector<int>>ans, int n, int i){
    if(i==n){
        cout<<"\nPossible Solution "<<q<<"\n";
        q++;
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                cout<<ans[a][b]<<" ";
            }
            cout<<endl;
        }
        
        return ;
    }

    for(int j=0;j<n;j++){
        if(is_safe(ans,i,j,n)){
            ans[j][i]=1;
            nqueens(ans,n,i+1);
            ans[j][i]=0;
        }
    }
}


int main(){
    int n;cin>>n;
    vector<vector<int>>ans;
    for(int a=0;a<n;a++){
        ans.push_back(vector<int>());
        for(int b=0;b<n;b++){
            ans[a].push_back(0);
        }
    }
    if(n==1){cout<<"1"<<endl;return 0;}
    if(n<=3){cout<<"Not Possible !!!!";return 0;}
        
    nqueens(ans,n,0);
}