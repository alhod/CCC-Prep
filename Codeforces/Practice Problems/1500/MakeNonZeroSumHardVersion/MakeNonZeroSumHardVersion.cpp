#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll count1s=0;
    for(ll i=0; i<n; i++){
        if(v[i]!=0){
            count1s++;
        }
    }
    if(count1s%2!=0){
        cout<<-1<<endl;
        return 0;
    }

    vector<pair<ll, ll>>ans;

    bool foundNonZero=false;
    ll foundAtInd=-1;
    for(ll i=0; i<n; i++){
        if(v[i]==0&&foundNonZero==false){
            ans.push_back(pair<ll, ll>(i, i));
        } else if(v[i]!=0&&foundNonZero==false){
            // cout<<"found nonzero "<<i<<endl;
            foundNonZero=true;
            foundAtInd=i;
            // cout<<"foundAtInd "<<foundAtInd<<endl;
        } else if(v[i]==0&&foundNonZero==true){
            continue;
        } else if(v[i]!=0&&foundNonZero==true){
            // cout<<"foundAtInd = "<<foundAtInd<<endl;
            // cout<<"i: "<<i<<endl;
            if(v[foundAtInd]==v[i]){
                if((i-foundAtInd)%2!=0){
                    ans.push_back(pair<ll, ll>(foundAtInd, i));
                } else {
                    ans.push_back(pair<ll, ll>(foundAtInd, foundAtInd));
                    ans.push_back(pair<ll, ll>(foundAtInd+1, i));
                }
            } else {
                if((i-foundAtInd)%2==0){
                    ans.push_back(pair<ll, ll>(foundAtInd, i));
                } else {
                    ans.push_back(pair<ll, ll>(foundAtInd, foundAtInd));
                    ans.push_back(pair<ll, ll>(foundAtInd+1, i));
                }  
            }
            // cout<<"false"<<endl;
            foundNonZero=false;
        }
    }

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