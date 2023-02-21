#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<vector<ll>, vector<ll>> trim(ll n, vector<ll>&a, vector<ll>&b, map<ll, ll>&a2, map<ll, ll>&b2){
    vector<ll>newA;
    vector<ll>newB;
    for(ll i=0; i<a.size(); i++){
        if(b2[a[i]]>0){
            a2[a[i]]--;
            b2[a[i]]--;
        } else {
            if(a2[a[i]]>0){
                newA.push_back(a[i]);
            }            
        }
    }
    for(ll i=0; i<b.size(); i++){
        if(b2[b[i]]>0){
            b2[b[i]]--;
            newB.push_back(b[i]);
        }
    }

    b2.clear();

    for(ll i=0; i<newB.size(); i++){
        b2[newB[i]]++;
    }

    return pair<vector<ll>, vector<ll>>(newA, newB);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        map<ll, ll>a2;
        vector<ll>b(n);
        map<ll, ll>b2;
        for(ll i=0; i<n; i++){
            ll num;
            cin>>num;
            a[i]=num;
            a2[num]++;
        }
        for(ll i=0; i<n; i++){
            ll num;
            cin>>num;
            b[i]=num;
            b2[num]++;
        }
        
        vector<ll> newA, newB;
        pair<vector<ll>, vector<ll>> ret = trim(n, a, b, a2, b2);
        newA=ret.first;
        newB=ret.second;

        // cout<<"newA and newB"<<endl;
        // for(auto i:newA){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:newB){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<"a2"<<endl;
        // for(auto i:a2){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<"b2"<<endl;
        // for(auto i:b2){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        ll op=0;
        for(ll i=0; i<newA.size(); i++){
            if(newA[i]>10){
                a2[newA[i]]--;
                // cout<<"baba"<<endl;
                string tmp = to_string(newA[i]);
                newA[i]=tmp.length();
                a2[newA[i]]++;
                op++;
            }
        }
        for(ll i=0; i<newB.size(); i++){
            if(newB[i]>10){
                b2[newB[i]]--;
                string tmp = to_string(newB[i]);
                newB[i]=tmp.length();
                b2[newB[i]]++;
                op++;
            }
        }

        ret = trim(n, newA, newB, a2, b2);
        newA=ret.first;
        newB=ret.second;

        // cout<<"newA and newB 2"<<endl;
        // for(auto i:newA){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:newB){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        for(ll i=0; i<newA.size(); i++){
            if(newA[i]==10){
                a2[newA[i]]--;
                newA[i]=2;
                a2[newA[i]]++;
                op++;
            }
        }
        for(ll i=0; i<newB.size(); i++){
            if(newB[i]==10){
                b2[newB[i]]--;
                newB[i]=2;
                b2[newB[i]]++;
                op++;
            }
        }

        ret = trim(n, newA, newB, a2, b2);
        newA=ret.first;
        newB=ret.second;

        // cout<<"newA and newB 3"<<endl;
        // for(auto i:newA){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:newB){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        for(ll i=0; i<newA.size(); i++){
            if(newA[i]>1){
                a2[newA[i]]--;
                newA[i]=1;
                a2[newA[i]]++;
                op++;
            }
        }
        for(ll i=0; i<newB.size(); i++){
            if(newB[i]>1){
                b2[newA[i]]--;
                newB[i]=1;
                b2[newA[i]]++;
                op++;
            }
        }

        cout<<op<<endl;
    }
}