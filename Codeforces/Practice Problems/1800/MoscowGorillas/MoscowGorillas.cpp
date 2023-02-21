#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);

    vector<ll>num_to_ind_a(n+1);
    vector<ll>num_to_ind_b(n+1);
    
    for(ll i=0; i<n; i++){
        cin>>a[i];
        num_to_ind_a[a[i]]=i;
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
        num_to_ind_b[b[i]]=i;
    }


    ll ans=1;
    ans+=(min(num_to_ind_a[1], num_to_ind_b[1]))*(min(num_to_ind_a[1], num_to_ind_b[1])+1)/2;
    // cout<<"init ans: "<<ans<<endl;
    ans+=(n-max(num_to_ind_a[1], num_to_ind_b[1])-1)*((n-max(num_to_ind_a[1], num_to_ind_b[1])))/2;
    // cout<<"init ans: "<<ans<<endl;
    ll diff=abs(num_to_ind_a[1]-num_to_ind_b[1]);
    if(diff>1){
        diff--;
        ans+=diff*(diff+1)/2;
    }
    
    // cout<<"init ans: "<<ans<<endl;

    ll p1=min(num_to_ind_a[1], num_to_ind_b[1]);
    ll p2=max(num_to_ind_a[1], num_to_ind_b[1]);

    for(ll i=2; i<=n; i++){
        ll p_left=min(num_to_ind_a[i], num_to_ind_b[i]);
        ll p_right=max(num_to_ind_a[i], num_to_ind_b[i]);

        if((p_left>=p1&&p_left<=p2)||(p_right>=p1&&p_right<=p2)){
            
        } else if(p_left<p1&&p_right<p1){
            ans+=(p1-p_right)*(n-p2);
        } else if(p_left>p2&&p_right>p2){
            ans+=(p_left-p2)*(p1+1);
        } else {
            ans+=(p1-p_left)*(p_right-p2);
        }

        p1=min(p1, p_left);
        p2=max(p2, p_right);
    }

    cout<<ans<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}