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
    ll num2s=0;
    for(ll i=0; i<n; i++){
        while(v[i]%2==0){
            num2s++;
            v[i]=v[i]/2;
            if(v[i]==0){
                break;
            }
        }
    }
    if(num2s>=n){
        cout<<0<<endl;
        return 0;
    }
    priority_queue<ll, vector<ll>>pq;
    for(ll i=n; i>=1; i--){
        if(i%2==0){
            // cout<<"i: "<<i<<endl;
            ll counter=0;
            ll copyi=i;
            while(copyi%2==0){
                copyi=copyi/2;
                counter++;
                if(copyi==0){
                    break;
                }
            }
            pq.push(counter);
        }
    }
    ll need=n-num2s;
    ll op=0;
    // cout<<"need: "<<need<<endl;
    while(pq.size()>0){
        need-=pq.top();
        // cout<<pq.top()<<endl;
        pq.pop();
        op++;
        if(need<=0){
            cout<<op<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
    
    return 0;
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