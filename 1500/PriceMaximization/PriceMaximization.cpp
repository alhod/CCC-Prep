#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll ans=0;
    vector<ll>nums(k);
    for(ll i=0; i<n; i++){
        ans+=v[i]/k;
        v[i]=v[i]%k;
        nums[v[i]]++;
    }

    for(ll i=1; i<k; i++){
        if(nums[i]>0){
            ll component=k-i;
            // cout<<"i: "<<i<<endl;
            // for(auto i:nums){
                // cout<<i<<" ";
            // }
            // cout<<endl;
            for(ll j=component; j<k&&nums[i]>0; j++){
                if(j==i){
                    ans+=nums[j]/2;
                    nums[j]=nums[j]%2;
                } else if(nums[i]==nums[j]){
                    ans+=nums[i];
                    nums[i]=0;
                    nums[j]=0;
                } else if(nums[i]>nums[j]){
                    ans+=nums[j];
                    nums[i]-=nums[j];
                    nums[j]=0;
                } else if(nums[i]<nums[j]){
                    ans+=nums[i];
                    nums[j]-=nums[i];
                    nums[i]=0;
                }
            }
            // cout<<"new ans: "<<ans<<endl;
        }
    }
    cout<<ans<<endl;


    
    return 0;
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