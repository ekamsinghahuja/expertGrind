#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// solved by makeinve
void solve(){
    int n;cin>>n;
    vector<int> vec(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        mp[vec[i]]=i;
    }
    vector<int>res(n,-1);
    int pick = (n-2)/2;
    vector<int> picked;
    for(int i=1;i<n-1;i++){
        if(vec[i]!=1){
            picked.push_back(vec[i]);
            res[i]=0;
            i++;
        }
    }
    vector<int> npick;
    for(int i=0;i<n;i++){
        if(res[i]==-1){
            npick.push_back(vec[i]);
        }
    }
    sort(picked.begin(),picked.end());
    sort(npick.begin(),npick.end(),greater<int>());
    int cnt=n;
    for(int i=0;i<picked.size();i++){
        res[mp[picked[i]]] = cnt--;
    }
    int cntt=1;
    for(int i=0;i<npick.size();i++){
        res[mp[npick[i]]] = cntt++;
    }
    for(auto x:res){
        cout<<x<<" ";
    }
    cout<<endl;


}

 
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
   
    
    return 0;
}