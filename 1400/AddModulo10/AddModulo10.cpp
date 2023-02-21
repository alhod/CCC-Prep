#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    map<ll, ll>m;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        m[v[i]%10]++;
    }
    if(m[5]!=0){
        ll maxItem=0;
        for(ll i=0; i<n; i++){
            maxItem=max(maxItem, v[i]);
        }
        for(ll i=0; i<n; i++){
            if(v[i]%10==0){
                if(v[i]!=maxItem){
                    cout<<"NO"<<endl;
                    return 0;
                }
            } else {
                if(v[i]!=maxItem-5){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        cout<<"YES"<<endl;
        return 0;
    } else if(m[0]!=0){
        for(ll i=1; i<n; i++){
            if(v[i]!=v[i-1]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        return 0;
    } else {
        ll twos=-1;
        ll threes=-1;
        for(ll i=0; i<n; i++){
            if(v[i]%10==1||v[i]%10==2||v[i]%10==4||v[i]%10==8){
                if(twos==-1){
                    if(((v[i]-v[i]%10)/10)%2==1){
                        twos=1;
                    } else {
                        twos=0;
                    }
                } else if(twos==0){
                    if(((v[i]-v[i]%10)/10)%2==1){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                } else if(twos==1){
                    if(((v[i]-v[i]%10)/10)%2==0){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
            } else {
                if(threes==-1){
                    if(((v[i]-v[i]%10)/10)%2==1){
                        threes=1;
                    } else {
                        threes=0;
                    }
                } else if(threes==0){
                    if(((v[i]-v[i]%10)/10)%2==1){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                } else if(threes==1){
                    if(((v[i]-v[i]%10)/10)%2==0){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
            }
        }
        if(threes==twos){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
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