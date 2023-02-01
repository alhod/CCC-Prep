#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool possible(ll length, ll k, vector<ll>&v){

    for(ll i=0; i<v.size(); i++){
        ll needed=1;
        ll start=v[i];
        
        for(ll j=1; j<v.size(); j++){
            ll end=v[(i+j)%v.size()];
            //ll dist=(end-start+1000000)%1000000;
            ll dist=min(abs(start-end), 1000000-abs(start-end));
            if(dist<=2*length){
                continue;
            } else {
                start=end;
                needed++;
            }
        }

        if(needed<=k){
            return true;
        }
    }
    return false;
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll k;
    cin>>k;

    sort(v.begin(), v.end());

    ll p1=0;
    ll p2=1000000;
    ll ans=0;
    while(p1<=p2){
        ll mid=(p1+p2)/2;
        if(possible(mid, k, v)){
            p2=mid-1;
            ans=mid;
        } else {
            p1=mid+1;
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