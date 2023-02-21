#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll f;
        cin>>f;
        vector<ll>x(f);
        vector<ll>y(f);
        for(ll i=0; i<f; i++){
            cin>>x[i];
        }
        for(ll i=0; i<f; i++){
            cin>>y[i];
        }
        priority_queue<ll>pos;
        priority_queue<ll>neg;
        for(ll i=0; i<f; i++){
            if(y[i]-x[i]<0){
                neg.push(abs(y[i]-x[i]));
            } else if(y[i]-x[i]>=0){
                pos.push(y[i]-x[i]);
            }
        }
        vector<ll>unUsedPos;
        ll count=0;
        while(true){
            if(pos.size()==0||neg.size()==0){
                break;
            }
            ll posCurr = pos.top();
            ll negCurr = neg.top();
            // cout<<posCurr<<endl;
            // cout<<negCurr<<endl;
            if(posCurr>=abs(negCurr)){
                count++;
                pos.pop();
                neg.pop();
            } else if(posCurr<abs(negCurr)){
                unUsedPos.push_back(posCurr);
                pos.pop();
            }
        }
        cout<<count+(unUsedPos.size()+pos.size())/2<<endl;
    }
}