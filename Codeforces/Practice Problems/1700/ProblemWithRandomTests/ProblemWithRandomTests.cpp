#include<bits/stdc++.h>
#define ll long long
using namespace std;


string combine(string &x, string &y){
    string ret=x;
    for(ll i=0; i<y.length(); i++){
        if(y[i]=='1'){
            ret[i+x.length()-y.length()]='1';
        }
    }
    return ret;
}

bool compare(ll n, string &s, string &a, string &b){
    string comb_first=combine(s, a);
    string comb_second=combine(s, b);

    for(ll i=0; i<n; i++){
        if(comb_first[i]>comb_second[i]){
            return false;
        } else if(comb_first[i]<comb_second[i]){
            return true;
        }
    }

    return false;
}


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll ind=-1;
    for(ll i=1; i<n; i++){
        if(s[i]=='0'&&s[i-1]=='1'){
            ind=i;
            break;
        }
    }

    ll size=n-ind;
    string best="";

    // printf("size: %d\n", size);

    for(ll i=0; i<ind; i++){
        if(s[i]=='1'){
            string sub=s.substr(i, size);
            // cout<<"sub: "<<sub<<endl;
            // printf("i: %d, sub: %s, compare: %d\n", i, sub, compare(n, s, best, sub));
            if(compare(n, s, best, sub)){
                best=sub;
            }
        }
    }

    string ret=combine(s, best);

    for(ll i=0; i<n; i++){
        if(ret[i]=='1'||i==n-1){
            cout<<ret.substr(i, n-i)<<endl;
            return;
        }
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}