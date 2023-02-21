#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll p=1;
    map<char, ll>count_a;
    map<char, ll>count_b;
    ll distinct_a=1;
    count_a[s[0]]++;
    
    ll distinct_b=0;
    
    for(ll i=1; i<n; i++){
        count_b[s[i]]++;
        if(count_b[s[i]]==1){
            distinct_b++;
        }
    }

    ll best=distinct_a+distinct_b;
    for(; p<n-1; p++){
        count_b[s[p]]--;
        if(count_b[s[p]]==0){
            distinct_b--;
        }
        count_a[s[p]]++;
        if(count_a[s[p]]==1){
            distinct_a++;
        }

        best=max(best, distinct_a+distinct_b);
    }

    cout<<best<<endl;
    
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