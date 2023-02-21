#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll k;
    cin>>k;
    vector<vector<ll>>req(n);

    for(ll i=0; i<k; i++){
        ll get, numToGet;
        cin>>get>>numToGet;
        for(ll j=0; j<numToGet; j++){
            ll x;
            cin>>x;
            req[get-1].push_back(x-1);
        }
    }

    ll ans=0;

    while(true){
        vector<ll>consume(n);
        bool imp=false;
        consume[n-1]++;

        for(ll i=n-1; i>=0; i--){
            if(consume[i]<=v[i]){
                v[i]-=consume[i];
                continue;
            }

            if(req[i].size()==0){
                imp=true;
                break;
            }

            consume[i]-=v[i];
            v[i]=0;
            for(auto ing:req[i]){
                consume[ing]+=consume[i];
            }
        }

        if(imp==true){
            break;
        } else {
            ans++;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}