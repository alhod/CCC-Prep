#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll sum=0;
    ll num_neg=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
        num_neg+=v[i]<0;
    }

    for(ll i=0; i<n; i++){
        if(v[i]==0){
            ll tmp=0;
            for(ll j=0; j<n; j++){
                tmp+=abs(v[j]);
            }
            cout<<tmp<<endl;
            return;
        }
    }

    if(num_neg%2==0){
        ll tmp=0;
        for(ll i=0; i<n; i++){
            tmp+=abs(v[i]);
        }
        cout<<tmp<<endl;
        return;
    } else {
        ll min_element=1e18;
        for(ll i=0; i<n; i++){
            min_element=min(min_element, abs(v[i]));
        }

        ll tmp=0;
        for(ll i=0; i<n; i++){
            tmp+=abs(v[i]);
        }

        tmp-=min_element*2;
        cout<<tmp<<endl;
    }


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}