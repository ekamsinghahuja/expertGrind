#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// solved by makeinve

pair<int,int> bfs(int b,int a,vector<vector<int>>& adj){
    int n = adj.size();
    queue<pair<int,int>> q;
    vector<int> dist_a(n,INT_MAX);
    vector<int> dist_b(n,INT_MAX);
    dist_a[a]=0,dist_b[b]=0;

    q.push({b,1});q.push({a,0});
    while(!q.empty()){
        int front = q.front().first;
        int type = q.front().second;
        q.pop();
        if(dist_a[front] != INT_MAX && dist_a[front] >= dist_b[front]){
            return {front,dist_a[front]};
        }
        for(auto x:adj[front]){
            if(type==1){
                if(dist_b[front] + 1 < dist_b[x]){
                    dist_b[x] = dist_b[front]+1;
                    q.push({x,1});
                }
            }
            else{
                if(dist_a[front]+1<dist_a[x]){
                    dist_a[x] = dist_a[front]+1;
                    q.push({x,0});
                }
            }
        }
    }
    return {-1,-1};

}



void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    a--,b--;
    auto [meet_point,dist] = bfs(a,b,adj);
    // cout<<meet_point<<" "<<dist<<endl;

    function<pair<int,int>(int,int)> dfs = [&](int node, int parent)->pair<int,int>{
        pair<int,int> p;
        int t_cost=0,depth=0;
        for (auto x : adj[node]) {
            if (parent != x){
                auto [a1,a2] = dfs(x, node);
                t_cost += a1+(a2-1)+2;
                depth = max(depth,a2);
            }   
        }
        t_cost-=depth;
        return {t_cost,depth+1};
    };

    auto [t_cost,dep] = dfs(meet_point,-1); 
    cout<<t_cost + dist<<endl;
    return;
}

 
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
   
    
    return 0;
}
 
 
 

