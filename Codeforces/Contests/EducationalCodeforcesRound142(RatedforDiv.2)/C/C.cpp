#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>pos(n+1);
    for(ll i=0; i<n; i++){
        pos[v[i]]=i;
    }

    ll ans=0;

    if(n%2==0){
        ll left=n/2;
        ll right=n/2+1;

        ll left_anchor=pos[left];
        ll right_anchor=pos[right];

        if(left_anchor>right_anchor){
            ans++;
            left_anchor=-1;
            right_anchor=1e18;
        }

        if(n==2){
            cout<<ans<<endl;
            return;
        }

        left--;
        right++;

        while(left>0){
            if(pos[left]<left_anchor&&pos[right]>right_anchor){
                left_anchor=pos[left];
                right_anchor=pos[right];
                
                left--;
                right++;
                continue;
            }

            ans++;
            left_anchor=-1;
            right_anchor=1e18;
            left--;
            right--;
        }
    } else {
        if(n==1){
            cout<<0<<endl;
            return;
        }

        ll mid=n/2+1;
        ll left=mid;
        ll right=mid;
        ll left_anchor=pos[mid];
        ll right_anchor=pos[mid];

        left--;
        right++;

        while(left>0){
            if(pos[left]<left_anchor&&pos[right]>right_anchor){
                left_anchor=pos[left];
                right_anchor=pos[right];

                left--;
                right++;
                continue;
            }

            ans++;
            left_anchor=-1;
            right_anchor=1e18;
            left--;
            right--;
        }
    }

    cout<<ans<<endl;
    
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