#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll n;
    cin>>n;
    map<ll, tuple<ll, ll, ll>>m;
    ll largestW = 0;
    for (ll i=0; i<n; i++){
        ll p, w, d;
        cin>>p>>w>>d;
        if (w>largestW){
            largestW = w;
        }
        m.insert(pair<ll, tuple<ll, ll ,ll>>(i, make_tuple(p, w, d)));
    }

    vector<ll>v;

    for (auto i : m){
        tuple<ll, ll, ll>j = i.second;
        ll p, w, d;
        p = get<0>(j);
        w = get<1>(j);
        d = get<2>(j);
        
        ll leftEnd = p-d;
        ll rightEnd = p+d;
        ll scale = largestW/w;
        leftEnd = leftEnd * largestW * scale;
        rightEnd = rightEnd * largestW * scale;
        v.push_back(leftEnd);
        v.push_back(rightEnd);
    }

    ll sum = accumulate(v.begin(), v.end(), 0);

    ll index = round((sum/(n*2))/largestW)-1;

    ll total = 0;

    for (auto i : m){
        tuple<ll, ll, ll>j = i.second;
        ll p, w, d;
        p = get<0>(j);
        w = get<1>(j);
        d = get<2>(j);
        
        ll leftEnd = p-d;
        ll rightEnd = p+d;
        ll val;
        ll leftDifference = index-leftEnd;
        if (leftDifference < 0){
            leftDifference = leftDifference*-1;
        }
        ll rightDifference = index-rightEnd;
        if (rightDifference < 0){
            rightDifference = rightDifference*-1;
        }
        if (leftDifference<rightDifference){
            val = leftEnd;
        } else{
            val = rightEnd;
        }

        ll finalDifference = index - val;
        if (finalDifference < 0){
            finalDifference = finalDifference*-1;
        }

        total+=finalDifference*w;
    }

    cout<<total<<endl;

}