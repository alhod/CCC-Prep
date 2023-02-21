// Time Complexity: O(log n)
// Space Complexity: O(1)

// Binary Search: Given a sorted array of numbers and a target, 
// returns an indice to the target or -1 if it doesn't exist


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll BinarySearch(ll n, vector<ll>&v){
    ll left=0, right=v.size()-1, mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(v[mid]==n){
            return mid;
        } else if(v[mid]>n){
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return -1;
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
    cout<<BinarySearch(m, v)<<endl;
}