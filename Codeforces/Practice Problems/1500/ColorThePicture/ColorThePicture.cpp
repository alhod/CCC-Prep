#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll>v(k);
    for(ll i=0; i<k; i++){
        cin>>v[i];
    }
    if(n==3&&m==3){
        for(ll i=0; i<k; i++){
            if(v[i]>=9){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }

    bool foundThree=false;
    ll squaresCovered=0;
    for(ll i=0; i<k; i++){
        if(v[i]/n>=2){
            squaresCovered+=v[i]/n*n;
            if(v[i]/n>=3){
                foundThree=true;
            }
        }
    }
    if(m%2==1){
        if(foundThree&&squaresCovered>=n*m){
            cout<<"Yes"<<endl;
            return 0;
        }
    } else {
        if(squaresCovered>=n*m){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    foundThree=false;
    squaresCovered=0;
    for(ll i=0; i<k; i++){
        if(v[i]/m>=2){
            squaresCovered+=v[i]/m*m;
            if(v[i]/m>=3){
                foundThree=true;
            }
        }
    }
    if(n%2==1){
        if(foundThree&&squaresCovered>=n*m){
            cout<<"Yes"<<endl;
            return 0;
        }
    } else {
        if(squaresCovered>=n*m){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    
    return 0;
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