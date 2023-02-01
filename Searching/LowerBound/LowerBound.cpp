// Time Complexity: O(log n)
// Space complexity: O(1)

// Lower Bound Array: Given a target, 
// returns the index to the first element in the array not less than the target

// Lower Bound True False: Given a range of numbers and a comparator
// returns the first number in the range of values that satisfies the comparator


#include<bits/stdc++.h>
#define ll long long
using namespace std;



bool comparator(ll n, ll target){
    return n>=target;
}

ll LowerBoundArray(ll target, vector<ll>&v){
    ll left=0, right=v.size()-1, mid, ans;
    bool found=false;

    while(left<=right){
        mid=left+(right-left)/2;
        if(comparator(v[mid], target)==true){
            found=true;
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }

    return (found?ans:-1);
}





bool comparator2(ll n){
    return n>=4;
}

ll LowerBoundTrueFalse(ll left, ll right){
    ll mid, ans;
    bool found=false;

    while(left<=right){
        mid=left+(right-left)/2;
        if(comparator2(mid)){
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
    cout<<LowerBoundArray(m, v)<<endl;
    
    ll l, r;
    cin>>l>>r;
    cout<<LowerBoundTrueFalse(l, r)<<endl;
}