#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// solved by makeinve

bool cc(int k,string s){
   
    vector <int> diff(s.size()+1,0);
    int n = s.size();
    for(int i=0;i<=n-k;i++){
       
        if(i!=0){
            diff[i] += diff[i-1];
        }
        if(diff[i]%2==1){
            if(s[i]=='0'){
                s[i]='1';
            
            }
            else{
                s[i]='0';
            }
            
        }
        if(s[i]=='0'){
            s[i]='1';
           
            diff[i]+=1;
            diff[i+k]-=1;
        }
       
    }
    for(int i=n-k+1;i<n;i++){
        if(i!=0){
            diff[i] += diff[i-1];
        }
        if(diff[i]%2==1){
            if(s[i]=='0'){
                s[i]='1';
            
            }
            else{
                s[i]='0';
            }
            
        }
    }
    for(int i=0;i<n;i++){

        if(s[i]=='0')return 0;
    }
    return 1;
}


void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    int l=0,r=n-1;
    int ans=-1;
    for(int i=1;i<=n;i++){
        bool check = cc(i,s);
        if(check){
            ans = i;
        }
    }
    cout<<ans<<endl;

}

 
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
   
    
    return 0;
}
 
 
 

