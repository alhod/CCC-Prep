// Time Complexity: O(n)  *length of text*
// Space Complexity: O(m)  *length of pattern*

// KMP (Knuth Morris Pratt) algorithm for Pattern Searching
// is used to find all occurances of a pattern in a text
// in O(n) worst case time complexity. It uses a LPS array
// (Longest Prefix Suffix) to detect repeating substrings
// in the pattern, so we avoid recomputing the pattern
// from the beginning (i think i don't know man this shit hard).


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void computeLPSArray(string pat, ll m, vector<ll>&lps){
    ll i=1;
    ll len=0;
    lps[0]=0;

    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        } else {
            if(len!=0){
                len=lps[len-1];
            } else {
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP(string pat, string txt){
    ll m=pat.length();
    ll n=txt.length();

    vector<ll>lps(m); // Longest Prefix Suffix
    
    computeLPSArray(pat, m, lps);

    ll i=0, j=0;
    while((n-i)>=(m-j)){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==m){ // reached end of pattern
            cout<<"Found pattern at index "<<i-j<<endl;
            j=lps[j-1];
        } else if(i<n&&pat[j]!=txt[i]){ // mismatch after j matches
            // Do not match lps[0...lps[j-1]] characters, 
            // they will match anyway

            if(j!=0){
                j=lps[j-1];
            } else {
                i++;
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pat, txt;
    cin>>pat>>txt;
    KMP(pat, txt);
}