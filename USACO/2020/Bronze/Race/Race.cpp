#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll k, n;
    cin>>k>>n;
    while(n--){
        ll x;
        cin>>x;
        ll leftSum=0;
        ll rightSum=0;
        ll inc=1;
        ll sec=0;
        while(true){
            leftSum+=inc;
            sec++;
            if(leftSum+rightSum>=k){
                cout<<sec<<endl;
                break;
            } else if(inc>=x){
                rightSum+=inc;
                sec++;
                if(leftSum+rightSum>=k){
                    cout<<sec<<endl;
                    break;
                }
            }
            inc++;
        }
    }
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}