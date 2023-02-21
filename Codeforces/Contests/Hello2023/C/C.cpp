#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    m--;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>pre(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            pre[i]=v[i];
        } else {
            pre[i]=pre[i-1]+v[i];
        }
    }


    ll ans=0;

    priority_queue<ll>pq;
    pq.push(v[m]);
    ll prem=pre[m];
    // printf("1--prem: %d\n", prem);
    for(ll i=m-1; i>=0; i--){
        while(pre[i]<prem){
            // printf("1--pre[i] (%d): %d < prem: %d\n", i, pre[i], prem);
            ll toSubtract=pq.top();
            pq.pop();
            prem-=toSubtract*2;
            ans++;
        }
        pq.push(v[i]);
    }

    priority_queue<ll, vector<ll>, greater<ll>>pq2;
    prem=pre[m];
    // printf("2--prem: %d\n", prem);
    ll allAdded=0;
    for(ll i=m+1; i<n; i++){
        pq2.push(v[i]);
        pre[i]+=allAdded;
        while(pre[i]<prem){
            // printf("2--pre[i] (%d): %d < prem: %d\n", i, pre[i], prem);
            ll toAdd=pq2.top();
            // printf("toAdd: %d\n", toAdd);
            pq2.pop();
            pre[i]+=-1*toAdd*2;
            allAdded+=-1*toAdd*2;
            ans++;
        }
    }

    cout<<ans<<endl;

    
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