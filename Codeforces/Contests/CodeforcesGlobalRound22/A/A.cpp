#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>type(n);
        ll numFire=0;
        ll numFrost=0;
        ll lowestType=0;
        ll lowestVal=10e8;
        for(ll i=0; i<n; i++){
            ll ty;
            cin>>ty;
            type[i]=ty;
            if(ty==0){
                numFire++;
            } else {
                numFrost++;
            }
        }
        // cout<<numFire<<"numFire"<<endl;
        // cout<<numFrost<<"numFrost"<<endl;
        vector<ll>fire;
        vector<ll>frost;
        ll lowest=10e8;
        priority_queue<ll>firepq;
        priority_queue<ll>frostpq;
        for(ll i=0; i<n; i++){
            if(type[i]==0){
                ll a;
                cin>>a;
                if(a<lowest){
                    lowest=a;
                }
                firepq.push(a);
            } else {
                ll a;
                cin>>a;
                if(a<lowest){
                    lowest=a;
                }
                frostpq.push(a);
            }
        }
        
        // sort(fire.begin(), fire.end(), greater<ll>());
        // sort(frost.begin(), frost.end(), greater<ll>());
        ll total=0;
        if(numFire>numFrost){
            for(ll i=1; i<n+1; i++){
                if(i%2==0){
                    total+=2*firepq.top();
                    firepq.pop();
                } else {
                    if(frostpq.size()==0){
                        while(firepq.size()>0){
                            total+=firepq.top();
                            firepq.pop();
                        }
                        break;
                    }
                    total+=2*frostpq.top();
                    frostpq.pop();
                }
            }
        } else if(numFrost>numFire){
            for(ll i=0; i<n; i++){
                // cout<<"total"<<total<<endl;
                if(i%2==0){
                    if(firepq.size()==0){
                        while(frostpq.size()>0){
                            total+=frostpq.top();
                            frostpq.pop();
                        }
                        break;
                    }
                    total+=2*firepq.top();
                    firepq.pop();
                } else {
                    total+=2*frostpq.top();
                    frostpq.pop();
                }
            }
        } else {
            while(firepq.size()>0){
                total+=2*firepq.top();
                firepq.pop();
            }
            while(frostpq.size()>0){
                total+=2*frostpq.top();
                frostpq.pop();
            }
            total-=lowest;
        }
        cout<<total<<endl;
    }
}