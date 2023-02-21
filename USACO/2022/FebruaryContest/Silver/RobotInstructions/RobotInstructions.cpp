#include<bits/stdc++.h>
#define ll long long
using namespace std;

using P = pair<ll, ll>;
P operator+(P a, P b){
    return {a.first+b.first, a.second+b.second};
}
P operator-(P a, P b){
    return {a.first-b.first, a.second-b.second};
}

vector<pair<P, ll>>displacements(const vector<P>&ins){
    vector<pair<P, ll>>ret{{}};
    for(const P d:ins){
        ret.resize(2*ret.size());
        for(ll i=0; i<ret.size()/2; i++){
            ret[i+ret.size()/2]={ret[i].first+d, ret[i].second+1};
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}



ll solution(){
    ll n;
    cin>>n;
    vector<P>v(n);
    P goal;
    cin>>goal.first>>goal.second;
    for(auto &i:v){
        cin>>i.first>>i.second;
    }

    vector<P>firstHalfTmp;
    vector<P>secondHalfTmp;
    for(ll i=0; i<n/2; i++){
        // cout<<"adding "<<v[i].first<<" "<<v[i].second<<endl;
        firstHalfTmp.push_back(v[i]);
    }
    for(ll i=n/2; i<n; i++){
        // cout<<"adding2 "<<v[i].first<<" "<<v[i].second<<endl;
        secondHalfTmp.push_back(v[i]);
    }

    vector<pair<P, ll>>leftDisplacements=displacements(firstHalfTmp);
    vector<pair<P, ll>>rightDisplacements=displacements(secondHalfTmp);

    reverse(rightDisplacements.begin(), rightDisplacements.end());
    // cout<<"left displacements"<<endl;
    // for(auto i:leftDisplacements){
        // cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }
    // cout<<"right displacements"<<endl;
    // for(auto i:rightDisplacements){
        // cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }
    // cout<<"done"<<endl;
    vector<ll>ans(n+1);

    vector<ll>solveDisplacements;
    P prevDisplacement{1e18, 1e18};
    ll indWorks=0;
    for(const auto &[displace, k]:leftDisplacements){
        // cout<<"displace: "<<displace.first<<" "<<displace.second<<endl;
        // cout<<"k: "<<k<<endl;
        const P remainingDisplacement=goal - displace;
        if(remainingDisplacement!=prevDisplacement){
            // cout<<"unequal prev"<<endl;
            solveDisplacements=vector<ll>(n-n/2+1);
            for(; indWorks<rightDisplacements.size()&&rightDisplacements[indWorks].first>remainingDisplacement; indWorks++);
            for(; indWorks<rightDisplacements.size()&&rightDisplacements[indWorks].first==remainingDisplacement; indWorks++){
                solveDisplacements[rightDisplacements[indWorks].second]++; 
            }
            prevDisplacement=remainingDisplacement;
        }
            
        for(ll i=0; i<solveDisplacements.size(); i++){
            ans[i+k]+=solveDisplacements[i];
        }
    }

    for(ll i=1; i<n+1; i++){
        cout<<ans[i]<<endl;
    }


    return 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}