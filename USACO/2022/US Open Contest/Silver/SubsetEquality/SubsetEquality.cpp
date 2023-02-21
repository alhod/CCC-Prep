#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    string s, t;
    cin>>s>>t;

    ll n=s.length();

    vector<set<char>>impossible(18);
    vector<ll>char_to_count_s(18);
    vector<ll>char_to_count_t(18);
    vector<bool>bad_chars(18);
    vector<bool>in_string(18);
    set<char>sliding_window_s;
    set<char>sliding_window_t;
    vector<ll>count_in_sliding_window_s(18);
    vector<ll>count_in_sliding_window_t(18);


    for(ll i=0; i<n; i++){
        char_to_count_s[s[i]-97]++;
        char_to_count_t[t[i]-97]++;
        in_string[s[i]-97]=true;
        in_string[t[i]-97]=true;
    }

    for(ll i=0; i<18; i++){
        if(char_to_count_s[i]!=char_to_count_t[i]){
            bad_chars[i]=true;
        }
    }


    for(ll i=0; i<n; i++){
        if(!bad_chars[s[i]-97]&&count_in_sliding_window_t[s[i]-97]){
            for(auto j:sliding_window_s){
                impossible[s[i]-97].insert(j);    
            }
            count_in_sliding_window_t[s[i]-97]--;
            if(!count_in_sliding_window_t[s[i]-97]){
                sliding_window_t.erase(s[i]);
            }
        } else if(!bad_chars[s[i]-97]){
            count_in_sliding_window_s[s[i]-97]++;
            sliding_window_s.insert(s[i]);
        }


        if(!bad_chars[t[i]-97]&&count_in_sliding_window_s[t[i]-97]){
            for(auto j:sliding_window_t){
                impossible[t[i]-97].insert(j);            
            }
            count_in_sliding_window_s[t[i]-97]--;
            if(!count_in_sliding_window_s[t[i]-97]){
                sliding_window_s.erase(t[i]);
            }
        } else if(!bad_chars[t[i]-97]){
            count_in_sliding_window_t[t[i]-97]++;
            sliding_window_t.insert(t[i]);
        }
    }


    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());


    sliding_window_s.clear();
    sliding_window_t.clear();
    count_in_sliding_window_s.clear();    
    count_in_sliding_window_s.resize(18);
    count_in_sliding_window_t.clear();    
    count_in_sliding_window_t.resize(18);

    for(ll i=0; i<n; i++){
        if(!bad_chars[s[i]-97]&&count_in_sliding_window_t[s[i]-97]){
            for(auto j:sliding_window_s){
                impossible[s[i]-97].insert(j);            
            }
            count_in_sliding_window_t[s[i]-97]--;
            if(!count_in_sliding_window_t[s[i]-97]){
                sliding_window_t.erase(s[i]);
            }
        } else if(!bad_chars[s[i]-97]){
            count_in_sliding_window_s[s[i]-97]++;
            sliding_window_s.insert(s[i]);
        }


        if(!bad_chars[t[i]-97]&&count_in_sliding_window_s[t[i]-97]){
            for(auto j:sliding_window_t){
                impossible[t[i]-97].insert(j);
            }
            count_in_sliding_window_s[t[i]-97]--;
            if(!count_in_sliding_window_s[t[i]-97]){
                sliding_window_s.erase(t[i]);
            }
        } else if(!bad_chars[t[i]-97]){
            count_in_sliding_window_t[t[i]-97]++;
            sliding_window_t.insert(t[i]);
        }
    }


    // for(ll i=0; i<18; i++){
    //     cout<<"i: "<<i<<endl;
    //     for(auto j:impossible[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    ll q;
    cin>>q;
    while(q--){
        string chars;
        cin>>chars;
        vector<bool>in_chars(18);

        bool flag=false;

        for(auto j:chars){
            in_chars[j-97]=true;
        }

        for(auto j:chars){
            if(flag)break;

            // if(!in_string[j-97]){
            //     cout<<'N';
            //     flag=true;
            //     break;
            // }

            if(bad_chars[j-97]){
                cout<<'N';
                flag=true;
                break;
            }

            for(auto x:impossible[j-97]){
                if(in_chars[x-97]){
                    cout<<'N';
                    flag=true;
                    break;
                }
            }
        }

        if(!flag){cout<<'Y';}
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}