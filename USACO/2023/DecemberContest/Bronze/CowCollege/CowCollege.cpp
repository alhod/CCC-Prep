#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    ll most_money_made=0;
    ll optimal_tuition=0;
    for(ll i=0; i<n; i++){
        ll tuition=v[i];
        auto iter=lower_bound(v.begin(), v.end(), tuition);
        ll money_made;
        if(iter==v.end()){
            money_made=0;
        } else {
            ll ind=iter-v.begin();
            money_made=(n-ind)*tuition;
        }
        if(money_made>most_money_made){
            most_money_made=money_made;
            optimal_tuition=v[i];
        }
    }

    printf("%lld %lld\n", most_money_made, optimal_tuition);
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}