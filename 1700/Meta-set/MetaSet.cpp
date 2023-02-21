#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;

    map<string, ll>num_sets;
    map<string, ll>string_to_ind;

    vector<string>v(n);
    for(ll i=0; i<n; i++){
        string tmp="";
        for(ll j=0; j<k; j++){
            char x;
            cin>>x;
            tmp.push_back(x);
        }

        v[i]=tmp;
        string_to_ind[tmp]=i;
    }

    for(ll i=0; i<n-2; i++){
        for(ll j=i+1; j<n-1; j++){
            string component="";
            for(ll x=0; x<k; x++){
                if(v[i][x]==v[j][x]){
                    component.push_back(v[i][x]);
                } else if((v[i][x]=='0'&&v[j][x]=='1')||(v[i][x]=='1'&&v[j][x]=='0')){
                    component.push_back('2');
                } else if((v[i][x]=='0'&&v[j][x]=='2')||(v[i][x]=='2'&&v[j][x]=='0')){
                    component.push_back('1');
                } else if((v[i][x]=='1'&&v[j][x]=='2')||(v[i][x]=='2'&&v[j][x]=='1')){
                    component.push_back('0');
                }
            }

            if(string_to_ind[component]!=0&&j<string_to_ind[component]){
                // cout<<"v[i]: "<<v[i]<<endl;
                // cout<<"v[j]: "<<v[j]<<endl;
                // cout<<"component: "<<component<<endl;
                num_sets[v[i]]++;
                num_sets[v[j]]++;
                num_sets[component]++;
            }
        }
    }

    ll ans=0;
    for(ll i=0; i<n; i++){
        ans+=(num_sets[v[i]]*(num_sets[v[i]]-1))/2;
    }

    cout<<ans<<endl;


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}