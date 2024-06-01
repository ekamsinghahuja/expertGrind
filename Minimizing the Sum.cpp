#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// solved by makeinve
void solve(){
    ll n,k;cin>>n>>k;
    

    vector<ll> vec(n);
    for(ll i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1e16));
    for(ll i=0;i<=k;i++){
        dp[0][i]=0;
    }
    for(ll i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0] + vec[i-1];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k;j++){
            ll minima = vec[i-1];
            for(ll p=0;p<=min(j,i-1);p++){
                minima = min(minima,vec[i-p-1]);
                dp[i][j] = min(dp[i-p-1][j-p] + minima*(p+1) ,dp[i][j]);
            }
        }
    }
    

    cout<<dp[n][k]<<endl;


}

 
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
   
    
    return 0;
}
 
 
 
 