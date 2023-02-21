#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    queue<ll>as;
    queue<ll>cs;
    vector<ll>allA;
    vector<ll>allC;

    ll aCount=0;
    ll cCount=0;
    ll aCount1=0;
    ll cCount1=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='a'){
            aCount++;
        }
        if(t[i]=='a'){
            aCount1++;
        }
        if(s[i]=='c'){
            cCount++;
        }
        if(t[i]=='c'){
            cCount1++;
        }
    }
    if(aCount!=aCount1||cCount!=cCount1){
        cout<<"NO"<<endl;
        return 0;
    }

    // cout<<"A"<<endl;
    for(ll i=0; i<n; i++){
        if(t[i]=='a'){
            as.push(i);
            // cout<<i<<" ";
            allA.push_back(i);
        }
        if(s[i]=='a'){
            allA.push_back(i);
        }
    }
    // cout<<endl;
    // for(auto i:allA){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    
    sort(allA.begin(), allA.end());

    // cout<<"C"<<endl;
    for(ll i=n-1; i>=0; i--){
        if(t[i]=='c'){
            cs.push(i);
            // cout<<i<<" ";
            allC.push_back(i);
        }
        if(s[i]=='c'){
            allC.push_back(i);
        }
    }
    // cout<<endl;
    // for(auto i:allC){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    sort(allC.begin(), allC.end());

    for(ll i=0; i<n; i++){
        // cout<<"i: "<<i<<endl;
        if(s[i]=='b'){
            continue;
        } else if(s[i]=='a'){
            ll nearestA=as.front();;
            // cout<<"i is a: "<<i<<endl;
            // cout<<"nearestA: "<<nearestA<<endl;
            as.pop();
            if(nearestA<i){
                cout<<"NO"<<endl;
                return 0;
            } else if(nearestA==i){
                continue;
            } else {
                auto firstC=upper_bound(allC.begin(), allC.begin(), i);
                if(firstC==allC.end()){
                    continue;
                }
                if(*firstC>=i&&*firstC<=nearestA){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    for(ll i=n-1; i>=0; i--){
        if(s[i]=='b'){
            continue;
        } else if(s[i]=='c'){
            ll nearestC=cs.front();;
            cs.pop();
            if(nearestC>i){
                cout<<"NO"<<endl;
                return 0;
            } else if(nearestC==i){
                continue;
            } else {
                auto firstA=upper_bound(allA.begin(), allA.end(), i);
                if(firstA==allA.end()){
                    continue;
                }
                if(*firstA>=nearestC&&*firstA<=i){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
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