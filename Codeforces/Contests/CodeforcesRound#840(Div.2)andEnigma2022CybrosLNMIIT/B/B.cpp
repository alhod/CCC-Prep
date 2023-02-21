#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll arithmeticSequence(double n, double p){
    return (n/2)*(2*p+(n-1)*p);
}


void solution(){
    ll n, k;
    cin>>n>>k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    vector<ll>h(n);
    vector<ll>p(n);
    for(ll i=0; i<n; i++){
        cin>>h[i];
    }
    for(ll i=0; i<n; i++){
        cin>>p[i];
    }
    for(ll i=0; i<n; i++){
        pq.push(pair<ll, ll>(p[i], h[i]));
    }
    
    ll totalDamage=k;
    while(pq.size()>0){
        if(k<=0){
            cout<<"NO"<<endl;
            return;
        }
        pair<ll, ll>curr=pq.top();
        pq.pop();
        ll currHealth=curr.second;
        ll currPower=curr.first;
        if(curr.second-totalDamage>0){
            ll p1=0;
            ll p2=100000;
            while(p1<=p2){
                ll mid=(p1+p2)/2;
                if(totalDamage+k-arithmeticSequence(mid, currPower)>=currHealth){
                    p2=mid-1;
                } else {
                    p1=mid+1;
                }
            }
            if(k-currPower*p1-currPower>=0){
                k-=currPower*p1-currPower;
            }
        } else {
            continue;
        }
    }

    cout<<"YES"<<endl;
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