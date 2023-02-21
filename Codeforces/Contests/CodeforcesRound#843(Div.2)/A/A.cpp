#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    string s;
    cin>>s;

    if(s[0]=='a'&&s[s.length()-1]=='a'){
        string left="a";
        string right="a";
        string middle="";
        for(ll i=1; i<s.length()-1; i++){
            middle.push_back(s[i]);
        }
        cout<<left<<" "<<middle<<" "<<right<<endl;
    } else if(s[0]=='a'&&s[s.length()-1]=='b'){
        if(s[1]=='a'){
            string right="";
            for(ll i=2; i<s.length(); i++){
                right.push_back(s[i]);
            }
            cout<<s[0]<<" "<<s[1]<<" "<<right<<endl;
        } else {
            string middle="";
            for(ll i=1; i<s.length()-1; i++){
                middle.push_back(s[i]);
            }
            cout<<s[0]<<" "<<middle<<" "<<s[s.length()-1]<<endl;
        }
        
    } else if(s[0]=='b'&&s[s.length()-1]=='a'){
        if(s[1]=='a'){
            string right="";
            for(ll i=2; i<s.length(); i++){
                right.push_back(s[i]);
            }
            cout<<s[0]<<" "<<s[1]<<" "<<right<<endl;
        } else {
            string middle="";
            for(ll i=1; i<s.length()-1; i++){
                middle.push_back(s[i]);
            }
            cout<<s[0]<<" "<<middle<<" "<<s[s.length()-1]<<endl;
        }
    } else {
        string left="b";
        string right="b";
        string middle="";
        for(ll i=1; i<s.length()-1; i++){
            middle.push_back(s[i]);
        }
        cout<<left<<" "<<middle<<" "<<right<<endl;
    }
    
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