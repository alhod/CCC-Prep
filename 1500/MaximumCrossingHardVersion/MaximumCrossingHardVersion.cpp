#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Merge(ll n, vector<ll>&v, vector<ll>&sorted, ll left, ll mid, ll right){
    ll numInversions=0;
    ll i=left, j=mid+1, k=left;
    while(i<=mid&&j<=right){
        if(v[i]<v[j]){
            sorted[k++]=v[i++];
        } else if(v[i]>=v[j]){
            sorted[k++]=v[j++];
            numInversions+=mid-i+1;
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

    return numInversions;
}

ll _CountInversionsMergeSort(ll n, vector<ll>&v, vector<ll>&sorted, ll left, ll right){
    
    ll numInversions=0;
    if(right>left){
        ll mid=(left+right)/2;
    
        numInversions+=_CountInversionsMergeSort(n, v, sorted, left, mid);
        numInversions+=_CountInversionsMergeSort(n, v, sorted, mid+1, right);
        
        numInversions+=Merge(n, v, sorted, left, mid, right);
    }
    return numInversions;
}

ll CountInversionsMergeSort(ll n, vector<ll>&v){
    vector<ll>sorted(n);
    return _CountInversionsMergeSort(n, v, sorted, 0, n-1);
}


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<CountInversionsMergeSort(n, v)<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}