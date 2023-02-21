#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n=9;
vector<vector<ll>>v(3);
vector<pair<ll, ll>>p;

ll countNum(){
    ll nums =0;
    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            if(v[i][j]!=100000000){
                nums++;
            }
        }
    }
    return nums;
}

ll solveAdj(){

    for(ll row=0; row<3; row++){
        ll num69 = count(v[row].begin(), v[row].end(), 100000000);
        if(num69==0||num69==2){
            continue;
        } else if (num69==1){
            if(v[row][0]==100000000){
                v[row][0]=v[row][1]-(v[row][2]-v[row][1]);
                solveAdj();
            } else if(v[row][1]==100000000){
                v[row][1]=v[row][0]+((v[row][2]-v[row][0])/2);
                solveAdj();
            } else{
                v[row][2]=v[row][1]-v[row][0]+v[row][1];
                solveAdj();
            }
        }
    }
    for(ll col=0; col<3; col++){
        vector<ll>tmp={v[0][col],v[1][col],v[2][col]};
        ll num69 = count(tmp.begin(), tmp.end(), 100000000);
        if(num69==0||num69==2){
            continue;
        } else if (num69==1){
            if(v[0][col]==100000000){
                v[0][col]=v[1][col]-(v[2][col]-v[1][col]);
                solveAdj();
            } else if(v[1][col]==100000000){
                v[1][col]=v[0][col]+((v[2][col]-v[0][col])/2);
                solveAdj();
            } else{
                v[2][col]=v[1][col]-v[0][col]+v[1][col];
                solveAdj();
            }
        }
    }

    return 0;
}

ll display(){
    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


ll oneCase(){
    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            v[i][j]=v[p[0].first][p[0].second];
        }
    }
    return 0;
}

ll twoCase(){
    ll p1 = v[p[0].first][p[0].second];
    ll p2 = v[p[1].first][p[1].second];
    bool sameRow;
    bool sameCol;
    if(p[0].first==p[1].first){
        sameRow=true;
    } else {
        sameRow=false;
    }

    if(p[0].second==p[1].second){
        sameCol=true;
    } else {
        sameCol=false;
    }
    
    if(sameRow==false&&sameCol==true){
        for(ll i=0; i<3; i++){
            for(ll j=0; j<3; j++){
                if(i==p[0].first){
                    v[i][j]=p1;
                } else if (i==p[1].first){
                    v[i][j]=p2;
                }
            }
        }
    } else if(sameRow==true&&sameCol==false){
        for(ll i=0; i<3; i++){
            for(ll j=0; j<3; j++){
                if(j==p[0].second){
                    v[i][j]=p1;
                } else if (j==p[1].second){
                    v[i][j]=p2;
                }
            }
        }
    } else if(p[1].first-p[0].first==1){
        for(ll j=0; j<3; j++){
            v[p[0].first][j]=p1;
            v[p[1].first][j]=p2;
        }
    } else {
        for(ll i=0; i<3; i++){
            v[i][p[0].second]=p1;
            v[i][p[1].second]=p2;
        }
    }

    solveAdj();
    
    return 0;
}

ll threeCase(){
    if(v[0][0]!=100000000&&v[1][1]!=100000000&&v[2][2]!=100000000){
        v[1][0]=v[0][0];
    } else if(v[0][2]!=100000000&&v[1][1]!=100000000&&v[2][0]!=100000000){
        v[1][2]=v[0][2];
    } else if(v[0][0]!=100000000){
        v[1][1]=v[1][2];
    } else if(v[0][2]!=100000000){
        v[1][1]=v[1][0];
    } else if(v[2][0]!=100000000){
        v[1][1]=v[0][1];
    } else if(v[2][2]!=100000000){
        v[1][1]=v[1][0];
    }

    for(ll i=0; i<3; i++){
        if(find(v[i].begin(), v[i].end(), 100000000)==v[i].end()){
            for(ll x=0; x<3; x++){
                v[x]=v[i];
            }
            return 0;
        }
    }
    //for(auto y:v){for(auto x:y){cout<<x<<" ";}cout<<endl;}cout<<endl;
    for(ll j=0; j<3; j++){
        vector<ll>tmp={v[0][j], v[1][j], v[2][j]};
        if(find(tmp.begin(), tmp.end(), 100000000)==tmp.end()){
            for(ll i=0; i<3; i++){
                v[i]={tmp[i], tmp[i], tmp[i]};
            }
            return 0;
        }
    }
    solveAdj();
    return 0;
}

ll fiveCase(){

    for(ll row=0; row<3; row++){
        for(ll col=0; col<3; col++){
            vector<ll>tmp={v[0][col],v[1][col],v[2][col]};
            if(count(tmp.begin(), tmp.end(), 100000000)==0&&count(v[row].begin(), v[row].end(), 100000000)==0){

                if(v[1][1]==100000000){
                    ll p1=100000000;
                    ll p2=100000000;
                    for(auto aSide:{v[0][1], v[1][0], v[1][2], v[2][1]}){
                        if(aSide!=100000000){
                            if(p1==100000000){p1=aSide;}
                            else{p2=aSide;break;}
                        }
                    }
                    v[1][1]=p1*p2;
                    solveAdj();
                    return 0;
                } else {
                    v[0][0]=v[1][0]*v[0][1];
                    solveAdj();
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main1(){

    for(ll i=0;i<3;i++){
        string one, two, three; cin>>one>>two>>three;
        if(one=="X"){one="100000000"; n--;}
        else{p.push_back(pair<ll, ll>(i, 0));}
        if(two=="X"){two="100000000"; n--;}
        else{p.push_back(pair<ll, ll>(i, 1));}
        if(three=="X"){three="100000000"; n--;}
        else{p.push_back(pair<ll, ll>(i, 2));}

        vector<ll>tmp={stoi(one), stoi(two), stoi(three)};
        v[i]=tmp;
    }

    solveAdj();
    n = countNum();

    if(n==1){
        oneCase();
        display();
        return 0;
    } else if (n==2){
        twoCase();
        display();
        return 0;
    } else if (n==3){
        threeCase();
        display();
    } else if (n==5){
        fiveCase();
        display();
    } else{
        display();
    }
        
    return 0;
}

int main(){
    ll t;cin>>t;
    while(t--){
        main1();
    }
    return 0;
}