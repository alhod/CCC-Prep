#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;

    if(n==0||n==1){
        cout<<n<<endl;
        return;
    }

    ll left=0;
    ll right=n/2;
    ll ans;
    while(left<=right){
        ll mid=left+(right-left)/2;
        ll squared=mid*mid;
        if(squared==n){
            cout<<mid<<endl;
            return;
        } else if(squared<n){
            left=mid+1;
            ans=mid;
        } else {
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}