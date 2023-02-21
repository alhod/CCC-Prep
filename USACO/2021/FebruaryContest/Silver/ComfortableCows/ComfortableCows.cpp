#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>>v;
ll to_add=0;


pair<ll, ll>find_missing(ll x, ll y){
    ll num_surrounding=0;
    num_surrounding+=v[x-1][y]==1;
    num_surrounding+=v[x+1][y]==1;
    num_surrounding+=v[x][y-1]==1;
    num_surrounding+=v[x][y+1]==1;

    if(num_surrounding==4){
        to_add--;
    }

    if(num_surrounding!=3){
        return pair<ll, ll>(-1, -1);
    }

    if(v[x-1][y]==0){
        return pair<ll, ll>(x-1, y);
    }
    if(v[x+1][y]==0){
        return pair<ll, ll>(x+1, y);
    }
    if(v[x][y+1]==0){
        return pair<ll, ll>(x, y+1);
    }
    if(v[x][y-1]==0){
        return pair<ll, ll>(x, y-1);
    }

    return pair<ll, ll>(-1, -1);
}


void check_surrounding(ll x, ll y){
    
    if(v[x-1][y]==1){
        pair<ll, ll>ret=find_missing(x-1, y);
        if(ret.first!=-1){
            to_add++;
            v[ret.first][ret.second]--;
        }
    }
    if(v[x+1][y]==1){
        pair<ll, ll>ret=find_missing(x+1, y);
        if(ret.first!=-1){
            to_add++;
            v[ret.first][ret.second]--;
        }
    }
    if(v[x][y-1]==1){
        pair<ll, ll>ret=find_missing(x, y-1);
        if(ret.first!=-1){
            to_add++;
            v[ret.first][ret.second]--;
        }
    }
    if(v[x][y+1]==1){
        pair<ll, ll>ret=find_missing(x, y+1);
        if(ret.first!=-1){
            to_add++;
            v[ret.first][ret.second]--;
        }
    }


}


void solution(){
    ll n;
    cin>>n;
    
    v.resize(1003, vector<ll>(1003));
    
    
    for(ll i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;
        x++;
        y++;
        // if(v[x][y]<0){
        //     to_add-=v[x][y];
        // }
        v[x][y]=1;

        check_surrounding(x, y);
        cout<<to_add<<endl;
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}