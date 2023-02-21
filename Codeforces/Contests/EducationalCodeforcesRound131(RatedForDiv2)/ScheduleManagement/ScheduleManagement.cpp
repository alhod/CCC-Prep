#include<bits/stdc++.h>
#define ll long long
using namespace std;

int compare(pair<ll, ll>n, pair<ll, ll>m){
	if(n.second<m.second){
		return true;
	} else {
		return false;
	}
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n, m;cin>>n>>m;
        map<ll, ll>ma;
        for(ll i=1;i<=n;i++){
            ma.insert(pair<ll, ll>(i, 0));
        }
        for(ll i=1;i<=m;i++){
            ll val;cin>>val;
            ma[val]++;
        }
        ll time=0;

        // for(pair<ll, ll>i:ma){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }



        while(true){
            if((*max_element(ma.begin(), ma.end(), compare)).second==0){
                break;
            }
            bool oneHour = true;
            for(pair<ll,ll> i:ma){
                if((*max_element(ma.begin(), ma.end(), compare)).second==0){
                    break;
                }
                // cout<<"num: "<<i.first<<" quantity: "<<i.second<<endl;
                // cout<<"max element: "<<(*max_element(ma.begin(), ma.end(), compare)).second<<endl;

                if(i.second>1){
                    ma[i.first]-=2;
                    oneHour = false;
                } else if(i.second==1){
                    ma[i.first]-=1;
                    i.second-=1;
                } else {
                    ll greatestInd = (*max_element(ma.begin(), ma.end(), compare)).first;
                    ma[greatestInd]--;
                    oneHour = false;
                }
            }

            if(oneHour==true){time+=1;}
            else{time+=2;}
        }
        cout<<time<<endl;
    }
}