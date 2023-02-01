// Time Complexity: O(log n)
// Space Complexity: O(1)

// Upper Bound: Given a target and a sorted array,
// returns the indice of the first element strictly greater than the target in the array


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll UpperBound(ll target, vector<ll>&v){
    ll left=0, right=v.size()-1, mid, ans;
    bool found=false;
    while(left<=right){
        mid=left+(right-left)/2;
        if(v[mid]>target){
            found=true;
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return (found?ans:-1);
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll m;
    cin>>m;
    cout<<UpperBound(m, v)<<endl;
}