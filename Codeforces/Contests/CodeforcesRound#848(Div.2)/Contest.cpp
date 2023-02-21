#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    
}



// ll n, k;
// string a, b;

// ll check(ll bm){
//     string new_a=a;
//     for(ll i=0; i<n; i++){
//         // printf("new_a[i]: %c --> %d\n", new_a[i], (1<<(new_a[i]-97)));
//         if(bm&(1<<(new_a[i]-97))){
//             new_a[i]=b[i];
//         }
//     }

//     ll p1=0, p2=0;
//     ll tot=0;
//     for(; p2<n; p2++){
//         if(new_a[p2]==b[p2]){
//             continue;
//         } else {
//             ll tmp=p2-p1;
//             tot+=tmp*(tmp+1)/2;
//             p1=p2+1;
//         }
//     }

//     tot+=(p2-p1)*(p2-p1+1)/2;

//     return tot;
// }


// ll recurse(ll ind, vector<ll>&chars, ll bm, ll count){
//     if(count==k){
//         return check(bm);
//     }
    
//     ll best=0;
//     for(ll i=ind; i<chars.size(); i++){
//         ll new_bm=bm+(1<<(chars[i]-97));
//         best=max(best, recurse(i+1, chars, new_bm, count+1));
//     }

//     return best;
// }


// void solution(){
//     cin>>n>>k;
//     cin>>a>>b;

//     set<char>chars;
//     for(ll i=0; i<n; i++){
//         chars.insert(a[i]);
//     }

//     if(k>=chars.size()){
//         cout<<n*(n+1)/2<<endl;
//         return;
//     }

//     vector<ll>c;
//     for(auto i:chars){
//         c.push_back(i);
//     }

//     cout<<recurse(0, c, 0, 0)<<endl;

// }



// void solution(){
//     ll n, m, d;
//     cin>>n>>m>>d;

//     vector<ll>pos(n+1);

//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//         pos[v[i]]=i;
//     }

//     vector<ll>a(m);
//     for(ll i=0; i<m; i++){
//         cin>>a[i];
//     }

//     ll best=1e18;
//     for(ll i=0; i<m-1; i++){
//         if(pos[a[i]]>=pos[a[i+1]]||pos[a[i]]+d<pos[a[i+1]]){
//             best=0;
//             break;
//         }

//         best=min(best, pos[a[i+1]]-pos[a[i]]);

//         if(d<n-1){
//             best=min(best, pos[a[i]]+d-pos[a[i+1]]+1);
//         }
//     }

//     cout<<best<<endl;
// }


// void solution(){
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     ll count=0;
//     ll best=0;

//     for(ll i=0; i<n; i++){
//         count+=v[i];
//         if(i<n-1&&v[i]==-1&&v[i+1]==-1){
//             best=max(best, 2ll);
//         } else if(v[i]==-1){
//             best=max(best, 1ll);
//         }
//     }
    

//     if(best==0){
//         cout<<count-4<<endl;
//     } else if(best==1){
//         cout<<count<<endl;
//     } else {
//         cout<<count+4<<endl;
//     }
// }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}