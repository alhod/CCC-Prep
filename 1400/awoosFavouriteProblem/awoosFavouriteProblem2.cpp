#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    ll countA=0;
    ll countC=0;
    ll countA2=0;
    ll countC2=0;

    for(ll i=0; i<n; i++){
        if(s[i]=='a'){
            countA++;
        }
        if(t[i]=='a'){
            countA2++;
        }
        if(s[i]=='c'){
            countC++;
        }
        if(t[i]=='c'){
            countC2++;
        }
    }
    if(countA!=countA2||countC!=countC2){
        cout<<"NO"<<endl;
        return 0;
    }
    
    string s2="";
    string t2="";
    for(ll i=0; i<n; i++){
        if(s[i]=='a'||s[i]=='c'){
            s2.push_back(s[i]);
        }
        if(t[i]=='a'||t[i]=='c'){
            t2.push_back(t[i]);
        }
    }

    if(s2!=t2){
        cout<<"NO"<<endl;
        return 0;
    }

    vector<ll>as;
    vector<ll>at;
    vector<ll>cs;
    vector<ll>ct;
    for(ll i=0; i<n; i++){
        if(s[i]=='a'){
            as.push_back(i);
        }
        if(t[i]=='a'){
            at.push_back(i);
        }
    }

    for(ll i=n-1; i>=0; i--){
        if(s[i]=='c'){
            cs.push_back(i);
        }
        if(t[i]=='c'){
            ct.push_back(i);
        }
    }


    for(ll i=0; i<as.size(); i++){
        if(as[i]>at[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(ll i=0; i<cs.size(); i++){
        if(cs[i]<ct[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

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