#include <bits/stdc++.h>
#define int long long

using namespace std;

int_fast32_t main() {

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int repeating = 0;
        int combinations = 0;
        map<char, vector<string>>leftToRight;
        map<char, vector<string>>rightToLeft;
        map<string, int>countRepeating;
        vector<string>checkRepeating(n);

        for(int i=0;i<n;i++){
            cin>>checkRepeating[i];
        }
        sort(checkRepeating.begin(), checkRepeating.end());

        for(int i=0;i<n;i++){
            int tmp = count(checkRepeating.begin(), checkRepeating.end(), checkRepeating[i]);
            if (tmp > 1) {
                if (countRepeating.count(checkRepeating[i])) {
                    continue;
                } else {
                    countRepeating.insert(pair<string, int>(checkRepeating[i], tmp));
                }
            }

        }

        for(int i=0;i<n;i++){
            string val = checkRepeating[i];
            leftToRight[val[0]].push_back(val);
            rightToLeft[val[1]].push_back(val);
        }

        for(auto aPair : leftToRight) {
            combinations += (aPair.second.size()*(aPair.second.size()-1))/2;
        }
        for(auto aPair : rightToLeft) {
            combinations += (aPair.second.size()*(aPair.second.size()-1))/2;
        }
        cout<<combinations<<endl;
        for(auto aPair : countRepeating) {
            int tmp = ((aPair.second*(aPair.second-1))/2)*2;
            combinations-=tmp;
        }

        cout<<combinations<<endl;
    }

    return 0;

}