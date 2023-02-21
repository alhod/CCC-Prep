// Time Complexity: Average = O(n log n), Worse Case = O(n^2)
// Space Complexity Average = O(log n), Worse Case = O(n)

// Quick Sort: A sorting algorithm based on choosing a pivot, 
// placing the pivot in the correct position, then recursively
// sorting the remainder of the array to the left and right of 
// the pivot.

// Although it has O(n^2) worst case time complexity, it is 
// generally prefered over Merge Sort and Heap Sort


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll Partition(ll left, ll right, vector<ll>&v){
    ll pivot=right;
    ll place_pivot=left;
    for(ll i=left; i<right; i++){
        if(v[i]<v[pivot]){
            swap(v[place_pivot], v[i]);
            place_pivot++;
        }
    }
    swap(v[place_pivot], v[pivot]);
    return place_pivot;
}

void _QuickSort(ll left, ll right, vector<ll>&v){
    if(left<right){
        ll pi = Partition(left, right, v);
        _QuickSort(left, pi-1, v);
        _QuickSort(pi+1, right, v);
    }
}

void QuickSort(vector<ll>&v){
    _QuickSort(0, v.size()-1, v);
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
    QuickSort(v);
    for(ll i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}