#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    for(ll i=0; i<n; i++){
        pq.push(pair<ll, ll>(b[i], i));
    }
    ll left=0;
    ll right=n-1;
    vector<ll>visited(n);
    ll cost=0;

    while(pq.size()>0){
        pair<ll, ll> curr=pq.top();
        // cout<<"curr: "<<curr.first<<" "<<curr.second<<endl;
        pq.pop();
        cost+=a[curr.second];
        visited[curr.second]=1;
        if(curr.second==left&&curr.second==right){
            break;
        } else if(curr.second==left){
            cost+=b[curr.second];
            left++;
            while(true){
                if(visited[left]==1){
                    left++;
                } else {
                    break;
                }
            }
        } else if(curr.second==right){
            cost+=b[curr.second];
            right--;
            while(true){
                if(visited[right]==1){
                    right--;
                } else {
                    break;
                }
            }
        } else {
            cost+=2*b[curr.second];
        }
    }

    cout<<cost<<endl;

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