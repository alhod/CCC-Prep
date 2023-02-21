// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;


// void solution(){
//     ll n;
//     cin>>n;
//     vector<vector<ll>>v(n);
//     ll maxp=0;
//     for(ll i=0; i<n; i++){
//         ll k;
//         cin>>k;
//         vector<ll>tmp(k);
//         for(ll j=0; j<k; j++){
//             cin>>tmp[j];
//             maxp=max(maxp, tmp[j]);
//         }
//         v[i]=tmp;
//     }

//     vector<ll>seen(maxp+1);
//     for(ll i=0; i<n; i++){
//         bool notSeen=false;
//         for(ll j=0; j<v[i].size(); j++){
//             if(!seen[v[i][j]]){
//                 notSeen=true;
//             }
//             seen[v[i][j]]++;
//         }

//         if(!notSeen){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }

//     for(ll i=0; i<n; i++){

//         bool notSeen=false;
//         for(ll j=0; j<v[i].size(); j++){
//             if(seen[v[i][j]]<=1){
//                 notSeen=true;
//             }
//         }

//         if(!notSeen){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }


//     cout<<"No"<<endl;
    
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


vector<ll>seen(200001);

void clean(set<ll>nums){
    for(auto i:nums){
        seen[i]=0;
    }
}

void solution(){
    ll n;
    cin>>n;
    vector<vector<ll>>v;
    bool flag=false;
    set<ll>nums;
    for(ll i=0; i<n; i++){
        ll k;
        cin>>k;
        vector<ll>tmp(k);
        bool notSeen=false;
        for(ll j=0; j<k; j++){
            cin>>tmp[j];
            if(tmp[j]>=seen.size()){
                seen.resize(tmp[j]+1);
            }
            if(seen[tmp[j]]==0){
                notSeen=true;
            }
            seen[tmp[j]]++;
            nums.insert(tmp[j]);
        }
        if(!notSeen){
            flag=true;
        }
        v.push_back(tmp);
    }

    if(flag){
        cout<<"Yes"<<endl;
        clean(nums);
        return;
    }

    for(ll i=0; i<n; i++){

        bool notSeen=false;
        for(ll j=0; j<v[i].size(); j++){
            if(seen[v[i][j]]<=1){
                notSeen=true;
                break;
            }
        }

        if(!notSeen){
            cout<<"Yes"<<endl;
            clean(nums);
            return;
        }
    }


    cout<<"No"<<endl;
    clean(nums);
    
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