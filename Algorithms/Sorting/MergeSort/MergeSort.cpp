// Time complexity: O(n*log(n))
// Space complexity: O(n)

// Merge Sort is a sorting algorithm


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void Merge(ll n, vector<ll>&v, vector<ll>&sorted, ll left, ll mid, ll right){
    ll i=left, j=mid+1, k=left;
    while(i<=mid&&j<=right){
        if(v[i]<=v[j]){
            sorted[k++]=v[i++];
        } else if(v[i]>v[j]){
            sorted[k++]=v[j++];
        }
    }
    while(i<=mid){
        sorted[k++]=v[i++];
    }
    while(j<=right){
        sorted[k++]=v[j++];
    }

    for(ll i=left; i<=right; i++){
        v[i]=sorted[i];
    }
}

void _MergeSort(ll n, vector<ll>&v, vector<ll>&sorted, ll left, ll right){
    
    if(right>left){
        ll mid=(left+right)/2;
    
        _MergeSort(n, v, sorted, left, mid);
        _MergeSort(n, v, sorted, mid+1, right);
        
        Merge(n, v, sorted, left, mid, right);
    }
}

void MergeSort(ll n, vector<ll>&v){
    vector<ll>sorted(n);
    _MergeSort(n, v, sorted, 0, n-1);
}


int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    MergeSort(n, v);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}