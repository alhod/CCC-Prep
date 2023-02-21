#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse(ll x, ll y, vector<vector<ll>>*v, vector<vector<ll>>visited, vector<vector<ll>>*memo, ll r, ll c){
    // cout<<"curr x y "<<x<<" "<<y<<endl;
    if(visited[x][y]==1&&(*memo)[x][y]!=0){
        return (*memo)[x][y];
    }
    if(x==r-1&&y==c-1){
        return 1;
    }
    visited[x][y]=1;
    // for(auto i:visited){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    ll count = 0;
    if(x+1<r&&(*v)[x+1][y]!=1&&visited[x+1][y]!=1){
        count+=recurse(x+1, y, v, visited, memo, r, c);
        // cout<<"call back to "<<x<<" "<<y<<endl;
        // for(auto i:visited){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    if(x-1>=0&&(*v)[x-1][y]!=1&&visited[x-1][y]!=1){
        count+=recurse(x-1, y, v, visited, memo, r, c);
        // cout<<"call back to "<<x<<" "<<y<<endl;
        // for(auto i:visited){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    if(y+1<c&&(*v)[x][y+1]!=1&&visited[x][y+1]!=1){
        count+=recurse(x, y+1, v, visited, memo, r, c);
        // cout<<"call back to "<<x<<" "<<y<<endl;
        // for(auto i:visited){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    if(y-1>=0&&(*v)[x][y-1]!=1&&visited[x][y-1]!=1){
        count+=recurse(x, y-1, v, visited, memo, r, c);
        // cout<<"call back to "<<x<<" "<<y<<endl;
        // for(auto i:visited){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    return (*memo)[x][y]=count;
    
}

int main(){
    ll r, c;
    cin>>r>>c;
    ll numCages;
    cin>>numCages;
    vector<vector<ll>>v(r, vector<ll>(c));
    for(ll i=0; i<numCages; i++){
        ll x, y;
        cin>>x>>y;
        v[x-1][y-1]=1;
    }
    vector<vector<ll>>visited(r, vector<ll>(c));
    vector<vector<ll>>memo(r, vector<ll>(c));
    cout<<recurse(0, 0, &v, visited, &memo, r, c)<<endl;


}