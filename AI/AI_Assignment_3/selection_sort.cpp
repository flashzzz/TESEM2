#include<bits/stdc++.h>
using namespace std ;

void selection_sort(int arr[],int n){
    int mineleindex;
    for(int i=0;i<n-1;i++){
        mineleindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mineleindex]){
                mineleindex=j;
            }
        }
        if(mineleindex!=i)swap(arr[mineleindex],arr[i]);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
}

int main(){
int n;cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
selection_sort(arr,n);
}