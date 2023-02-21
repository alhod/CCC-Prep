#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll r, c;
    cin>>r>>c;
    vector<string>v(r);
    for(ll i=0; i<r; i++){
        cin>>v[i];
    }

    ll k;
    cin>>k;
    vector<char>com(k);
    for(ll i=0; i<k; i++){
        cin>>com[i];
    }

    vector<string>ans=v;

    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            // cout<<"i: "<<i<<endl;
            // cout<<"j: "<<j<<endl;
            if(v[i][j]=='X'){
                continue;
            }
            for(ll dir=0; dir<4; dir++){
                // cout<<"dir: "<<dir<<endl;
                // 0 - north
                // 1 - east
                // 2 - south
                // 3 - west
                ll currX=i;
                ll currY=j;
                ll direction=dir;
                bool imp=false;
                for(ll x=0; x<k; x++){
                    // cout<<"x: "<<x<<endl;
                    // cout<<com[x]<<endl;
                    if(com[x]=='F'){
                        if(direction==0){
                            currX--;
                            if(currX<0||v[currX][currY]=='X'){
                                imp=true;
                                // cout<<"break 1"<<endl;
                                break;
                            }
                        } else if(direction==1){
                            currY++;
                            if(currY==c||v[currX][currY]=='X'){
                                imp=true;
                                // cout<<"break 2"<<endl;
                                break;
                            }
                        } else if(direction==2){
                            currX++;
                            if(currX==r||v[currX][currY]=='X'){
                                imp=true;
                                // cout<<"break 3"<<endl;
                                break;
                            }
                        } else if(direction==3){
                            currY--;
                            if(currY<0||v[currX][currY]=='X'){
                                imp=true;
                                // cout<<"break 4"<<endl;
                                break;
                            }
                        }
                    } else if(com[x]=='L'){
                        if(direction==0){
                            direction=3;
                        } else if(direction==1){
                            direction=0;
                        } else if(direction==2){
                            direction=1;
                        } else if(direction==3){
                            direction=2;
                        }
                    } else if(com[x]=='R'){
                        if(direction==0){
                            direction=1;
                        } else if(direction==1){
                            direction=2;
                        } else if(direction==2){
                            direction=3;
                        } else if(direction==3){
                            direction=0;
                        }
                    }
                }
                if(imp==false){
                    // cout<<currX<<" "<<currY<<" = *"<<endl;
                    ans[currX][currY]='*';
                }
            }
        }
    }

    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}