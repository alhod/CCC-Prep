#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll properFloor(ll a, ll b){
    ll ret=a/b;  // -5/2 = -2
    if(ret*b>a){  // from -2.5 we don't want round to -2, we want round down to -3
        ret--;
    }

    return ret;

}



void solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll sum=0;
    for(ll i=0; i<n; i++){sum+=v[i];}
    if(sum<=k){cout<<0<<endl;return;}

    sort(v.begin(), v.end());

    vector<ll>pre(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            pre[i]=v[i];
        } else {
            pre[i]=v[i]+pre[i-1];
        }
    }


    // cout<<"vectors: "<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;

    ll best=1e18;
    for(ll y=0; y<n; y++){
        ll tmp1=k-pre[n-y-1]+v[0];
        ll tmp2=y+1;

        // ll x=v[0]-floor((k-pre[n-y-1]+pre[0])/(y+1));
        ll x=v[0]-properFloor(tmp1, tmp2);
        // printf("x: %d, y: %d, tmp1: %d, tmp2: %d\n", x, y, tmp1, tmp2);
        best=min(best, max(0ll, x)+y);
    }

    cout<<best<<endl;
    
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



// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;


// void solution(){
//     ll n, k;
//     cin>>n>>k;
//     vector<ll>v(n+1);
//     for(ll i=1; i<n+1; i++){
//         cin>>v[i];
//     }

//     ll sum=0;
//     for(ll i=1; i<n+1; i++){
//         sum+=v[i];
//     }

//     if(sum<=k){
//         cout<<0<<endl;
//         return;
//     }

//     if(n==1){
//         cout<<v[1]-k<<endl;
//         return;
//     }

//     sort(v.begin()+1, v.end());
//     reverse(v.begin()+1, v.end());

//     ll var=min(k/n, v[n]);

//     vector<ll>pre(n+1);
//     for(ll i=1; i<n+1; i++){
//         pre[i]=v[i]+pre[i-1];
//     }

//     ll best=1e18;

//     // initial find best
//     ll copy=sum-v[n]+var;
//     ll startInd;

//     for(ll i=1; i<n+1; i++){
//         copy-=v[i];
//         copy+=var;
//         if(copy<=k){
//             startInd=i-1;
//             best=v[n]-var+i;
//             var--;
//             break;
//         }
//     }

//     // printf("startInd: %d, var: %d\n", startInd, var);
//     // cout<<"vectors: "<<endl;
//     // for(ll i=0; i<n+1; i++){
//         // cout<<v[i]<<" ";
//     // }
//     // cout<<endl;
//     // for(ll i=0; i<n+1; i++){
//         // cout<<pre[i]<<" ";
//     // }
//     // cout<<endl;

//     while(startInd>=0){
//         ll ops=v[n]-var;
//         copy=sum-v[n]+var;
//         ll bestInd=-1;
//         for(ll i=startInd; i>=0; i--){
//             if(copy-pre[i]+i*var<=k){
//                 bestInd=i;
//                 continue;
//             }
//         }

//         // printf("ops: %d, copy: %d, bestInd: %d\n", ops, copy, bestInd);

//         if(bestInd==-1){
//             startInd--;
//             var--;
//             continue;
//         }

//         best=min(best, ops+bestInd);
//         // printf("new best: %d\n", best);
//         startInd=bestInd-1;
//         var--;
//     }

//     cout<<best<<endl;



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