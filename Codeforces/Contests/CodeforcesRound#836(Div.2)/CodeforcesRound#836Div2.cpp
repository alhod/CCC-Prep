#include<bits/stdc++.h>
#define ll long long
using namespace std;


// int solutionA(){
//     string s;
//     cin>>s;
//     deque<char>dq;
//     for(ll i=0; i<s.length(); i++){
//         dq.push_front(s[i]);
//         dq.push_back(s[i]);
//     }
//     while(dq.size()>0){
//         cout<<dq.front();
//         dq.pop_front();
//     }
//     cout<<endl;
    
//     return 0;
// }


// int solutionB(){
//     ll n;
//     cin>>n;
//     if(n%2!=0){
//         for(ll i=0; i<n; i++){
//             cout<<1<<" ";
//         }
//         cout<<endl;
//     } else {
//         if(n>=4){
//             cout<<"1 2 3 ";
//             for(ll i=0; i<n-3; i++){
//                 cout<<2<<" ";
//             }
//             cout<<endl;
//         } else {
//             cout<<"1 3"<<endl;
//         }
//     }
//     return 0;
// }


// int solutionC(){
//     ll n, x;
//     cin>>n>>x;
//     vector<ll>v(n+1);
//     v[1]=x;
//     v[n]=1;
//     if(x==n){
//         cout<<n<<" ";
//         for(ll i=2; i<n; i++){
//             cout<<i<<" ";
//         }
//         cout<<1<<endl;
//         return 0;
//     }
    
//     ll extra=n;
//     if(extra%x!=0){
//         cout<<-1<<endl;
//         return 0;
//     }

//     ll curr=x+1;
//     ll ind=x;
//     while(true){
//         if(curr==n){
//             break;
//         }
//         if(extra%curr==0&&curr%x==0){
//             v[ind]=curr;
//             ind=curr;
//             x=curr;
//         }
//         curr++;
//     }
//     v[ind]=extra;
//     for(ll i=2; i<n; i++){
//         if(v[i]==0){
//             v[i]=i;
//         }
//     }
//     for(ll i=1; i<=n; i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;


//     return 0;
// }

int solutionD(){

    ll n;
    cin>>n;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solutionC();
    }
}