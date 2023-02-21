#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 5000005

vector<bool>primes;
// vector<ll>primes_1;
// vector<ll>primes_3;
vector<ll>cost;
vector<ll>max_mod={2, 1, 2, 3};


void sieve(){

    primes.resize(MAXN, true);
    cost.resize(MAXN);

    for(ll i=2; i<MAXN; i++){
        if(primes[i]){
            for(ll j=i; j<MAXN; j+=i){
                primes[j]=false;
            }
            max_mod[i%4]=i;
        }
        if(i%4==0){
            cost[i]=i/2-1;
        } else if(i%2==0){
            cost[i]=i/2-2;
        } else {
            cost[i]=(i-max_mod[i%4])/2;
        }
    }
}


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }


    string win;
    ll best=1e18;
    for(ll i=0; i<n; i++){
        if(cost[v[i]]<best){
            best=cost[v[i]];
            win=(v[i]%4?"Farmer John":"Farmer Nhoj");
        }
    }

    cout<<win<<endl;

    // cout<<((ans&1)?"Farmer John":"Farmer Nhoj")<<endl;

    // vector<ll>winner(n);
    // vector<ll>times(n);

    // for(ll i=0; i<n; i++){
    //     if(v[i]%4==0){
    //         winner[i]=0;
    //     } else {
    //         winner[i]=1;
    //     }
    //     times[i]=cost[v[i]];
    // }


    // ll win;
    // ll best=1e18;
    // for(ll i=0; i<n; i++){
    //     if(times[i]<best){
    //         win=winner[i];
    //         best=times[i];
    //     }
    // }

    // cout<<(win?"Farmer John":"Farmer Nhoj")<<endl;


    // cout<<"winner: "<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<winner[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"times: "<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<times[i]<<" ";
    // }
    // cout<<endl;

    // if(best_john!=best_nhoj){
    //     cout<<(best_john<best_nhoj?"Farmer John":"Farmer Nhoj")<<endl;
    // } else {
    //     cout<<(best_ind_john<best_ind_nhoj?"Farmer John":"Farmer Nhoj")<<endl;
    // }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    sieve();

    // for(ll i=0; i<MAXN; i++){
    //     if(primes[i]||i==1){
    //         if(i%4==1){
    //             primes_1.push_back(i);
    //         } else if(i%4==3){
    //             primes_3.push_back(i);
    //         }
    //     }
    // }

    // ll prev_mod_1=1;
    // ll prev_mod_3=3;

    // for(ll i=0; i<MAXN; i++){
    //     if(i%2==0){
    //         cost[i]=i/2;
    //     } else {
    //         if(i%4==1){
    //             cost[i]=(i-prev_mod_1)/2+1;
    //             prev_mod_1=i;
    //         } else {
    //             cost[i]=(i-prev_mod_3)/2+1;
    //             prev_mod_3=i;
    //         }
    //     }
    // }

    while(t--){
        solution();
    }
}