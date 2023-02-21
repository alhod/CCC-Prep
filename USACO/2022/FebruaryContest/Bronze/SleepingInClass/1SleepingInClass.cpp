#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    bool imp=false;
    for(ll i=1; i<n; i++){
        if(v[i]!=v[i-1]){
            imp=true;
            break;
        }
    }
    if(imp==false){
        cout<<0<<endl;
        return 0;
    }

    vector<ll>pre(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            pre[0]=v[0];
        } else {
            pre[i]=pre[i-1]+v[i];
        }
    }

    // for(auto i:pre){
        // cout<<i<<" ";
    // }
    // cout<<endl;

    for(ll i=1; i<=pre[n-1]; i++){
        if(pre[n-1]%i==0){
            // cout<<"i: "<<i<<endl;
            ll mult=1;
            ll op=0;
            ll prev=0;
            for(ll j=0; j<n; j++){
                if(pre[j]==i*mult){
                    mult++;
                    op+=abs(prev-j);
                    prev=j+1;
                }
            }
            // cout<<"mult: "<<mult<<endl;
            // cout<<"pre[n-1]: "<<pre[n-1]<<endl;
            // cout<<"1: "<<pre[n-1]/(max((ll)1, mult-1)*i)<<endl;
            // cout<<"1: "<<pre[n-1]%(max((ll)1, mult-1)*i)<<endl;
            if(pre[n-1]/(max((ll)1, mult-1)*i)==1&&pre[n-1]%(max((ll)1, mult-1)*i)==0){
                cout<<op<<endl;
                return 0;
            }
        }
    }
    return 0;
}

// int solution(){
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     ll best=1e18;
//     for(ll i=0; i<n; i++){
//         ll sum=0;
//         ll currSum=0;
//         ll op=0;
//         bool imp=false;

//         for(ll j=0; j<=i; j++){
//             sum+=v[j];
//             op++;
//         }
//         op--;

//         for(ll j=i+1; j<n; j++){
//             currSum+=v[j];
//             op++;
//             if(currSum>sum){
//                 imp=true;
//                 break;
//             } else if(currSum==sum){
//                 currSum=0;
//                 op--;
//             } else {
//                 continue;
//             }
//         }

//         if(imp==true){
//             continue;
//         }
//         best=min(best, op);
//     }

//     cout<<best<<endl;
    
//     return 0;
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