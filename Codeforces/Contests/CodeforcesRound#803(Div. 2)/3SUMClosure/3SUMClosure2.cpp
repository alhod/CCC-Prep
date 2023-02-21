#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> pos, neg, z;
        for(ll i=0; i<n; i++){
            ll a;cin>>a;
            if(a>0)pos.push_back(a);
            if(a<0)neg.push_back(a);
            if(a==0 && z.size()<2)z.push_back(a);
        }
        if(pos.size()>2||neg.size()>2){cout<<"NO"<<endl; continue;}
        for(ll i:pos)z.push_back(i);
        for(ll i:neg)z.push_back(i);
        bool flag=false;
        for(ll i=0; i<z.size(); i++){
            if (flag==true) break;
            for(ll j=i+1; j<z.size(); j++){
                if (flag==true) break;
                for(ll x=j+1; x<z.size(); x++){
                    if (flag==true) break;
                    //cout<<"sum: "<<z[i]+z[j]+z[x]<<endl;
                    if(find(z.begin(), z.end(), z[i]+z[j]+z[x])==z.end()){
                        flag=true;
                        break;
                    }
                }
            }
        }
        if(flag==true){cout<<"NO"<<endl; continue;;}
        cout<<"YES"<<endl;
    }

}