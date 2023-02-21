#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> PrimeFactorization(ll n){
    ll fact=2;

    vector<ll>ret;

    if(n<=1){
        return ret;
    } else if(n<=3){
        return {n};
    }

    while(true){
        if(fact>sqrt(n)){
            break;
        } else if(n%fact==0){
            while(n%fact==0){
                n/=fact;
                ret.push_back(fact);
            }
        }
        fact++;
    }

    if(n>1){
        ret.push_back(n);
    }

    return ret;
}


void solution(){
    ll n;
    cin>>n;

    vector<ll>prime_factors=PrimeFactorization(n);

    sort(prime_factors.begin(), prime_factors.end());
    
    multiset<pair<ll, ll>>prime_factors_2;
    for(ll i=0; i<prime_factors.size(); i++){
        prime_factors_2.insert(pair<ll, ll>(prime_factors[i], i));
    }


    ll ans=0;

    while(prime_factors_2.size()>0){
        ll product=1;
        map<ll, bool>seen;
        vector<pair<ll, ll>>to_remove;
        for(auto i:prime_factors_2){
            if(!seen[i.first]){
                seen[i.first]=true;
                product*=i.first;
                to_remove.push_back(i);
            }
        }

        ans+=product;
        for(auto i:to_remove){
            prime_factors_2.erase(i);
        }
    }

    cout<<ans<<endl;

}


// void solution(){
//     ll n;
//     cin>>n;

//     if(n%2==1){
//         cout<<-1<<endl;
//     } else {
//         cout<<1<<" "<<n/2<<endl;
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