#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }

        vector<vector<ll>>tab(n, vector<ll>(n));
        for(ll i=0; i<n; i++){
            tab[i][0]=v[i];
            for(ll j=1; j<=i; j++){
                tab[i][j]=tab[i][j-1]+v[i-j];
            }
        }

        for(auto i:tab){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        map<ll, vector<ll>>m;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<=i; j++){
                cout<<"find "<<tab[i][j]<<" start at "<<i<<" "<<j<<endl;
                bool imp = false;
                for(ll x=i-j; x<=i; x++){
                    for(ll y=0; y<=j; y++){
                        if(tab[x][y]=tab[i][j]&&x!=i&&y!=j){
                            cout<<"found "<<tab[i][j]<<" = "<<                       tab[x][y]<<" "<<" at "<<x<<" "<<y<<endl;
                            imp = true;
                            break;
                        }
                    }
                    if(imp==true){
                        break;
                    }
                }
                if(imp==true){
                    continue;
                }
                cout<<"not found "<<tab[i][j]<<" pushing back "<<i+1<<endl;
                m[tab[i][j]].push_back(i+1);
            }
        }

        ll best=1e10;

        for(auto i:m){
            ll sum=0;
            for(ll j=0; j<i.second.size(); j++){
                sum+=i.second[j];
            }
            if(sum!=n){
                continue;
            }
            ll high=0;
            for(ll j=0; j<i.second.size(); j++){
                high=max(i.second[j], high);
            }
            best=min(best, high);
        }

        cout<<(best==1e10?n:best)<<endl;
    }
}