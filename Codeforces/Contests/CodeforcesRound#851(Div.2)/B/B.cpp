#include<bits/stdc++.h>
#define ll long long
using namespace std;


pair<ll, ll> sum_digits(ll n){
    ll a=n/2+1, b=n/2;
    ll sum_1=0, sum_2=0;
    while(a>0){
        sum_1+=a%10;
        a/=10;
    }
    while(b>0){
        sum_2+=b%10;
        b/=10;
    }

    // printf("n: %d, sum_1: %d, sum_2: 1%d\n", n, sum_1, sum_2);

    ll diff=abs(sum_1-sum_2)/2;
    ll tmp=0;
    ll count=0;
    while(diff>0){
        if(diff>9){
            tmp+=9*pow(10, count);
            count++;
            diff-=9;
        } else {
            tmp+=diff*pow(10, count);
            diff=0;
            count++;
        }
    }

    return pair<ll, ll>(n/2+1+tmp, n/2-tmp);
}


void solution(){
    ll n;
    cin>>n;

    if(n%2){
        pair<ll, ll>ret=sum_digits(n);
        cout<<ret.first<<" "<<ret.second<<endl;
    } else {
        cout<<n/2<<" "<<n/2<<endl;
    }
    
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