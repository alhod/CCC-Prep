#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, c;
    cin>>n>>c;
    vector<ll>v(n+1);
    vector<ll>seats(c);


    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v[x]++;
    }

    priority_queue<ll>people;
    priority_queue<ll>available_seats;

    for(ll i=0; i<n+1; i++){
        if(v[i]>0){
            people.push(v[i]);
        }
    }

    for(ll i=0; i<c; i++){
        ll x;
        cin>>x;
        available_seats.push(x);
    }

    ll ans=0;

    while(available_seats.size()>0&&people.size()>0){
        ll group=people.top();
        people.pop();

        ll a_seat=available_seats.top();
        available_seats.pop();

        // printf("group: %d, a_seat: %d\n", group, a_seat);

        ll to_be_seated=min(group, a_seat);

        // printf("to be seated: %d\n", to_be_seated);

        group-=to_be_seated;
        if(group>0){
            people.push(group);
        }

        ans+=to_be_seated;
    }

    cout<<ans<<endl;

    

    
    // vector<bool>taken(c);

    // for(ll i=0; i<n; i++){
    //     ll x;
    //     cin>>x;
    //     v[x]++;
    // }
    // for(ll i=0; i<c; i++){
    //     cin>>seats[i];
    // }

    // while(true){
    //     sort(v.rbegin(), v.rend());
    //     sort(seats.rbegin(), seats.rend());

    //     ll group=v[0];
    //     if(group==0){
    //         break;
    //     }

    //     bool found_available=false;
    //     for(ll i=0; i<c; i++){
    //         if(!taken[i]){
    //             ll to_be_seated=min(group, seats[i]);
    //             group-=to_be_seated;
    //             seats[i]-=to_be_seated;
    //             taken[i]=true;
    //             found_available=true;
    //         }
    //     }

    //     if(!found_available){
    //         for(ll i=0; i<c; i++){

    //         }
    //     }
    // }
    


    
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