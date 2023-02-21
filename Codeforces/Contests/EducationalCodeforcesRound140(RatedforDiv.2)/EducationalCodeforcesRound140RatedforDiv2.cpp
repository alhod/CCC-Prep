#include<bits/stdc++.h>
#define ll long long
using namespace std;


// void solution(){
//     ll x, y, x2, y2, x3, y3;
//     cin>>x>>y>>x2>>y2>>x3>>y3;
//     // printf("%d %d %d %d %d %d\n", x, y, x2, y2, x3, y3);
//     if((y==y2||y2==y3||y3==y)&&(x==x2||x2==x3||x3==x)){
//         cout<<"NO"<<endl;
//     } else {
//         cout<<"YES"<<endl;

//     }
    
// }


// void solution(){

//     ll n;
//     cin>>n;
//     vector<ll>v(n-1);
//     priority_queue<ll, vector<ll>, greater<ll>>pq;

//     ll ans;
//     cin>>ans;

//     for(ll i=0; i<n-1; i++){
//         cin>>v[i];
//         pq.push(v[i]);
//     }

//     while(pq.size()>0){
//         ll curr=pq.top();
//         pq.pop();
//         if(curr<=ans){
//             continue;
//         }

//         ll diff=curr-ans;
//         if(diff%2!=0){
//             diff++;
//         }

//         ans+=diff/2;
//     }

//     cout<<ans<<endl;



// }





// ll mod=998244353;

// void solution(){

//     ll n;
//     cin>>n;
//     vector<vector<ll>>v(n, vector<ll>(n));
//     for(ll i=0; i<n; i++){
//         for(ll j=i; j<n; j++){
//             cin>>v[i][j];
//         }
//     }

//     for(ll i=0; i<n; i++){
//         if(v[i][i]==2){
//             cout<<0<<endl;
//             return;
//         }
//     }

//     for(auto i:v){
//         for(auto j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }

//     for(ll i=0; i<n; i++){
//         for(ll j=i+1; j<n; j++){
//             if(v[i][j]==1){
//                 //printf("found at %d %d\n", i, j);
//                 for(ll x=i; x<j; x++){
//                     for(ll y=i; y<j; y++){
//                         if(v[x][y]==2){
//                             cout<<0<<endl;
//                             return;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     vector<ll>s(n, 0);
//     for(ll i=0; i<n; i++){
//         for(ll j=i+1; j<n; j++){
//             if(v[i][j]==0){
//                 continue;
//             } else if(v[i][j]==1){
//                 for(ll x=i; x<=j; x++){
//                     s[x]=1;
//                 }
//             } else if(v[i][j]==2){
//                 s[j]=2;
//             }
//         }
//     }

//     ll ans=1;
//     cout<<"s"<<endl;
//     for(ll i=0; i<n; i++){
//         cout<<s[i]<<" ";
//         if(s[i]==0){
//             ans=(2*ans)%mod;
//         } else if(s[i]==1){
//             continue;
//         } else if(s[i]==2){
//             ans=(2*ans-2)%mod;
//         }
//     }
//     cout<<endl;
//     cout<<ans<<endl;

// }



void solution(){

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll num1s=0;
    ll num0s=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            num1s++;
        } else {
            num0s++;
        }
    }
    ll start=(1<<num1s);
    ll end=(1<<n)-(1<<num0s)+1;
    for(ll i=start; i<=end; i++){
        cout<<i<<" ";
    }
    cout<<endl;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    // ll t;
    // cin>>t;

    // while(t--){
    //     solution();
    // }
}