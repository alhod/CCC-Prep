#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int recurse(string&s, string&t, int ss, int st){
        if(ss==s.length()){
            return t.length()-st;
        }
        if(st==t.length()){
            return s.length()-ss;
        }
        
        if(s[ss]==t[st]){
            return recurse(s, t, ss+1, st+1);   
        }
        
        return 1+min(recurse(s, t, ss, st+1), min(recurse(s, t, ss+1, st), recurse(s, t, ss+1, st+1)));
    }
  
    int editDistance(string s, string t) {
        return recurse(s, t, 0, 0);
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}






