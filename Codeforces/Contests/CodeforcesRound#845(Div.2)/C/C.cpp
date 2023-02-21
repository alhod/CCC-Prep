// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;

// ll n, m;
// vector<ll>v;
// vector<ll>f;


// vector<ll>all_factors(ll num){
//     vector<ll>facts;
//     for(ll i=sqrt(num); i>=1; i--){
//         if(num%i==0){
//             if(i<=m){
//                 facts.push_back(i);
//             }
//             if(num/i<=m){
//                 facts.push_back(num/i);
//             }
//         }
//     }

//     return facts;
// }


// void solution(){
//     cin>>n>>m;
//     v.clear();
//     v.resize(n);
//     f.clear();
//     f.resize(m+1);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     ll count=0;

//     ll ans=1e18;

//     sort(v.begin(), v.end());

//     ll j=0;
//     for(ll i=0; i<n; i++){
//         vector<ll>facts=all_factors(v[i]);
//         for(auto factor:facts){
//             if(!f[factor]++){
//                 count++;
//             }
//         }

//         while(count==m){
//             ans=min(ans, v[i]-v[j]);
//             vector<ll>facts=all_factors(v[j]);
//             for(auto factor:facts){
//                 if(!--f[factor]){
//                     count--;
//                 }
//             }
//             j++;
//         }

        
//     }

//     cout<<(ans==1e18?-1:ans)<<endl;

    
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
 
 
ll n, m;
vector<ll>v;
vector<ll>f;
 
 
// vector<ll> all_factors(ll num){
//     vector<ll>factors;
    
//     for(ll i=sqrt(num); i>=1; i--){
//         // printf("i: %d\n", i);
//         if(num%i==0){
//             if(i<=m){
//                 factors.push_back(i);
//             }
//             if(num/i<=m){
//                 factors.push_back(num/i);
//             }
//         }
//     }
 
//     return factors;
// }
 

vector<ll>all_factors(ll num){
    vector<ll>facts;
    for(ll i=sqrt(num); i>=1; i--){
        if(num%i==0){
            if(i<=m){
                facts.push_back(i);
            }
            if(num/i<=m){
                facts.push_back(num/i);
            }
        }
    }

    return facts;
}
 
void solution(){
    cin>>n>>m;
    v.clear();
    v.resize(n);
    f.clear();
    f.resize(m+1);
    ll count=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
 
    sort(v.begin(), v.end());
 
    ll p1=0, p2=0, ans=1e18;;
 
    while(p2<n){
        vector<ll>facts=all_factors(v[p2]);
        for(auto a_factor:facts){
            f[a_factor]++;
            if(f[a_factor]==1){
                count++;
            }
        }

        while(count==m){
            ans=min(ans, v[p2]-v[p1]);
            vector<ll>facts=all_factors(v[p1]);
            for(auto a_factor:facts){
                f[a_factor]--;
                if(f[a_factor]==0){
                    count--;
                }
            }
            p1++;
        }

        p2++;
    }
 
    cout<<(ans==1e18?-1:ans)<<endl;
 
    
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