#include<bits/stdc++.h>
#define ll long long
using namespace std;


void add(ll n, ll p, vector<ll>&v, map<ll, bool>&new_seen){
    ll curr=0;
    new_seen[0]=true;
    ll ind=n-2;
    while(true){
        if(ind<0){
            new_seen[1]=true;
            break;
        }

        curr=v[ind]+1;
        if(curr==p){
            ind--;
        } else {
            new_seen[curr]=true;
            break;
        }
    }
}


void solution(){
    ll n, p;
    cin>>n>>p;
    vector<ll>v(n);
    map<ll, bool>seen_digit;
    map<ll, bool>new_seen;
    
    for(ll i=0; i<n; i++){
        cin>>v[i];
        seen_digit[v[i]]=true;
    }

    bool not_seen_digit=false;
    for(ll i=0; i<p; i++){
        if(!seen_digit[i]){
            not_seen_digit=true;
            break;
        }
    }

    if(!not_seen_digit){
        cout<<0<<endl;
        return;
    }

    ll first_non_seen=-1;
    for(ll i=v[n-1]; i>=0; i--){
        if(!seen_digit[i]){
            first_non_seen=i;
            break;
        }
    }

    // printf("init first_non_seen: %d\n", first_non_seen);

    if(first_non_seen==-1){
        // cout<<"early"<<endl;
        for(ll i=p-1; i>v[n-1]; i--){
            if(!seen_digit[i]){
                cout<<i-v[n-1]<<endl;
                return;
            }
        }
    }

    ll ans=p-v[n-1];

    add(n, p, v, new_seen);

    // printf("new_seen:\n");
    // for(auto i:new_seen){
    //     printf("%d %d\n", i.first, i.second);
    // }

    first_non_seen=-1;
    
    for(ll i=v[n-1]-1; i>=0; i--){
        if(!new_seen[i]&&!seen_digit[i]){
            first_non_seen=i;
            break;
        }
    }

    // printf("first_non_seen: %d\n", first_non_seen);

    if(first_non_seen==-1){
        cout<<ans<<endl;
    } else {
        cout<<ans+first_non_seen<<endl;
    }


    
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