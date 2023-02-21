#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    priority_queue<ll>pq;
    priority_queue<ll>apq;

    ll sum=0;

    while(n--){
        ll num;cin>>num;
        sum+=num;
        pq.push(num);
    }

    apq.push(sum);

    while(true){
        if(apq.size()==0&&pq.size()==0){
            cout<<"YES"<<endl;
            return 0;
        } else if (apq.size()==0||pq.size()==0){
            cout<<"NO"<<endl;
            return 0;
        }

        ll curr=apq.top();
        apq.pop();
        if(curr<pq.top()){
            cout<<"NO"<<endl;
            return 0;
        } else if (curr==pq.top()){
            pq.pop();
        } else {
            if(curr%2==0){
                apq.push(curr/2);
                apq.push(curr/2);
            } else {
                apq.push(curr/2);
                apq.push(curr/2+1);
            }
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