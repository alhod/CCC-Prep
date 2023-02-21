#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }

    ll m;
    cin>>m;
    vector<ll>x(m);
    map<ll, ll>x_count;
    for(ll i=0; i<m; i++){
        cin>>x[i];
        x_count[x[i]]++;
    }


    // preliminary check
    for(ll i=0; i<n; i++){
        if(b[i]>a[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    priority_queue<pair<ll, ll>>pq;
    for(ll i=0; i<n; i++){
        // if(a[i]==b[i]){
        //     continue;
        // }
        pq.push(pair<ll, ll>(b[i], i));
    }

    set<pair<ll, ll>>s;
    queue<pair<ll, ll>>q;

    while(pq.size()>0){
        pair<ll, ll>curr=pq.top();
        pq.pop();

        swap(curr.first, curr.second);

        if(q.front().second!=curr.second){
            while(q.size()>0){
                s.insert(q.front());
                q.pop();
            }
        }

        auto iter=s.lower_bound(curr);

        // printf("curr.first: %d, curr.second: %d\n", curr.first, curr.second);

        if(a[curr.first]==b[curr.first]) {
            q.push(curr);
            continue;
        } else if(iter!=s.end()&&(*iter).second==curr.second){}    
        else {
            // printf("valid --> %d %d\n", (*iter).first, (*iter).second);
            x_count[curr.second]--;
            if(x_count[curr.second]<0){
                cout<<"NO"<<endl;
                return;
            }
        }

        s.insert(curr);
    }

    cout<<"YES"<<endl;




    
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