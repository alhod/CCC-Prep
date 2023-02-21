#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>>v;


ll getDistance(ll ind, ll n){
    ll total=0;
    for(ll i=0; i<n; i++){
        ll p, w, left, right;
        p = v[i][0];
        w = v[i][1];
        left = p-v[i][2];
        right = p+v[i][2];
        // cout<<"ind "<<ind<<endl;
        // cout<<"left "<<left<<endl;
        // cout<<"right "<<right<<endl;
        // cout<<p<<" "<<w<<" "<<left<<" "<<right<<endl;

        if(left<=ind&&ind<=right){continue;}
        ll distance = min(abs(ind-left), abs(ind-right));
        total+=distance*w;
    }
    // cout<<"total: "<<total<<endl;
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;cin>>n;
    ll greatest = -1;
    ll lowest = -1;
    for(ll i=0;i<n;i++){
        ll p, w, d;
        cin>>p>>w>>d;
        vector<ll>tmp={p, w, d};
        v.push_back(tmp);
        if(v[i][0]>greatest||greatest==-1){greatest=v[i][0];}
        if(v[i][0]<lowest||lowest==-1){lowest=v[i][0];}
    }


    while(true){
        
        ll mid = (greatest+lowest)/2;
        ll cost = getDistance(mid, n);
        if (getDistance(mid-1, n)<cost){
            greatest=mid-1;
        } else if (getDistance(mid+1, n)<cost){
            lowest=mid+1;
        } else {
            cout<<cost<<endl;
            break;
        }
        
    }

    // while(true){
    //     ll mid = (greatest+lowest)/2;
    //     ll cost = getDistance(mid, n);
    //     ll costRight = getDistance(mid+1, n);
    //     best=min(costRight, min(best, cost));
    //     //cout<<greatest<<" "<<lowest<<endl;
    //     if(greatest==lowest||cost==costRight){
    //         cout<<cost<<endl;
    //         break;
    //     } else if(cost<costRight){
    //         greatest=mid;
    //     } else if (cost>costRight){
    //         lowest=mid+1;
    //     } 
    // }


    return 0;
} 