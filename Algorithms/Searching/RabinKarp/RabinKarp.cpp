// Time Complexity: Best Case and Average = O(n+m), Worst Case = O(nm)
// Space Complexit: O(1)

// Rabin-Karp algorithm for pattern searching is an algorithm that combines
// sliding window and efficient hashing to quickly detect possible matches,
// then actually checks the match.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void RabinKarp(string pat, string txt){
    ll m=pat.length();
    ll n=txt.length();
    ll i, j;
    ll p=0;  // hash value for pattern
    ll t=0;  // hash value for text
    ll d=256;  // number of different characters
    ll h=1;  // used for shifting window
    ll q=997;  // prime number

    // h = d^m-1
    for(ll i=0; i<m-1; i++){
        h=(h*d)%q;
    }

    // calculate hash values for first window
    // in pat and txt
    for(ll i=0; i<m; i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }

    for(ll i=0; i<=n-m; i++){

        if(p==t){
            for(j=0; j<m; j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }

            if(j==m){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }

        // shift window
        if(i<n-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%q;

            if(t<0){
                t+=q;
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pat, txt;
    cin>>pat>>txt;
    RabinKarp(pat, txt);
}