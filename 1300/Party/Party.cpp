#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<ll>v(n);
        map<ll, vector<ll>>friends;
        for(ll i=0; i<n; i++){
            ll tmp;
            cin>>tmp;
            v[i]=tmp;
        }
        for(ll i=0; i<m; i++){
            ll left, right;
            cin>>left>>right;
            friends[left-1].push_back(right-1);
            friends[right-1].push_back(left-1);
        }
        if(m%2==0){
            cout<<0<<endl;
            continue;
        }
        bool evenExists = false;
        bool oddExists = false;
        for(auto i:friends){
            if(i.second.size()%2==0){
                evenExists=true;
            }
            if(i.second.size()%2!=0){
                oddExists=true;
            }
        }
        ll costEven=10e8;
        ll costOdd=10e8;
        if(evenExists&&oddExists){
            // check even
            for(auto i:friends){
                // cout<<"i: "<<i.first<<endl;
                if(i.second.size()%2==0){
                    for(ll j : i.second){
                        // cout<<"j: "<<j<<endl;
                        if(friends[j].size()%2==0){
                            if(v[i.first]+v[j]<costEven){
                                costEven=v[i.first]+v[j];
                            }
                        }
                    }
                }
            }

            // check odd
            for(ll i=0; i<n; i++){
                if(v[i]<costOdd&&friends[i].size()%2!=0){
                    costOdd=v[i];
                }
            }
        } else if(evenExists){
            // check even
            for(auto i:friends){
                if(i.second.size()%2==0){
                    for(ll j : i.second){
                        if(friends[j].size()%2==0){
                            if(v[i.first]+v[j]<costEven){
                                costEven=v[i.first]+v[j];
                            }
                        }
                    }
                }
            }
        } else {
            // check odd
            for(ll i=0; i<n; i++){
                if(v[i]<costOdd&&friends[i].size()%2!=0){
                    costOdd=v[i];
                }
            }
        }
        // cout<<"costOdd: "<<costOdd<<endl;
        // cout<<"costEven: "<<costEven<<endl;
        cout<<min(costOdd, costEven)<<endl;
    }
}