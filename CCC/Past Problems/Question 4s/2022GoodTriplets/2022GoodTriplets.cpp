#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n, c;
vector<ll>points(2000001);
vector<ll>v;


ll cal(ll start, ll end){
    ll ret=0;
    ll n=points[end]-points[start];
    ll points_start=v[start];

    // printf("start: %d, end: %d, %d %d %d\n", start, end, points_start*(n*(n-1))/2, n*(points_start*(points_start-1))/2, points_start*(points_start-1)*(points_start-2)/6);


    ret+=points_start*(n*(n-1))/2;
    ret+=n*(points_start*(points_start-1))/2;
    ret+=(points_start*(points_start-1)*(points_start-2))/6;

    // if(start>=(c+1)/2-1&&c%2==0){
    //     ll points_com=points[start+c/2]-points[start+c/2-1];
    //     ret-=points_start*(points_com*(points_com-1))/2;
    //     ret-=(points_start*(points_start-1))/2*points_com;
    // }

    return ret;
    
}


void solution(){
    cin>>n>>c;

    v.resize(c);

    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v[x]++;
    }

    for(ll i=0; i<c; i++){
        points[i]=points[i+c]=v[i];
    }

    for(ll i=1; i<c*2; i++){
        points[i]+=points[i-1];
    }


    // for(ll i=0; i<=c*2; i++){
    //     cout<<points[i]<<" ";
    // }
    // cout<<endl;

    ll ans=(n*(n-1)*(n-2))/6;

    // printf("init ans: %d\n", ans);

    for(ll i=0; i<c; i++){
        ans-=cal(i, i+c/2);
    }

    if(c%2==0){
        for(ll i=0; i<c/2; i++){
            ll points_start=v[i];
            ll points_end=v[i+c/2];
            ans+=(points_start*(points_start-1))/2*points_end;
            ans+=(points_end*(points_end-1))/2*points_start;
        }
    }

    cout<<ans<<endl;

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}