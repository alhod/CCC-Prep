#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll id=0;

bool check(ll n, ll m, ll r, ll c, vector<string>&v, vector<vector<ll>>&cnt){
    ll num_neighbors=0;
    ll curr_id;
    if(cnt[r][c]==-1){
        // printf("case 1\n");
        curr_id=id;
        id++;
        cnt[r][c]=curr_id;
        if(v[r-1][c]=='*'){
            num_neighbors++;
            if(cnt[r-1][c]!=-1){
                return false;
            } else {
                cnt[r-1][c]=curr_id;
            }
        }
        if(v[r-1][c-1]=='*'){
            num_neighbors++;
            if(cnt[r-1][c-1]!=-1){
                return false;
            } else {
                cnt[r-1][c-1]=curr_id;
            }
        }
        if(v[r-1][c+1]=='*'){
            num_neighbors++;
            if(cnt[r-1][c+1]!=-1){
                return false;
            } else {
                cnt[r-1][c+1]=curr_id;
            }
        }
        if(v[r][c-1]=='*'){
            num_neighbors++;
            if(cnt[r][c-1]!=-1){
                return false;
            } else {
                cnt[r][c-1]=curr_id;
            }
        }
        if(v[r][c+1]=='*'){
            num_neighbors++;
            if(cnt[r][c+1]!=-1){
                return false;
            } else {
                cnt[r][c+1]=curr_id;
            }
        }
        if(v[r+1][c]=='*'){
            num_neighbors++;
            if(cnt[r+1][c]!=-1){
                return false;
            } else {
                cnt[r+1][c]=curr_id;
            }
        }
        if(v[r+1][c-1]=='*'){
            num_neighbors++;
            if(cnt[r+1][c-1]!=-1){
                return false;
            } else {
                cnt[r+1][c-1]=curr_id;
            }
        }
        if(v[r+1][c+1]=='*'){
            num_neighbors++;
            if(cnt[r+1][c+1]!=-1){
                return false;
            } else {
                cnt[r+1][c+1]=curr_id;
            }
        }
    } else {
        // printf("case 2\n");
        curr_id=cnt[r][c];
        if(v[r-1][c]=='*'){
            num_neighbors++;
            if(cnt[r-1][c]!=curr_id){
                return false;
            }
        }
        if(v[r-1][c-1]=='*'){
            num_neighbors++;
            if(cnt[r-1][c-1]!=curr_id){
                return false;
            }
        }
        if(v[r-1][c+1]=='*'){
            num_neighbors++;
            if(cnt[r-1][c+1]!=curr_id){
                return false;
            }
        }
        if(v[r][c-1]=='*'){
            num_neighbors++;
            if(cnt[r][c-1]!=curr_id){
                return false;
            }
        }
        if(v[r][c+1]=='*'){
            num_neighbors++;
            if(cnt[r][c+1]!=curr_id){
                return false;
            }
        }
        if(v[r+1][c]=='*'){
            num_neighbors++;
            if(cnt[r+1][c]!=curr_id){
                return false;
            }
        }
        if(v[r+1][c-1]=='*'){
            num_neighbors++;
            if(cnt[r+1][c-1]!=curr_id){
                return false;
            }
        }
        if(v[r+1][c+1]=='*'){
            num_neighbors++;
            if(cnt[r+1][c+1]!=curr_id){
                return false;
            }
        }
    }

    if(num_neighbors!=2){
        return false;
    }

    return true;
}



void solution(){
    ll n, m;
    cin>>n>>m;
    id=0;
    vector<string>v(n+2);
    string tmp="";
    for(ll i=0; i<m+2; i++){
        tmp.push_back('.');
    }
    v[0]=tmp;
    v[n+1]=tmp;

    for(ll i=1; i<n+1; i++){
        cin>>v[i];
        v[i]='.'+v[i]+'.';
    }

    vector<vector<ll>>cnt(n+2, vector<ll>(m+2, -1));
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<m+1; j++){
            if(v[i][j]=='.'){
                continue;
            }

            if(!check(n+2, m+2, i, j, v, cnt)){
                // printf("%d %d %d %d\n", n+2, m+2, i, j);
                // for(ll x=0; x<n+2; x++){
                    // for(ll y=0; y<m+2; y++){
                        // cout<<cnt[x][y]<<" ";
                    // }
                    // cout<<endl;
                // }
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
    
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