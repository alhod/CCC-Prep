#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, bool>m;

ll checkMultiples(ll n){
    ll currBest=n;
    // cout<<"n: "<<n<<endl;
    for(ll i=1; i<n; i++){
        if(n%i==0){
            // cout<<"n divisible by "<<i<<endl;
            if(m[i]==1){
                ll nCopy=n-i;
                bool imp=false;
                while(nCopy>0){
                    if(m[nCopy]==0){
                        imp=true;
                        // cout<<nCopy<<" is 0"<<endl;
                        break;
                    }
                    nCopy-=i;
                }
                if(imp==true){
                    continue;
                }
                // cout<<"return "<<i<<endl;
                return i;
            }
        }
    }
    // cout<<"return "<<n<<endl;
    return currBest;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        
        ll op=0;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                op+=checkMultiples(i+1);
                m[i+1]=1;
            }
        }
        cout<<op<<endl;
        m.clear();
    }
}