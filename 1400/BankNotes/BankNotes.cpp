#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;


ll power(ll b, ll exp){

    ll num=1;
   
    for(ll i=0; i<exp; i++){
        num*=b;
    }

    return num;
}


int solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(1000);
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v[x]=1;
    }
    k++;
    ll ans=0;
    ll tenToWhat=0;
    ll last=-1;
    while(k!=0){
        // cout<<"tenToWhat: "<<tenToWhat<<endl;
        if(v[tenToWhat]==1){
            // cout<<"found "<<tenToWhat<<endl;
            if(k>=9){
                // cout<<"k>=9"<<endl;
                k-=9;
                // cout<<"k - 9 = "<<k<<endl;
                ans+=9*power(10, tenToWhat);
                // cout<<"new ans: "<<ans<<endl;
            } else {
                // cout<<"k<9"<<endl;
                ans+=k*power(10, tenToWhat);
                // cout<<"ans += "<<k*power(10, tenToWhat)<<endl;
                // cout<<"new ans: "<<ans<<endl;
                k=0;
            }
            last=tenToWhat;
        } else {
            // cout<<"did not find "<<tenToWhat<<endl;
            if(k>=(9*power(10, tenToWhat))/power(10, last)){
                // cout<<"k>="<<(9*power(10, tenToWhat))/power(10, last)<<endl;
                k-=(9*power(10, tenToWhat))/power(10, last);
                // cout<<"k - "<<(9*power(10, tenToWhat))/power(10, last)<<" = "<<k<<endl;
                ans+=9*power(10, tenToWhat);
                // cout<<"power(10, tenToWhat) = "<<power(10, tenToWhat)<<endl;
                // cout<<"ans += 9*power(10, tenToWhat) = "<<ans<<endl;
            } else {
                // cout<<"k<"<<(9*power(10, tenToWhat))/power(10, last)<<endl;
                // cout<<"last: "<<last<<endl;
                // cout<<"k = "<<k<<endl;
                // cout<<"power(10, last) = "<<power(10, last)<<endl;
                ll tmp = power(10, last);
                // cout<<"k * power(10, last) = "<<k*tmp<<endl;
                ans+=k*tmp;
                // cout<<"ans += k*power(10, last)="<<k*tmp<<endl;
                // cout<<"new ans: "<<ans<<endl;
                k=0;
            }
        }
        tenToWhat++;
    }

    cout<<ans<<endl;
    
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