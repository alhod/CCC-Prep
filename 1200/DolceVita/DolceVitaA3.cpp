#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {

    int t;
    cin>>t;
    while (t--){
        int n, budget;
        cin>>n>>budget;
        vector<int>shops(n);
        for(int i=0;i<n;i++){
            cin>>shops[i];
        }
        sort(shops.begin(), shops.end());
        int dp = shops[0];
        if (dp > budget) {
            cout<<0<<endl;
            continue;
        }
        int ans = budget-shops[0] + 1;
        for (int i = 1; i < n; i++) {
            dp += shops[i];
            if (dp > budget) {
                break;
            }
            ans += ((budget-dp)/(i+1))+1;
        }
        cout<<ans<<endl;
    }

    return 1;
}