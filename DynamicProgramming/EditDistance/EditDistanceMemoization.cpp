#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int recurse(string&s, string&t, int ss, int st, map<pair<int, int>, int>&m){
        if(m[pair<int, int>(ss, st)]!=0){
            return m[pair<int, int>(ss, st)];
        }
        if(ss==s.length()){
            return t.length()-st;
        }
        if(st==t.length()){
            return s.length()-ss;
        }
        
        if(s[ss]==t[st]){
            return recurse(s, t, ss+1, st+1, m);   
        }
        
        return m[pair<int, int>(ss, st)]=1+min(recurse(s, t, ss, st+1, m), min(recurse(s, t, ss+1, st, m), recurse(s, t, ss+1, st+1, m)));
    }
  
    int editDistance(string s, string t) {
        map<pair<int, int>, int>m;
        return recurse(s, t, 0, 0, m);
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



