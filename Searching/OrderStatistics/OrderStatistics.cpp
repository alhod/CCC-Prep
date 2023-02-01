// Time Complexity: Average = O(n), Worst Case = O(n^2)
// Space Complexity: O(1)

// This Order Statistics/Kth Smallest Element algorithm utilises partitions
// (in a similar way to QuickSort) on random pivots to find the kth smallest
// element, though the worst case time complexity is still O(n^2).



#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Partition(ll left, ll right, vector<ll>&v){
    ll pivot=v[right];
    ll place_pivot=left;
    for(ll i=left; i<right; i++){
        if(v[i]<=pivot){
            swap(v[place_pivot], v[i]);
            place_pivot++;
        }
    }
    swap(v[place_pivot], v[right]);
    return place_pivot;
}

ll RandomPartition(ll l, ll r, vector<ll>&v){
    ll n=r-l+1;
    ll pivot=rand()%n;
    swap(v[l+pivot], v[r]);
    return Partition(l, r, v);
}


ll _KthSmallestElement(ll left, ll right, vector<ll>&v, ll k){
    if(k>0&&k<=right-left+1){
        ll pos=RandomPartition(left, right, v);

        if(pos-left==k-1){
            return v[pos];
        } else if(pos-left>k-1){
            return _KthSmallestElement(left, pos-1, v, k);
        } else {
            return _KthSmallestElement(pos+1, right, v, k-pos+left-1);
        }
    }
    return -1;
}


ll KthSmallestElement(ll k, vector<ll>&v){
    return _KthSmallestElement(0, v.size()-1, v, k);
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
    ll k;
    cin>>k;
    cout<<KthSmallestElement(k, v)<<endl;
}