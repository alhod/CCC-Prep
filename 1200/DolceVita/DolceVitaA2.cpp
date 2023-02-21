#include <bits/stdc++.h>

using namespace std;


int solve(int n, int budget) {
    vector<int>shops(n);
    for (int i = 0; i < n; i++) {
        cin>>shops[i];
    }

    int sumShops = accumulate(shops.begin(), shops.end(), 0);
    int numShops = n;
    int purchased = 0;
    int days = 0;

    sort(shops.begin(), shops.end());

    while (true) {
        if (numShops == 0) {
            cout<<purchased<<endl;
            return 0;
        }

        // cout<<"sumShops --> "<<sumShops<<endl;
        for (int i = 0; i<n; i++) {
            // cout<<"shops --> "<<shops[i]<<endl;
        }
        while (sumShops > budget) {
            sumShops-=shops.back()+days;
            shops.pop_back();
            numShops--;
        }

        sumShops += numShops;
        purchased += numShops;
        days++;
        // cout<<purchased<<endl;

    }


}




int main() {

    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        solve(n, x);
    }

}