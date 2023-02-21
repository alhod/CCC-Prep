#include<bits/stdc++.h>
#define ll long double
using namespace std;

ll findCost(ll ind, ll n, vector<ll>*v, vector<ll>*d){
    ll totalCost=0;
    for(ll i=1; i<=n; i++){
        totalCost+=abs((*v)[i]-ind)+(*d)[i];
    }
    return totalCost;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=2;
        vector<ll>v(n+1);
        vector<ll>d(n+1);
        ll greatestPos=0;
        for(ll i=1; i<n+1; i++){
            ll pos;
            cin>>pos;
            if(pos*2>greatestPos){
                greatestPos=pos*2;
            }
            v[i]=pos*2;
        }
        for(ll i=1; i<n+1; i++){
            cin>>d[i];
            d[i]*=2;
        }

        ll p1=1;
        ll p2=greatestPos;
        ll mid, midCost, leftCost, rightCost;

        while(true){
            mid=(p1+p2)/2;
            
            midCost=findCost(mid, n, &v, &d);
            leftCost=findCost(mid-1, n, &v, &d);
            rightCost=findCost(mid+1, n, &v, &d);

            if(leftCost==rightCost){
                break;
            } else if(leftCost<=midCost){
                p2=mid;
            } else if(rightCost<=midCost){
                p1=mid;
            } else if(leftCost>=midCost&&midCost<=rightCost){
                break;
            }
        }
        cout<<mid*2<<endl;
        
    }
}