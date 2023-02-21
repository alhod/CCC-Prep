#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    set<ll>aSet;
    for(ll i=0; i<n; i++){
        if(s[i]=='0'){
            aSet.insert(i);
        }
    }

    for(ll i=0; i<n; i++){
        if(i==0){
            continue;
        }
        if(s[i]=='1'){
            auto it = aSet.lower_bound(i);
            if(it==aSet.begin()){
                continue;
            }
            it--;
            if(*it>i){
                continue;
            }
            if(v[*it]>v[i]){
                s[*it]='1';
                s[i]='0';
                aSet.erase(*it);
                aSet.insert(i);
            }
        }
    }

    ll sum=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            sum+=v[i];
        }
    }
    cout<<sum<<endl;
    
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