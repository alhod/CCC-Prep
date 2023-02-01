#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
  public:
  
    int editDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>>v(m+1, vector<int>(n+1));
        for(int i=0; i<m+1; i++){
            v[i][0]=i;
        }
        for(int i=0; i<n+1; i++){
            v[0][i]=i;
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1]==t[j-1]){
                    v[i][j]=v[i-1][j-1];
                } else {
                    v[i][j]=1+min(v[i-1][j-1], min(v[i][j-1], v[i-1][j]));
                }
            }
        }
        return v[m][n];
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



