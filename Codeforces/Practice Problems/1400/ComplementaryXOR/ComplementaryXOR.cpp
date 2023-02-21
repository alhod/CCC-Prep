#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    bool allOpp=true, allSame=true;
    for(ll i=0; i<n; i++){
        if(a[i]!=b[i]){
            allSame=false;
        } else {
            allOpp=false;
        }
    }
    if(!allOpp&&!allSame){
        cout<<"NO"<<endl;
        return 0;
    }

    vector<pair<ll, ll>>ans;

    bool type=false;
    for(ll i=0; i<n-2; i++){
        if(a[i]=='1'&&type==false){
            type=true;
            ans.push_back(pair<ll, ll>(i, n-1));
        } else if(a[i]=='0'&&type==true){
            type=false;
            ans.push_back(pair<ll, ll>(i, n-1));
        }
    }

    if(type==true){
        if(a[n-2]=='0'){
            a[n-2]='1';
        } else {
            a[n-2]='0';
        }
        if(a[n-1]=='0'){
            a[n-1]='1';
        } else {
            a[n-1]='0';
        }
    }

    if(a[n-2]=='0'){
        if(a[n-1]=='0'){
            if(b[n-2]=='0'&&b[n-1]=='0'){
                
            } else if (b[n-2]=='1'&&b[n-1]=='1'){
                ans.emplace_back(n-2, n-1);
                ans.emplace_back(n-2, n-2);
                ans.emplace_back(n-1, n-1);
            }
        } else if(a[n-1]=='1'){
            if(b[n-2]=='1'&&b[n-1]=='0'){
                ans.emplace_back(n-1, n-1);
            } else if (b[n-2]=='0'&&b[n-1]=='1'){
                ans.emplace_back(n-2, n-1);
                ans.emplace_back(n-2, n-2);
            }
        }
    } else if(a[n-2]=='1'){
        if(a[n-1]=='0'){
            if(b[n-2]=='0'&&b[n-1]=='1'){
                ans.emplace_back(n-2, n-2);
            } else if (b[n-2]=='1'&&b[n-1]=='0'){
                ans.emplace_back(n-2, n-1);
                ans.emplace_back(n-1, n-1);
            }
        } else if(a[n-1]=='1'){
            if(b[n-2]=='0'&&b[n-1]=='0'){
                ans.emplace_back(n-2, n-1);
            } else if(b[n-2]=='1'&&b[n-1]=='1'){
                ans.emplace_back(n-1, n-1);
                ans.emplace_back(n-2, n-2);
            }
        }
    }

    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first+1<<" "<<i.second+1<<endl;
    }
    
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