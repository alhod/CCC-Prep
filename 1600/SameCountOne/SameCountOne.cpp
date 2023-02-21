#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(m));
    vector<ll>sum(n);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>v[i][j];
            sum[i]+=v[i][j];
        }
    }

    ll totalSumOnes=0;
    for(ll i=0; i<n; i++){
        totalSumOnes+=sum[i];
    }
    if(totalSumOnes%n!=0){
        cout<<-1<<endl;
        return;
    }

    ll need=totalSumOnes/n;
    vector<tuple<ll, ll, ll>>ans;
    for(ll j=0; j<m; j++){
        vector<ll>greater;
        vector<ll>lesser;
        for(ll i=0; i<n; i++){
            if(sum[i]>need&&v[i][j]==1){
                greater.push_back(i);
            } else if(sum[i]<need&&v[i][j]==0){
                lesser.push_back(i);
            }
        }
        for(ll i=0; i<min(greater.size(), lesser.size()); i++){
            sum[greater[i]]--;
            sum[lesser[i]]++;
            ans.emplace_back(lesser[i], greater[i], j);
        }
        
    }

    cout<<ans.size()<<endl;
    for(auto [x, y, z]:ans){
        cout<<x+1<<" "<<y+1<<" "<<z+1<<endl;
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