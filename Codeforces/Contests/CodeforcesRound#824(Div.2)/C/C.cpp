#include<bits/stdc++.h>
#define ll long long
using namespace std;

// a ascii = 97

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char, bool>seen;
        map<char, bool>taken;
        map<char, bool>taken2;
        vector<char>letterToChar(27);
        string ans;
        string nextLowest = "abcdefghijklmnopqrstuvwxyz";
        string nextLowest2 = "";
        ll ind=0;
        ll counter=0;

        // cout<<"sec 1"<<endl;
        for(ll i=0; i<n; i++){
            if(seen[s[i]]){
                cout<<"seen: "<<s[i]<<endl;
                ans.push_back(letterToChar[s[i]-97]);
                continue;
            }
            // cout<<"curr s[i]: "<<s[i]<<endl;
            seen[s[i]]=true;
            bool passed = false;
            // cout<<"sec 2"<<endl;
            for(ll j=0; j<26; j++){
                if(s[i]==nextLowest[j]){
                    continue;
                }
                if(taken[nextLowest[j]]){//||seen[nextLowest[j]]
                    continue;
                }
                if(taken[s[i]]&&seen[nextLowest[j]]){
                    // cout<<"seen: "<<nextLowest[j]<<" and taken "<<s[i]<<endl; 
                    continue;
                }
                if(taken[s[i]]==false){
                    nextLowest2.push_back(s[i]);
                    // cout<<"new nextLowest2: "<<nextLowest2<<endl;
                }
                seen[s[i]]=true;
                taken[nextLowest[j]]=true;
                letterToChar[s[i]-97]=nextLowest[j];
                passed = true;
                ans.push_back(nextLowest[j]);
                break;
            }
            // cout<<"sec 3"<<endl;
            if(passed==false){
                // cout<<"passed == false"<<endl;
                for(ll j=0; j<26; j++){
                    if(taken2[nextLowest2[j]]){
                        continue;
                    }
                    if(taken[nextLowest2[j]]){
                        continue;
                    }
                    if(taken[s[i]]==false){
                        nextLowest2.push_back(s[i]);
                    }
                    taken2[nextLowest[j]]=true;
                    seen[s[i]]=true;
                    letterToChar[s[i]-97]=nextLowest2[j];
                    ans.push_back(nextLowest2[j]);
                    break;
                }
            }
            // cout<<"new ans: "<<ans<<endl;
            // cout<<"sec 4"<<endl;

        }
        cout<<ans<<endl;
    }
}