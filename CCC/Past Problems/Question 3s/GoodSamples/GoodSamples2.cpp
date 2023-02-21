#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m, k;
    cin>>n>>m>>k;

    if(k<n||k>(n*(n+1))/2||k>(m*(m+1))/2+(n-m)*m){
        cout<<-1<<endl;
        return;
    }

    vector<ll>ans(n);

    ll count=0;
    ll curr=1;
    ll adding=1;

    for(ll i=0; i<n; i++){
        ll to_add=(k-count)-(n-i-1);

        if(to_add==1){
            ans[i]=(i==0?1:ans[i-1]);
            count++;
        } else if(to_add<adding){
            curr+=m-to_add;
            if(curr>m){
                curr-=m;
            }
            ans[i]=curr;
            count+=to_add;
        } else {
            ans[i]=curr;
            count+=adding;
            curr++;
            if(curr>m){
                curr=1;
            }
            adding=max(adding, curr);
        }
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}