#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    for(ll i=1; i<=((c*d)/(a*b)); i++){
        ll toSum=i*a*b;
        for(ll j=a; j<=c; j++){
            if(j%toSum==0&&(j/toSum)>b&&(j/toSum)<=d){
                cout<<j<<" "<<j/toSum<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1"<<endl;
    
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