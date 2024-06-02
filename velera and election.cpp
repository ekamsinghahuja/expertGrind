#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// solved by makeinve

int f(int node,int parent,vector<vector<int>>& adj,vector<int>& road,vector<int>& subtree){
    // cout<<node<<endl;
    if(road[node]==1){
        subtree[node]++;
    }
    for(auto child:adj[node]){
        if(child==parent)continue;
        subtree[node] += f(child,node,adj,road,subtree);
    }
    return subtree[node];

}


void solve(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    vector<int> roads(n,0),subtree(n,0);
    for(int i=0;i<n-1;i++){
        int u,v,t;
        cin>>u>>v>>t;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        if(t==2){
            roads[u-1]=1;
            roads[v-1]=1;
        }
    }
    int a = f(0,-1,adj,roads,subtree);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(subtree[i]==1){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++){
        if(subtree[i] == 1){
            cout<<i+1<<endl;
        }
    }



    
}

 
int main(){
    ll t=1;
    
    
    while(t--){
        solve();
    }
   
    
    return 0;
}
 
 
 

