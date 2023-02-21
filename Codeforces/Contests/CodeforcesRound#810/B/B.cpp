#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

    ll t; cin>>t;
    while(t--){
        ll n, x; cin>>n>>x;
        vector<pair<ll, ll>>weightsVector;
        map<ll, ll>weightMap;
        map<ll, vector<ll>>friends;
        for(ll i=1; i<n+1; i++){
            ll tmp; cin>>tmp;
            weightsVector.push_back(pair<ll, ll>(tmp, i));
            weightMap[i]=tmp;
        }
        for(ll i=0; i<x; i++){
            ll left, right; cin>>left>>right;
            friends[left].push_back(right);
            friends[right].push_back(left);
        }

        if(x%2==0){cout<<0<<endl;continue;}
        ll bestIndexGetEven=-1;
        ll bestWeightGetEven=10e8;
        for(auto i:friends){
            if(i.second.size()%2!=0){
                if(bestWeightGetEven==-1||weightMap[i.first]<bestWeightGetEven){
                    bestWeightGetEven=weightMap[i.first];
                    bestIndexGetEven=i.first;
                }
            }
        }
        sort(weightsVector.begin(), weightsVector.end());

        ll total=0;
        ll numPairs=n;
        map<ll, bool>elem;
        ll curr;
        bool done=false;
        while(true){
            curr = weightsVector[0].second;
            elem[curr]=true;
            for(auto i:friends[curr]){
                if(elem[i]!=true){
                    numPairs--;
                }
            }
            if(numPairs%2==0){
                ll totalCost=0;
                for(auto i:elem){
                    if(elem[i.first]==true){
                        totalCost+=weightMap[i.first];
                    }
                }
                cout<<(totalCost<bestWeightGetEven?totalCost:bestWeightGetEven)<<endl;
                break;
            }
            
            weightsVector.erase(weightsVector.begin());
            sort(weightsVector.begin(), weightsVector.end());
        }
        if(done==true){continue;}

    }

}