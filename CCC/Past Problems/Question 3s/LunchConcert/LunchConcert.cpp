#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, tuple<ll, ll, ll, ll>>m;


ll getDistance(ll ind, ll n){
    ll total=0;
    for(ll i=0; i<n; i++){
        ll p, w, left, right;
        p = get<0>(m[i]);
        w = get<1>(m[i]);
        left = get<2>(m[i]);
        right = get<3>(m[i]);
        // cout<<"ind "<<ind<<endl;
        // cout<<"left "<<left<<endl;
        // cout<<"right "<<right<<endl;
        // cout<<p<<" "<<w<<" "<<left<<" "<<right<<endl;

        if(left<=ind&&ind<=right){continue;}
        ll distance=abs(ind-left)<abs(ind-right)?abs(ind-left):abs(ind-right);
        total+=distance*w;
    }
    // cout<<"total: "<<total<<endl;
    return total;
}

int main(){
    ll n;cin>>n;
    ll greatest = -1;
    ll lowest = -1;
    for(ll i=0;i<n;i++){
        ll p, w, d;cin>>p>>w>>d;
        if(p+d>greatest||greatest==-1){greatest=p+d;}
        // if((p-d<0?0:p-d)<lowest||lowest==-1){lowest=(p-d<0?0:p-d);}
        if(p-d<lowest||lowest==-1){lowest=p-d;}
        m.insert(pair<ll, tuple<ll, ll, ll, ll>>(i, make_tuple(p, w, p-d, p+d)));
    }
    

    while(true){
        ll curr = (greatest+lowest)/2;
        ll cost = getDistance(curr, n);
        ll costLeft = getDistance(curr-1, n);
        ll costRight = getDistance(curr+1, n);
        if (cost<costLeft&&cost<costRight){
            cout<<cost<<endl;
            break;
        } else if (cost==costLeft&&cost==costRight){
            cout<<cost<<endl;
            break;
        } else if(cost<costRight){
            greatest=curr;
        } else if (cost<costLeft){
            lowest=curr;
        } 
    }


    return 0;
}