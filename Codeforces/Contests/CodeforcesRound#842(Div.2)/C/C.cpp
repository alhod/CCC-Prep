#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>count(n+1);
    for(ll i=0; i<n; i++){
        cin>>a[i];
        count[a[i]]++;
    }

    vector<ll>p(n);
    vector<ll>q(n);
    vector<bool>usedP(n+1);
    vector<bool>usedQ(n+1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>greatestNonFilledIndexP;  // pair<a[i] value, index>
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>greatestNonFilledIndexQ;
    priority_queue<ll, vector<ll>, greater<ll>>greatestAvailableP;
    priority_queue<ll, vector<ll>, greater<ll>>greatestAvailableQ;
    
    
    for(ll i=0; i<n; i++){
        if(count[a[i]]>=3){
            cout<<"NO"<<endl;
            return;
        }

        if(count[a[i]]==1){
            p[i]=a[i];
            q[i]=a[i];
            usedP[a[i]]=true;
            usedQ[a[i]]=true;
        } else if(!usedP[a[i]]){
            p[i]=a[i];
            usedP[a[i]]=true;
        } else if(usedP[a[i]]){
            q[i]=a[i];
            usedQ[a[i]]=true;
        }
    }

    for(ll i=0; i<n; i++){
        if(p[i]==0){
            greatestNonFilledIndexP.push(pair<ll, ll>(a[i], i));
        }
        if(q[i]==0){
            greatestNonFilledIndexQ.push(pair<ll, ll>(a[i], i));
        }
        if(!usedP[i+1]){
            greatestAvailableP.push(i+1);
        }
        if(!usedQ[i+1]){
            greatestAvailableQ.push(i+1);
        }
    }

    if(greatestNonFilledIndexP.size()!=greatestNonFilledIndexP.size()){
        cout<<"NO"<<endl;
        return;
    }
    if(greatestNonFilledIndexQ.size()!=greatestNonFilledIndexQ.size()){
        cout<<"NO"<<endl;
        return;
    }

    while(true){
        if(greatestNonFilledIndexP.size()==0&&greatestAvailableP.size()==0){
            break;
        }

        pair<ll, ll> nonFilledIndex=greatestNonFilledIndexP.top();
        greatestNonFilledIndexP.pop();
        ll available=greatestAvailableP.top();
        greatestAvailableP.pop();

        if(nonFilledIndex.first<available){
            cout<<"NO"<<endl;
            return;
        } else {
            p[nonFilledIndex.second]=available;
            usedP[available]=true;
        }
    }

    while(true){
        if(greatestNonFilledIndexQ.size()==0&&greatestAvailableQ.size()==0){
            break;
        }

        pair<ll, ll> nonFilledIndex=greatestNonFilledIndexQ.top();
        greatestNonFilledIndexQ.pop();
        ll available=greatestAvailableQ.top();
        greatestAvailableQ.pop();

        if(nonFilledIndex.first<available){
            cout<<"NO"<<endl;
            return;
        } else {
            q[nonFilledIndex.second]=available;
            usedP[available]=true;
        }
    }

    cout<<"YES"<<endl;
    for(ll i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    for(ll i=0; i<n; i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;

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