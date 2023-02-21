#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>primes;

void Eratosthenes(){

    vector<ll>primesVec(34050);

    for(ll i=2; i*i<34050; i++){
        if(primesVec[i]==1){
            continue;
        }

        // primes.push_back(i);
        for(ll j=i*i; j<34050; j+=i){
            primesVec[j]=1;
        }
    }

    for(ll i=2; i<34050; i++){
        if(primesVec[i]==0){
            primes.push_back(i);
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

    map<ll, bool>seen;

    for(ll i=0; i<n; i++){
        ll k=v[i];
        for(ll aPrime:primes){
            if(!(v[i]%aPrime)){
                if(seen[aPrime]){
                    cout<<"YES"<<endl;
                    return;
                }
                seen[aPrime]=true;
                while(!(k%aPrime)){
                    k/=aPrime;
                }
            }
        }
        if(k-1&&seen[k]){
            cout<<"YES"<<endl;
            return;
        }
        seen[k]=true;
    }

    cout<<"NO"<<endl;

    return;

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Eratosthenes();

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}