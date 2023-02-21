#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        ll left=0, right=0, up=0, down=0;
        for(ll i=0; i<n; i++){
            ll x, y;
            cin>>x>>y;
            if(x<left){left=x;}
            if(x>right){right=x;}
            if(y<down){down=y;}
            if(y>up){up=y;}
        }
        ll tot=0;
        tot+=abs(right)*2;
        tot+=abs(up)*2;
        tot+=abs(down)*2;
        tot+=abs(left)*2;
        cout<<tot<<endl;
    }
}