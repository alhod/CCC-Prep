#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll calculateTravelTime(ll ind, ll n, map<ll, tuple<ll, ll, ll>>m){

    ll total = 0;

    // cout<<"ind: "<<ind<<endl;

    for (ll i=0; i<n; i++){
        ll p = get<0>(m[i]);
        ll w = get<1>(m[i]);
        ll d = get<2>(m[i]);

        ll leftSide = p-d;
        ll rightSide = p+d;

        if (leftSide <= ind and ind <= rightSide){
            continue;
        }

        ll leftDistance = 0;
        ll rightDistance = 0;
        ll startingInd = 0;

        leftDistance = ind-leftSide;
        if (leftDistance<0){
            leftDistance *= -1;
        }
        rightDistance = ind-rightSide;
        if (rightDistance<0){
            rightDistance *= -1;
        }
        if (leftDistance < rightDistance){
            startingInd = leftSide;
        } else {
            startingInd = rightSide;
        }

        startingInd = startingInd - ind;
        if (startingInd < 0){
            startingInd*=-1;
        }
        // cout<<p<<" "<<w<<" "<<d<<endl;
        // cout<<"left distance: "<<leftDistance<<endl;
        // cout<<"right distance: "<<rightDistance<<endl;
        // cout<<"startingInd: "<<startingInd<<endl;
        // cout<<"--------------------"<<endl;
        total+=startingInd*w;
    }

    // cout<<"calculated total:"<<total<<endl;
    return total;

}

int main() {

    ll n;
    cin>>n;
    map<ll, tuple<ll, ll, ll>>m;
    ll greatestInd = 0;
    for (ll i=0; i<n; i++){
        ll p, w, d;
        cin>>p>>w>>d;
        if (p>greatestInd){
            greatestInd = p;
        }
        m.insert(pair<ll, tuple<ll, ll, ll>>(i, make_tuple(p, w, d)));
    }

    ll numerator = 0;
    ll divisor = 0;

    for (auto aFriend : m){
        ll p, w, d;
        p = get<0>(aFriend.second);
        w = get<1>(aFriend.second);
        d = get<2>(aFriend.second);

        numerator+=w*p;
        divisor+=w;
    }

    ll bestInitialInd = numerator/divisor;

    ll currBestTotal = calculateTravelTime(bestInitialInd, n, m);

    ll leftTotal, rightTotal;

    if (bestInitialInd-1 > 0){
        leftTotal = calculateTravelTime(bestInitialInd-1, n, m);
    } else {
        leftTotal = -1;
    }

    if (bestInitialInd+1 < greatestInd){
        rightTotal = calculateTravelTime(bestInitialInd+1, n, m);
    } else {
        rightTotal = -1;
    }

    ll curr1 = bestInitialInd-1;
    ll curr2 = bestInitialInd+1;

    // cout<<"leftTotal: "<<leftTotal<<endl;
    // cout<<"rightTotal: "<<rightTotal<<endl;

    if (leftTotal < currBestTotal and leftTotal != -1){
        while (leftTotal < currBestTotal and curr1>0){
            curr1--;
            currBestTotal = leftTotal;
            leftTotal = calculateTravelTime(curr1, n, m);
        }

        cout<<currBestTotal<<endl;
        return 0;
    }

    if (rightTotal < currBestTotal and rightTotal != -1){
        while (rightTotal < currBestTotal and curr2<greatestInd){
            curr2++;
            currBestTotal = rightTotal;
            rightTotal = calculateTravelTime(curr2, n, m);
        }

        cout<<currBestTotal<<endl;
        return 0;
    }

    cout<<currBestTotal<<endl;
    return 0;

}