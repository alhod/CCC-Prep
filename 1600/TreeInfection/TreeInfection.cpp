#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>groups(n);
    for(ll i=0; i<n-1; i++){
        ll x;
        cin>>x;
        groups[x-1]++;
    }

    groups.push_back(1);

    sort(groups.rbegin(), groups.rend());

    for(ll i=groups.size()-1; i>=0; i--){
        if(groups[i]<=0){
            groups.pop_back();
        } else {
            break;
        }
    }

    for(ll i=0; i<groups.size(); i++){
        groups[i]-=groups.size()-i;
    }

    sort(groups.rbegin(), groups.rend());

    ll timePassed=groups.size();

    for(ll i=groups.size()-1; i>=0; i--){
        if(groups[i]<=0){
            groups.pop_back();
        } else {
            break;
        }
    }


    while(groups.size()>0){
        timePassed++;
        
        ll last=0;
        for(ll i=0; i<groups.size(); i++){
            if(groups[i]==groups[last]){
                last=i;
            } else {
                break;
            }
        }
        groups[last]--;

        for(ll i=0; i<groups.size(); i++){
            groups[i]--;
        }

        for(ll i=groups.size()-1; i>=0; i--){
            if(groups[i]<=0){
                groups.pop_back();
            } else {
                break;
            }
        }
    }

    printf("%d\n", timePassed);
    
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