#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll ans=0;

    vector<ll>pre(n+1, 0);
    for(ll i=1; i<=n; i++){
        pre[i]=pre[i-1]+v[i-1];
    }

    // for(ll i=0; i<=n; i++){
        // cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // cout<<pre[n]<<" --"<<endl;
    

    
    if(k<=n){
        ll p1=1;
        ll p2=k;
        while(p2<=n){
            ans=max(ans, pre[p2]-pre[p1-1]);
            p1++;
            p2++;
        }
        ans+=k*(k-1)/2;
    } else {
        ll totalSum=pre[n];
        ll alpha=k-(n-2);
        ll beta=(k*(k-1))/2-(alpha*(alpha-1))/2;
        // printf("alpha: %d, beta: %d, totalSum: %d\n", alpha, beta, totalSum);
        ans=pre[n]+beta+2*(alpha-2)+1;
    }
    
    printf("%lld\n", ans);

    // ll extra;
    // if(k<n){
    //     extra=((k-1)*k)/2;
    // } else {
    //     ll init=(n*(n-1))/2;
    //     k-=n;
    //     ll full_cycles=k/(n-1);
    //     ll mushrooms_full_cycle=full_cycles*n*(n-1);
    //     ll remaining=k%(n-1);
    //     ll mushrooms_remaining_cycle=remaining*(1+remaining);
    //     printf("full_cycles: %d\nmushrooms_full_cycle: %d\nremaining: %d\nmushrooms_remainingCycle: %d\n", full_cycles, mushrooms_full_cycle, remaining, mushrooms_remaining_cycle);
    //     extra=init+mushrooms_full_cycle+mushrooms_remaining_cycle;
    // }

    // cout<<ans+extra<<endl;
    
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