#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m, k;
    cin>>n>>m>>k;

    queue<ll>cards;
    for(ll i=0; i<k; i++){
        ll x;
        cin>>x;
        cards.push(x);
    }

    ll want=k;
    ll availableTiles=n*m-3;
    vector<ll>placed(100000);
    while(true){
        if(placed[want]==1){
            placed[want]--;
            want--;
            availableTiles++;
            continue;
        }
        if(cards.size()==0){
            cout<<"YA"<<endl;
            return 0;
        }
        if(availableTiles==0){
            cout<<"TIDAK"<<endl;
            return 0;
        }

        ll curr=cards.front();
        cards.pop();
        if(curr==want){
            want--;
        } else {
            placed[curr]++;
            availableTiles--;
        }
    }


    
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