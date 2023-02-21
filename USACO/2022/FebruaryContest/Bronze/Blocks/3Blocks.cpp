#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string s, s2, s3, s4;
    cin>>s>>s2>>s3>>s4;
    vector<ll>v(26);
    vector<ll>v2(26);
    vector<ll>v3(26);
    vector<ll>v4(26);
    for(ll i=0; i<6; i++){
        v[s[i]-65]++;
    }
    for(ll i=0; i<6; i++){
        v2[s2[i]-65]++;
    }
    for(ll i=0; i<6; i++){
        v3[s3[i]-65]++;
    }
    for(ll i=0; i<6; i++){
        v4[s4[i]-65]++;
    }
    vector<vector<ll>>cnt;
    cnt.push_back(v);
    cnt.push_back(v2);
    cnt.push_back(v3);
    cnt.push_back(v4);
    // for(auto i:cnt){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    while(n--){
        string get;
        cin>>get;
        if(get.length()==1){
            bool imp=true;
            for(ll i=0; i<6; i++){
                if(s[i]==get[0]){
                    cout<<"YES"<<endl;
                    imp=false;
                    break;
                }
            }
            if(imp==false){
                continue;
            }
            for(ll i=0; i<6; i++){
                if(s2[i]==get[0]){
                    cout<<"YES"<<endl;
                    imp=false;
                    break;
                }
            }
            if(imp==false){
                continue;
            }
            for(ll i=0; i<6; i++){
                if(s3[i]==get[0]){
                    cout<<"YES"<<endl;
                    imp=false;
                    break;
                }
            }
            if(imp==false){
                continue;
            }
            for(ll i=0; i<6; i++){
                if(s4[i]==get[0]){
                    cout<<"YES"<<endl;
                    imp=false;
                    break;
                }
            }
            if(imp==false){
                continue;
            }
            cout<<"NO"<<endl;
        } else if(get.length()==2){
            bool solved=false;
            for(ll i=0; i<4; i++){
                if(cnt[i][get[0]-65]==0){
                    continue;
                }
                for(ll j=0; j<4; j++){
                    if(j==i){
                        continue;
                    }
                    if(cnt[j][get[1]-65]>0){
                        cout<<"YES"<<endl;
                        solved=true;
                        break;
                    }
                }
                if(solved==true){
                    break;
                }
            }
            if(solved==true){
                continue;
            }
            cout<<"NO"<<endl;
        } else if(get.length()==3){
            bool solved=false;
            for(ll i=0; i<4; i++){
                if(cnt[i][get[0]-65]==0){
                    continue;
                }
                for(ll j=0; j<4; j++){
                    if(i==j){
                        continue;
                    }
                    if(cnt[j][get[1]-65]==0){
                        continue;
                    }
                    for(ll x=0; x<4; x++){
                        if(x==i||x==j){
                            continue;
                        }
                        if(cnt[x][get[2]-65]==0){
                            continue;
                        }
                        cout<<"YES"<<endl;
                        solved=true;
                        break;
                    }
                    if(solved==true){
                        break;
                    }
                }
                if(solved==true){
                    break;
                }
            }
            if(solved==true){
                continue;
            }
            cout<<"NO"<<endl;

        } else if(get.length()==4){
            bool solved=false;
            for(ll i=0; i<4; i++){
                // cout<<"i: "<<i<<endl;
                if(cnt[i][get[0]-65]==0){
                    continue;
                }
                for(ll j=0; j<4; j++){
                    // cout<<"j: "<<j<<endl;
                    if(j==i){
                        continue;
                    }
                    if(cnt[j][get[1]-65]==0){
                        continue;
                    }
                    for(ll x=0; x<4; x++){
                        // cout<<"x: "<<x<<endl;
                        if(x==j||x==i){
                            continue;
                        }
                        if(cnt[x][get[2]-65]==0){
                            continue;
                        }
                        for(ll y=0; y<4; y++){
                            if(cnt[y][get[3]-65]==0){
                                continue;
                            }
                            if(y==x||y==i||y==j){
                                continue;
                            }
                            cout<<"YES"<<endl;
                            solved=true;
                            break;
                        }
                        if(solved==true){
                            break;
                        }
                    }
                    if(solved==true){
                        break;
                    }
                }
                if(solved==true){
                    break;
                }
            }
            if(solved==true){
                continue;
            }
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}