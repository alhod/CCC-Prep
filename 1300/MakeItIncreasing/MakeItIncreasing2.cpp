#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll tot=1e18;  // must be 1*10^18 (1e8) instead of 10*10^8 (10e8) because this is 
    // supposed to act as the maximum value that is greater than all inputs.
    // However, since input can be 10^9, which is equal 10*10^8, it is potentially
    // not greater than all the inputs, thus it doesn't function properly as the
    // initial greatest value.
    for(ll i=0; i<n; i++){
        vector<ll>p(n);
        ll left=i-1;
        ll right=i+1;
        ll count=0;
        // cout<<"i: "<<i<<endl;
        while(left>=0){
            // cout<<"left: "<<left<<endl;
            ll op=abs(p[left+1]/v[left])+1;
            p[left]=-1*v[left]*op;
            left--;
            count+=op;
        }
        while(right<n){
            // cout<<"right: "<<right<<endl;
            ll op=abs(p[right-1]/v[right])+1;
            p[right]=v[right]*op;
            right++;
            count+=op;
        }
        // cout<<"count: "<<count<<endl;
        tot=min(tot, count);
    }
    cout<<tot<<endl;
}