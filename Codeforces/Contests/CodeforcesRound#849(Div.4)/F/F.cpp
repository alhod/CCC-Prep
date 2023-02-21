#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll replace(ll n){
    ll ret=0;
    while(n>0){
        ret+=n%10;
        n/=10;
    }
    return ret;
}


void solution(){
    ll n, q;
    cin>>n>>q;

    map<ll, ll>ind_to_val;
    multiset<pair<ll, ll>>ms;

    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        if(x>=10){
            ms.insert(pair<ll, ll>(i, x));
        }
        ind_to_val[i]=x;
    }


    while(q--){
        ll k;
        cin>>k;
        if(k==1){
            ll l, r;
            cin>>l>>r;
            l--;
            r--;
            vector<pair<ll, ll>>add_back;
            for(ll i=l; i<=r; i++){
                auto iter=ms.lower_bound(pair<ll, ll>(i, 0));

                if(iter==ms.end()){
                    break;
                }
                if((*iter).first<l||(*iter).first>r){
                    break;
                }
                pair<ll, ll>tmp=*iter;
                ms.erase(*iter);
                tmp.second=replace(tmp.second);
                ind_to_val[tmp.first]=tmp.second;
                if(tmp.second>=10){
                    add_back.push_back(tmp);
                }
            }

            for(auto i:add_back){
                ms.insert(i);
            }
        } else {
            ll ind;
            cin>>ind;
            ind--;
            cout<<ind_to_val[ind]<<endl;
        }
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