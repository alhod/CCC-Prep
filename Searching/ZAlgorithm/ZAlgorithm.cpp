// Time Complexity: O(n+m)
// Space Complexity: O(n+m)

// Z Algorithm for Pattern Searching concatenates the pattern
// with the text, separated by a character (not included in)
// the text or pattern. Then, a "Z Array" is created (an 
// array at which Z[i] is the longest substring starting at
// index i that is also a prefix) in linear time, and its
// checked to see if there exists a substring of equal length
// to the prefix before the character (i.e. the pattern).


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void getZarr(string str, vector<ll>&Z){
    ll n=str.length();
    ll L=0, R=0, K;
    for(ll i=1; i<n; i++){
        // Nothing matches, calculate Z[i] using naive method
        if(i>R){
            L=R=i;
            while(R<n&&str[R-L]==str[R]){
                R++;
            }
            Z[i]=R-L;
            R--;
        } else {
            K=i-L;
            if(Z[K]<R-i+1){
                Z[i]=Z[K];
            } else {
                L=i;
                while(R<n&&str[R-L]==str[R]){
                    R++;
                }
                Z[i]=R-L;
                R--;
            }
        }
    }
}


void ZAlgorithm(string pat, string txt){
    string concat=pat+"$"+txt;
    ll l=concat.length();

    vector<ll>Z(l);
    getZarr(concat, Z);

    for(ll i=0; i<l; i++){
        if(Z[i]==pat.length()){
            cout<<"Pattern found at index "<<i-pat.length()-1<<endl;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pat, txt;
    cin>>pat>>txt;
    ZAlgorithm(pat, txt);
}