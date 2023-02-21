#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool isPrime(ll n){
    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int solution(){
    ll n, e;
    cin>>n>>e;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<ll>>cnt(min(e, n));
    // cout<<"aused"<<endl;
    for(ll i=0; i<min(e, n); i++){
        for(ll j=i; j<n; j+=e){
            if(v[j]==1){
                cnt[i].push_back(1);
            } else if(isPrime(v[j])){
                cnt[i].push_back(0);
            } else {
                cnt[i].push_back(-1);
            }
        }
        // cout<<"cnt"<<endl;
        // for(auto j:cnt[i]){
        //     cout<<j<<" ";
        // }
        // cout<<endl;
    }
    // cout<<"aused2"<<endl;
    for(ll i=0; i<cnt.size(); i++){
        // cout<<"aaaa"<<endl;
        vector<ll>tmp;
        for(ll j=0; j<cnt[i].size(); j++){
            // for(auto x:tmp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            // cout<<"aaaa2"<<endl;
            if(cnt[i][j]==0||cnt[i][j]==-1){
                // cout<<"bbb"<<endl;
                tmp.push_back(cnt[i][j]);
            } else if(cnt[i][j]==1){
                // cout<<"bbb2"<<endl;
                if(tmp.size()>0&&tmp[tmp.size()-1]>0){
                    // cout<<"ccc"<<endl;
                    tmp[tmp.size()-1]+=cnt[i][j];
                } else {
                    // cout<<"ccc2"<<endl;
                    tmp.push_back(cnt[i][j]);
                }
            }
        }
        // cout<<"tmp: "<<endl;
        // for(auto i:tmp){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        cnt[i]=tmp;
    }
    // cout<<"aused3"<<endl;
    ll ans=0;

    for(auto i:cnt){
        if(i.size()<=1){
            continue;
        }
        for(ll j=0; j<i.size(); j++){
            if(j==0&&i[j]==0){
                ans+=max(0ll, i[j+1]);
            } else if(j==i.size()-1&&i[j]==0){
                ans+=max(0ll, i[j-1]);
            } else if(i[j]==0){
                ans+=max(0ll, i[j-1])+max(0ll, i[j+1])+max(0ll, i[j-1])*max(0ll, i[j+1]);
            }
        }
    }

    cout<<ans<<endl;


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