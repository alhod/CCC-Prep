#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll greatest=-1;
    ll greatestInd=-1;
    vector<ll>pre(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            pre[i]=v[i];
        } else {
            pre[i]=max(v[i], pre[i-1]);
        }
        if(v[i]>greatest){
            greatest=v[i];
            greatestInd=i;
        }
    }

    while(q--){
        ll ind, k;
        cin>>ind>>k;
        ind-=1;
        if(ind>greatestInd||k<=ind-1){
            cout<<0<<endl;
        } else if(ind==greatestInd){
            k-=max(ind-1, (ll)0);
            cout<<k<<endl;
        } else {
            if(ind!=0&&pre[ind-1]>v[ind]){
                cout<<0<<endl;
            } else {
                ll wins=0;
                if(ind!=0){
                    wins++;
                }
                k-=ind;
                ll firstIndGreater=upper_bound(pre.begin(), pre.end(), v[ind])-pre.begin()-1;
                wins+=min(firstIndGreater-ind, k);
                cout<<wins<<endl;
            }
        }
    }
    
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