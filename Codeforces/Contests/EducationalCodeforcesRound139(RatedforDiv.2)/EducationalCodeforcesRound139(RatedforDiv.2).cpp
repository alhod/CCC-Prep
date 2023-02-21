#include<bits/stdc++.h>
#define ll long long
using namespace std;


// int solution(){
//     ll n;
//     cin>>n;
//     ll count=0;
//     ll ans=0;
//     while(true){
//         if(n>=9*pow(10, count)){
//             ans+=9;
//             count++;
//         } else {
//             ans+=n/pow(10, count);
//             break;
//         }
//     }
//     cout<<ans<<endl;
    
//     return 0;
// }


// void solution(){

//     ll n;
//     cin>>n;
//     string s;
//     cin>>s;

//     map<string, pair<ll, ll>>seen;
//     for(ll i=0; i<n-1; i++){
//         string aSubstr=s.substr(i, 2);
//         if(seen[aSubstr].first==true&&i-seen[aSubstr].second>1){
//             cout<<"YES"<<endl;
//             return;
//         } else {
//             if(!seen[aSubstr]){
//                 seen[aSubstr].first=true;
//                 seen[aSubstr].second=i;
//             }
            
//         }
//     }

//     cout<<"NO"<<endl;
//     return;

// }





// ll totalB=0;

// bool dfs(ll x, ll y, string &a, string &b, vector<vector<ll>>seen, ll numB){
    
//     seen[x][y]=1;
    
//     if(x==0){
//         if(a[y]=='B'){
//             numB++;
//         }
//     } else {
//         if(b[y]=='B'){
//             numB++;
//         }
//     }

//     // cout<<"curr "<<x<<" "<<y<<endl;
//     // cout<<"seen"<<endl;
//     // for(auto i:seen[0]){
//     //     cout<<i<<" ";
//     // }
//     // cout<<endl;
//     // for(auto i:seen[1]){
//     //     cout<<i<<" ";
//     // }
//     // cout<<endl;
//     // cout<<"numB: "<<numB<<endl;
//     // cout<<"totalB: "<<totalB<<endl;

//     if(numB==totalB){
//         return true;
//     }

//     if(x==0){
//         if(y-1>=0&&seen[0][y-1]!=1&&a[y-1]=='B'){
//             if(dfs(0, y-1, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         if(y+1<seen[0].size()&&seen[0][y+1]!=1&&a[y+1]=='B'){
//             if(dfs(0, y+1, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         if(seen[1][y]!=1&&b[y]=='B'){
//             if(dfs(1, y, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         return false;
//     } else {
//         if(y-1>=0&&seen[1][y-1]!=1&&b[y-1]=='B'){
//             if(dfs(1, y-1, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         if(y+1<seen[1].size()&&seen[1][y+1]!=1&&b[y+1]=='B'){
//             if(dfs(1, y+1, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         if(seen[0][y]!=1&&a[y]=='B'){
//             if(dfs(0, y, a, b, seen, numB)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     return false;
// }


// void solution(){
//     ll n;
//     cin>>n;
//     string a, b;
//     cin>>a>>b;
//     totalB=0;
//     for(ll i=0; i<n; i++){
//         if(a[i]=='B'){
//             totalB++;
//         }
//         if(b[i]=='B'){
//             totalB++;
//         }
//     }
//     vector<vector<ll>>seen(2, vector<ll>(n));
//     vector<vector<ll>>seen2(2, vector<ll>(n));
//     vector<vector<ll>>seen3(2, vector<ll>(n));
//     vector<vector<ll>>seen4(2, vector<ll>(n));
//     if(a[0]=='B'&&dfs(0, 0, a, b, seen, 0)){
//         cout<<"YES"<<endl;
//     } else if(b[0]=='B'&&dfs(1, 0, a, b, seen2, 0)){
//         cout<<"YES"<<endl;
//     } else if(a[n-1]=='B'&&dfs(0, n-1, a, b, seen3, 0)){
//         cout<<"YES"<<endl;
//     } else if(b[n-1]=='B'&&dfs(1, n-1, a, b, seen4, 0)){
//         cout<<"YES"<<endl;
//     } else {
//         cout<<"NO"<<endl;
//     }
//     return;
// }




// void solution(){
//     ll n;
//     cin>>n;
//     vector<string>v(2);
//     cin>>v[0]>>v[1];
//     ll dir=2;
//     ll totalB=0;
//     for(ll i=0; i<n; i++){
//         if(v[0][i]=='B'){
//             totalB++;
//         }
//         if(v[1][i]=='B'){
//             totalB++;
//         }
//     }
//     ll numB=0;
//     for(ll i=0; i<n; i++){
//         if(dir==2){
//             if(v[0][i]=='W'&&v[1][i]=='W'&&numB<totalB){
//                 cout<<"NO"<<endl;
//                 return;
//             } else if(v[0][i]=='B'&&v[1][i]=='B'){
//                 numB+=2;
//                 continue;
//             } else if(v[0][i]=='W'&&v[1][i]=='B'){
//                 dir=1;
//                 numB++;
//             } else if(v[0][i]=='B'&&v[1][i]=='W'){
//                 dir=0;
//                 numB++;
//             }
//         } else if(dir==1){
//             if(v[0][i]=='W'&&v[1][i]=='W'&&numB<totalB){
//                 cout<<"NO"<<endl;
//                 return;
//             } else if(v[0][i]=='B'&&v[1][i]=='B'){
//                 dir=0;
//                 numB+=2;
//             } else if(v[0][i]=='W'&&v[1][i]=='B'){
//                 numB++;
//                 continue;
//             } else if(v[0][i]=='B'&&v[1][i]=='W'){
//                 cout<<"NO"<<endl;
//                 return;
//             }
//         } else {
//             if(v[0][i]=='W'&&v[1][i]=='W'&&numB<totalB){
//                 cout<<"NO"<<endl;
//                 return;
//             } else if(v[0][i]=='B'&&v[1][i]=='B'){
//                 dir=1;
//                 numB+=2;
//             } else if(v[0][i]=='W'&&v[1][i]=='B'){
//                 cout<<"NO"<<endl;
//                 return;
//             } else if(v[0][i]=='B'&&v[1][i]=='W'){
//                 numB++;
//                 continue;
//             }
//         }
//     }
//     if(numB==totalB){
//         cout<<"YES"<<endl;
//     } else {
//         cout<<"NO"<<endl;
//     }
// }

int arr[10000001];

void sieve()
{
    arr[1]=1;
    for (int i=2; i<10000001; i++){
        arr[i]=i;
    }
    for (int i=4; i<10000001; i+=2){
        arr[i]=2;
    }
 
    for (int i=3; i*i<10000001; i++){
        if (arr[i]==i){
            for (int j=i*i; j<10000001; j+=i){
                if (arr[j]==j){
                    arr[j]=i;
                }
            }
        }
    }
}


set<ll> primeFactor(ll x) {
    set<ll> ret;
    while (x != 1) {
        ret.insert(arr[x]);
        x = x / arr[x];
    }
    return ret;
}


void solution(){
    ll x, y;
    cin>>x>>y;
    if(gcd(x, y)!=1){
        cout<<0<<endl;
        return;
    } else if(abs(x-y)==1){
        cout<<-1<<endl;
        return;
    } else {
        ll diff=abs(x-y);
        set<ll>primes=primeFactor(diff);
        ll best=1e18;
        for(auto aPrime:primes){
            ll k=aPrime-(x%aPrime);
            best=min(best, k);
        }
        cout<<best<<endl;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}