#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    if(2*a*b>c*d){
        cout<<"-1 -1"<<endl;
        return 0;
    }

    // if(a==1&&b==1){
    //     cout<<"2 2"<<endl;
    //     return 0;
    // }

    // if(a==1){
    //     if(c>=b){
    //         cout<<b<<" "<<d<<endl;
    //         return 0;
    //     } else if(d>=2*b){
    //         cout<<c<<" "<<2*b<<endl;
    //         return 0;
    //     } else {
    //         cout<<"-1 -1"<<endl;
    //         return 0;
    //     }
    // }
    // if(b==1){
    //     if(d>=a){
    //         cout<<a<<" "<<c<<endl;
    //     } else if(c>=2*a){
    //         cout<<d<<" "<<2*a<<endl;
    //     } else {
    //         cout<<"-1 -1"<<endl;
    //         return 0;
    //     }
    // }

    vector<ll>factorsOfAB;
    for(ll i=1; i<=sqrt(a*b); i++){
        if((a*b)%i==0){
            factorsOfAB.push_back(i);
        }
    }

    for(ll fact:factorsOfAB){
        ll component=(a*b)/fact;
        if(a<c-(c%fact)&&b<d-(d%component)){
            cout<<c-(c%fact)<<" "<<d-(d%component)<<endl;
            return 0;
        }
        swap(fact, component);
        if(a<c-(c%fact)&&b<d-(d%component)){
            cout<<c-(c%fact)<<" "<<d-(d%component)<<endl;
            return 0;
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