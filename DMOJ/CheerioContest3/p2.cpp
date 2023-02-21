#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll my_ammo=0;
    ll their_ammo=0;
    ll score=0;

    for(ll i=0; i<n; i++){
        if(s[i]=='F'){
            if(their_ammo==0){
                if(my_ammo==0){
                    my_ammo++;
                } else {
                    score++;
                    my_ammo--;
                }
            } else {
                their_ammo--;
            }
        } else if(s[i]=='B'){
            my_ammo++;
        } else if(s[i]=='R'){
            their_ammo++;
            if(my_ammo==0){
                my_ammo++;
            } else {
                score++;
                my_ammo--;
            }
        }
        // printf("i: %d, my_ammo: %d, their_ammo: %d, score: %d\n", i, my_ammo, their_ammo, score);
    }

    cout<<score<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}