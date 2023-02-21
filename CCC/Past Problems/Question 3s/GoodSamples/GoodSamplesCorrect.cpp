#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, ll>ma;
map<ll, ll>mb;

int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll maximum=m*n-((m-1)*(m)/2);
    ll minimum=n;
    if(k<minimum||k>maximum){
        cout<<-1<<endl;
        return 0;
    }
    ll samples = k-n;
    vector<ll>v(n);
    v[0]=1;
    ll ind=1;  // index in vector
    ll toAdd;  // value added to vector
    ll cost;  // sample cost
    ma[1]=0;
    mb[1]=true;
    bool repeating = false;
    while(true){
        if(ind==n){
            break;
        }

        if(samples==0){
            v[ind]=v[ind-1];
            ind++;
            continue;
        }


        toAdd=v[ind-1]+1;
        if(toAdd>m){
            toAdd=1;
        }
        
        if(mb[toAdd]==false){
            cost=ind;
            if(samples-cost<0){
                toAdd=1;
            } else {
                v[ind]=toAdd;
                ma[toAdd]=ind;
                mb[toAdd]=true;
                samples-=cost;
                ind++;
                continue;
            }
        }
        if(mb[toAdd]==true){
            cost=ind-ma[toAdd]-1;
            while(samples-cost<0){
                toAdd++;
                if(toAdd>m){
                    toAdd=1;
                }
                cost=ind-ma[toAdd]-1;
            }
            v[ind]=toAdd;
            ma[toAdd]=ind;
            samples-=cost;
            ind++;
            continue;
        }
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}