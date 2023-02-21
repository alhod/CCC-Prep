#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    char col;
    cin>>n>>col;
    string s;
    cin>>s;
    if(col=='g'){
        cout<<0<<endl;
        return 0;
    }
    vector<ll>greens;
    ll firstG=-1;
    for(ll i=0; i<n; i++){
        if(s[i]=='g'){
            if(firstG==-1){
                firstG=i;
            }
            greens.push_back(i);
        }
    }
    // cout<<"greens: "<<endl;
    // for(auto i:greens){
        // cout<<i<<" ";
    // }
    // cout<<endl;
    ll best=0;
    for(ll i=0; i<n; i++){
        if(s[i]==col){
            auto closestInd=upper_bound(greens.begin(), greens.end(), i);
            // cout<<"closest ind: "<<closestInd<<endl;
            if(closestInd==greens.end()){
                best=max(best, (n-i+firstG));
            } else {
                best=max(best, (*closestInd)-i);
            }
        }
    }
    cout<<best<<endl;
    
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