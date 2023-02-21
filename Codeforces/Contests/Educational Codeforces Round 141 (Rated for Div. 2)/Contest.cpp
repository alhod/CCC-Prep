// // #include<bits/stdc++.h>
// // #define ll long long
// // using namespace std;


// // void solution(){
// //     ll n;
// //     cin>>n;
// //     vector<ll>v(n);
// //     for(ll i=0; i<n; i++){
// //         cin>>v[i];
// //     }

// //     sort(v.begin(), v.end(), greater<ll>());
// //     if(v[0]==v[1]){
// //         swap(v[1], v[v.size()-1]);
// //     }
// //     if(v[0]==v[1]){
// //         printf("NO\n");
// //     } else {
// //         printf("YES\n");
// //         for(ll i=0; i<n; i++){
// //             printf("%d ", v[i]);
// //         }
// //         printf("\n");
// //     }
    
// // }



// // int main(){
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);

// //     ll t;
// //     cin>>t;

// //     while(t--){
// //         solution();
// //     }
// // }


// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;


// void solution(){
//     ll n;
//     cin>>n;
//     vector<vector<ll>>v(n, vector<ll>(n));
//     ll val=0;
//     for(ll i=0; i<n; i++){
//         if(i%2==0){
//             for(ll j=0; j<n; j++){
//                 if(j%2==0){
//                     v[i][j]=n*n-val;
//                     val++;
//                 } else {
//                     v[i][j]=val;
//                 }
//             }
//         } else {
//             for(ll j=n-1; j>=0; j--){
//                 if(j%2==0){
//                     v[i][j]=val;
//                 } else {
//                     v[i][j]=n*n-val;
//                     val++;
//                 }
//             }
//         }
//     }

//     for(ll i=0; i<n; i++){
//         for(ll j=0; j<n; j++){
//             cout<<v[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
// }



// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     ll t;
//     cin>>t;

//     while(t--){
//         solution();
//     }
// }


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll knapSack(ll W, vector<ll>wt, vector<ll>val, int n) 
{ 
    vector<vector<ll>>v(n+1, vector<ll>(W+1));
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<W+1; j++){
            if(wt[i-1]>j){
                v[i][j]=v[i-1][j];
            } else {
                v[i][j]=max(v[i-1][j], val[i-1]+v[i-1][j-wt[i-1]]);
            }
        }
    }
    return v[n][W];
}


void solution(){
    ll n, m;
    cin>>n>>m;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>values(n, 1);

    ll best=knapSack(m, v, values, n);
    sort(v.begin(), v.end());
    ll tmp=best;
    for(ll i=n-1; i>=0; i--){
        if(tmp>0){
            tmp--;
        } else {
            v[i]++;
        }
    }

    ll x=0;
    for(; x<best; x++)
    v.push_back(v[x]+1);

    vector<ll>pre(1005);

    for(ll i=0; i<n+1; i++){
        pre[v[i]]++;
    }

    for(ll i=1003; i>=0; i--){
        pre[i]+=pre[i+1];
    }

    cout<<pre[v[x]+1]+1<<endl;


    
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