#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    
    ll ans=0;

    if(n==7){
        cout<<1<<endl;
        return;
    } else if(n==4){

        // case 4
        if(v[1]-v[0]+v[2]-v[0]+v[0]==v[3]){
            ans++;
        } else if((v[0]+v[1]+v[2])/2==v[3]){
            ans++;
        }

        // case 3
        if((v[2]+v[3])-(v[0]+v[1])==v[0]||(v[2]+v[3])-(v[0]+v[1])==v[1]){
            ans++;
        }

        // case 2
        if(v[1]+v[2]==v[0]+v[3]){
            ans++;
        }

        // case 1
        if(v[0]+v[1]==v[3]){
            ans++;
        }

    } else if(n==5){

    }
    cout<<ans<<endl;
    

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