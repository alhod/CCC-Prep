#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse1(string&s, string&curr, ll ind, map<ll, bool>&visited, map<ll, ll>&memo, hash<string>&hasher){
    // cout<<"ind: "<<ind<<endl;
    // cout<<"curr: "<<curr<<endl;
    if(visited[hasher(curr)]){
        return 0;
    }
    visited[hasher(curr)]=true;
    
    ll count=1;
    // cout<<"count is: "<<count<<endl;
    for(ll i=ind+1; i<s.length(); i++){
        // cout<<"call from index "<<ind<<" to index "<<i<<endl;
        string newStr = curr+s[i];
        count+=1+recurse1(s, newStr, i, visited, memo, hasher);
    }
    // cout<<"final count for index "<<ind<<" is "<<count<<endl;
    return memo[hasher(s)]=count;
}

ll recurse(string&s, string curr, ll ind, map<ll, bool>&visited, map<ll, ll>&memo, hash<string>&hasher){
    if(visited[hasher(curr)]){
        return 0;
    }
    visited[hasher(curr)]=true;
    ll count=1;
    for(ll i=ind+1; i<s.length(); i++){
        curr+=s[i];
        // cout<<"call newStr: "<<curr<<endl;
        count+=recurse(s, curr, i+1, visited, memo, hasher);
        // cout<<"call back to "<<curr<<endl;
    }
    return memo[hasher(curr)]=count;
}

ll preRecurse(string&s, string curr, ll ind, map<ll, bool>&visited, map<ll, ll>&memo, hash<string>&hasher){
    ll count=1;
    for(ll i=0; i<s.length(); i++){
        string newStr=curr+s[i];
        count+=recurse(s, newStr, i, visited, memo, hasher);
    }
    return count;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<ll, bool>visited;
        hash<string>hasher;
        map<ll, ll>memo;
        string curr="";
        cout<<preRecurse(s, curr, 0, visited, memo, hasher)<<endl;
        
    }
}