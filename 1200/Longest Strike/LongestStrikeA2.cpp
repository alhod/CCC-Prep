#include <bits/stdc++.h>
# define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<int>vtmp(n);
        map<int, int>counter;
        map<int, int>inV;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            vtmp[i] = val;
            counter[val]++;
        } 
        sort(vtmp.begin(), vtmp.end());
        vector<int>v;
        for(int i=0;i<n;i++){
            if(counter[vtmp[i]]>= k and inV[vtmp[i]] == 0) {
                v.push_back(vtmp[i]);
                inV[vtmp[i]]++;
            }
        }

        if(v.size() == 0){
            cout<<-1<<endl;
            continue;
        }

        tuple<int, int>ans;
        ll currL = v[0];
        ll currR = v[0];
        ans = make_tuple(currL, currR);

        for(int i=1;i<v.size();i++){
            if(v[i] == v[i-1]+1){
                currR = v[i];
            } else {
                if(currR-currL > get<1>(ans)-get<0>(ans)){
                    ans = make_tuple(currL, currR);
                }
                currL = v[i];
                currR = v[i];
            }
        }
        if(currR-currL > get<1>(ans)-get<0>(ans)){
            ans = make_tuple(currL, currR);
        }

        cout<<get<0>(ans)<<" "<<get<1>(ans)<<endl;
    }

}