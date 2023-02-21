#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    string s, t;
    cin>>s>>t;

    ll n=s.length();

    vector<ll>char_to_count_s(18);
    vector<ll>char_to_count_t(18);

    for(ll i=0; i<n; i++){
        char_to_count_s[s[i]-97]++;
        char_to_count_t[t[i]-97]++;
    }

    vector<vector<bool>>check(18, vector<bool>(18));

    for(ll i=0; i<18; i++){
        for(ll j=i; j<18; j++){
            string new_s="", new_t="";
            for(ll x=0; x<s.length(); x++){
                if(s[x]==i+97||s[x]==j+97){
                    new_s.push_back(s[x]);
                }
            }
            for(ll x=0; x<t.length(); x++){
                if(t[x]==i+97||t[x]==j+97){
                    new_t.push_back(t[x]);
                }
            }
            

            if(new_s.length()!=new_t.length()){
                check[i][j]=false;
                goto next;
            }

            for(ll x=0; x<new_s.length(); x++){
                if(new_s[x]!=new_t[x]){
                    check[i][j]=false;
                    goto next;
                }
            }

            check[i][j]=true;

            next:
            continue;
        }
    }


    ll q;
    cin>>q;
    while(q--){
        string chars;
        cin>>chars;
        for(ll i=0; i<chars.length(); i++){
            if(chars.size()==1){
                if(!check[chars[i]-'a'][chars[i]-'a']){
                    cout<<'N';
                    goto next2;
                }
            }
            for(ll j=i+1; j<chars.length(); j++){
                if(!check[chars[i]-'a'][chars[j]-'a']){
                    cout<<'N';
                    goto next2;
                }
            }
        }

        cout<<'Y';

        next2:
        continue;
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}