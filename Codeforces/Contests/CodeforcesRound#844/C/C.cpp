#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    string s;
    cin>>n;
    cin>>s;

    map<char, ll>freq;

    for(ll i=0; i<26; i++){
        freq[char(i+97)]=0;
    }

    for(ll i=0; i<n; i++){
        freq[s[i]]++;
    }

    vector<pair<ll, char>>v;
    
    for(ll i=0; i<26; i++){
        v.push_back(pair<ll, char>(freq[char(i+97)], char(i+97)));
    }

    sort(v.rbegin(), v.rend());

    // for(ll i=0; i<26; i++){
        // cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    ll best=1e18;
    string best_string;

    

    for(ll i=1; i<=n; i++){
        map<char, ll>frequency_in_string;
        if(n%i!=0||n/i>26){
            continue;
        }

        ll different_characters=n/i;
        ll frequency=i;

        ll count=0;
        string ret="";
        for(ll j=0; j<n; j++){
            ret.push_back('&');
        }

        // printf("i: %d\n", i);

        for(ll j=0; j<different_characters; j++){
            // printf("curr: %c\n", v[j].second);
            for(ll x=0; x<n; x++){
                // printf("s[%d]: %c\n", x, s[x]);
                if(s[x]==v[j].second&&frequency_in_string[v[j].second]<frequency){
                    // cout<<"match"<<endl;
                    ret[x]=v[j].second;
                    frequency_in_string[v[j].second]++;
                }
            }
        }


        for(ll j=0; j<different_characters; j++){
            for(ll x=0; x<n&&frequency_in_string[v[j].second]<frequency; x++){
                if(ret[x]=='&'){
                    ret[x]=v[j].second;
                    count++;
                    frequency_in_string[v[j].second]++;
                }
            }
        }

        if(count<best){
            best=count;
            best_string=ret;
        }
    }

    cout<<best<<endl;
    cout<<best_string<<endl;

    
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