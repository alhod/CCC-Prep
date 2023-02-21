#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        if (v[n-2]>v[n-1]){
            cout<<-1<<endl;
            continue;
        }
        ll l = v[n-2];
        ll l2 = n-2;
        ll g = v[n-1];
        ll g2 = n-1;
        ll m = 0;
        vector<vector<ll>>c;
        bool flag = false;
        for(ll i=n-1; i>=0; i--){
            if(i==n-1||i==n-2) continue;
            if(v[i]<=v[i+1]){
                l = v[i];
                l2 = i;
                continue;
            }
            v[i] = l-g;
            if(v[i]>v[i+1]){
                flag = true;
                break;
            }
            m++;
            c.push_back(vector<ll>{i+1, l2+1, g2+1});
            l = v[i]; l2 = i;
        }
        if(flag==true){cout<<"-1"<<endl; continue;}
        cout<<m<<endl;
        for(vector<ll> i:c){
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
    }

}