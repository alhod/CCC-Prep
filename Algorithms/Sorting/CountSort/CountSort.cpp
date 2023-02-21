// Time Complexity: O(n+k) where n is number of elements and k is the range of input
// Space Complexity: O(n+k)

// Count Sort sorts an array, in which all numbers in the array
// fall within a certain range. A count array is maintained, in
// which count[i] is the number of times i appears in the array.
// It is converted into a prefix sum-esk array, which finds the
// correct position for each element in the sorted array.

// Note there are other versions that allow for negative elements.
// https://www.geeksforgeeks.org/top-algorithms-and-data-structures-for-competitive-programming/


#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define RANGE 255  // Assumes range of numbers is 1 to 255


void CountSort(vector<ll>&v){
    vector<ll>output(v.size());

    vector<ll>count(RANGE+1);
    ll i;

    for(i=0; i<v.size(); i++){
        count[v[i]]++;
    }

    for(i=1; i<=RANGE; i++){
        count[i]+=count[i-1];
    }

    for(i=0; i<v.size(); i++){
        output[count[v[i]]-1]=v[i];
        count[v[i]]--;
    }

    for(ll i=0; i<v.size(); i++){
        v[i]=output[i];
    }
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
}