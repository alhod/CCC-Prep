#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll t;
    cin>>t;
    while(t--){
        vector<ll>pal = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};
        string initialTime; cin>>initialTime;
        ll total=0;
        total+=(int(initialTime[0])-48)*600;
        total+=(int(initialTime[1])-48)*60;
        total+=(int(initialTime[3])-48)*10;
        total+=(int(initialTime[4])-48);
        ll x; cin>>x;
        set<ll>a;
        for(ll i=0; i<1440; i++){
            a.insert(total);
            //cout<<"total "<<total<<endl;
            total+=x;
            total%=1440;
        }
        ll num=0;
        for(ll i:a){
            if (find(pal.begin(), pal.end(), i) != pal.end()){
                num++;
            }
        }
        cout<<num<<endl;
    }

}