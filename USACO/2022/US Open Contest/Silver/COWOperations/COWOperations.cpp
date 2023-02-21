#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    string s;
    cin>>s;

    vector<ll>pre_c(s.length());
    vector<ll>pre_o(s.length());
    vector<ll>pre_w(s.length());

    for(ll i=0; i<s.length(); i++){
        if(i==0){
            if(s[i]=='C'){
                pre_c[i]++;
            } else if(s[i]=='O'){
                pre_o[i]++;
            } else {
                pre_w[i]++;
            }
        } else {
            pre_c[i]=pre_c[i-1];
            pre_o[i]=pre_o[i-1];
            pre_w[i]=pre_w[i-1];
            if(s[i]=='C'){
                pre_c[i]++;
            } else if(s[i]=='O'){
                pre_o[i]++;
            } else {
                pre_w[i]++;
            }
        }
    }

    ll q;
    cin>>q;
    while(q--){
        ll l, r;
        cin>>l>>r;
        l--;
        r--;
        ll num_c=pre_c[r]-(l==0?0:pre_c[l-1]);
        ll num_o=pre_o[r]-(l==0?0:pre_o[l-1]);
        ll num_w=pre_w[r]-(l==0?0:pre_w[l-1]);
        num_c%=2;
        num_o%=2;
        num_w%=2;
        if(num_c==1&&num_o==0&&num_w==0){
            cout<<'Y';
        } else if(num_c==0&&num_o==1&&num_w==1){
            cout<<'Y';
        } else {
            cout<<'N';
        }
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}