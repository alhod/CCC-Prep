#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool pos(ll k, vector<ll>v){
    // cout<<"k: "<<k<<endl;
    ll ind=1;
    while(true){
        // cout<<"ind: "<<ind<<endl;
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(ind==k+1){
            break;
        }
        sort(v.begin(), v.end(), greater<ll>());
        ll turnMax=k-ind+1;
        ll i=0;
        while(turnMax<v[i]){
            i++;
            if(i==v.size()){
                return false;
            }
        }
        ll toAdd=v[i];
        v.erase(v.begin()+i);
        if(v.size()==0){
            return true;
        }
        sort(v.begin(), v.end());
        v[0]+=toAdd;
        ind++;
    }
    return true;
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    if(n==1&&v[0]==1){
        cout<<1<<endl;
        return 0;
    } else if(n==1&&v[0]!=1){
        cout<<0<<endl;
        return 0;
    }
    ll left=0;
    ll right=n-1;
    while(left<=right){
        ll mid=(left+right)/2;
        if(pos(mid, v)){
            // cout<<"possible"<<endl;
            left=mid+1;
        } else {
            // cout<<"impossible"<<endl;
            right=mid-1;
        }
    }
    cout<<right<<endl;

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