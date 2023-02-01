#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m;
ll n;
vector<pair<string, ll>>v;
vector<string>indToName;
map<pair<pair<ll, ll>, ll>, pair<pair<vector<vector<ll>>, ll>, ll>>memo;

pair<pair<vector<vector<ll>>, ll>, ll> recurse(ll M, ll ind, ll prevGreatest){
    if(memo.count(pair<pair<ll, ll>, ll>(pair<ll, ll>(M, ind), prevGreatest))>0){
        return memo[pair<pair<ll, ll>, ll>(pair<ll, ll>(M, ind), prevGreatest)];
    }

    vector<vector<ll>>store;
    vector<vector<ll>>store2;
    if(ind==v.size()){
        return pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store, 0), prevGreatest);
    }

    if(M==0){
        vector<ll>tmp={ind};
        store.push_back(tmp);
        pair<pair<vector<vector<ll>>, ll>, ll>ret=recurse(m-1, ind+1, v[ind].second);
        ret.second+=prevGreatest;
        if(m-1==0){
            for(auto i:ret.first.first){
                store.push_back(i);
            }
            return pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store, 0), ret.second);
        } else {
            if(ret.first.first.size()==0){
                return pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store, 0), ret.second);
            }
            for(auto i:ret.first.first[0]){
                store[0].push_back(i);
            }
            for(ll i=1; i<ret.first.first.size(); i++){
                store.push_back(ret.first.first[i]);
            }
            return pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store, 0), ret.second);
        }
    }

    // include
    pair<pair<vector<vector<ll>>, ll>, ll>ret1=recurse(M-1, ind+1, max(prevGreatest, v[ind].second));
    if(M-1==0||ret1.first.second==0){
        vector<ll>tmp={ind};
        store.push_back(tmp);
        for(auto i:ret1.first.first){
            store.push_back(i);
        }
    } else {
        vector<ll>tmp={ind};
        store.push_back(tmp);
        if(ret1.first.first.size()!=0){
            for(auto i:ret1.first.first[0]){
                store[0].push_back(i);
            }
            for(ll i=1; i<ret1.first.first.size(); i++){
                store.push_back(ret1.first.first[i]);
            }
        }
    }
    

    // exclude
    pair<pair<vector<vector<ll>>, ll>, ll>ret2=recurse(m-1, ind+1, v[ind].second);
    ret2.second+=prevGreatest;
    if(m-1==0||ret2.first.second==0){
        vector<ll>tmp={ind};
        store2.push_back(tmp);
        for(auto i:ret2.first.first){
            store2.push_back(i);
        }
    } else {
        vector<ll>tmp={ind};
        store2.push_back(tmp);
        if(ret2.first.first.size()!=0){
            for(auto i:ret2.first.first[0]){
                store2[0].push_back(i);
            }
            for(ll i=1; i<ret2.first.first.size(); i++){
                store2.push_back(ret2.first.first[i]);
            }
        }
    }

    if(ret1.second<=ret2.second){
        return memo[pair<pair<ll, ll>, ll>(pair<ll, ll>(M, ind), prevGreatest)]=pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store, 1), ret1.second);
    } else {
        return memo[pair<pair<ll, ll>, ll>(pair<ll, ll>(M, ind), prevGreatest)]=pair<pair<vector<vector<ll>>, ll>, ll>(pair<vector<vector<ll>>, ll>(store2, 0), ret2.second);
    }

}


int solution(){
    cin>>m;
    cin>>n;
    v.resize(n);
    for(ll i=0; i<n; i++){
        string name;
        cin>>name;
        ll time;
        cin>>time;
        v[i].first=name;
        v[i].second=time;
        indToName.push_back(name);
    }

    pair<pair<vector<vector<ll>>, ll>, ll>ans = recurse(m, 0, 0);
    cout<<"Total Time: "<<ans.second<<endl;
    for(auto i:ans.first.first){
        for(auto j:i){
            cout<<indToName[j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}