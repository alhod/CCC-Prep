#include <bits/stdc++.h>

using namespace std;





int solve(int n, int budget) {
    vector<int>shops(n);
    for (int i = 0; i < n; i++) {
        cin>>shops[i];
    }
    sort(shops.begin(), shops.end());


    int sumShops = accumulate(shops.begin(), shops.end(), 0);  
    int numShops = n;
    int purchased = 0;
    int days = 0;

    while (true) {
        
        if (numShops == 0) {
            cout<<purchased<<endl;
            return 0;
        }

        for (int i : shops) {
            // cerr<<"shop --> "<<i<<endl;
        }

        while (sumShops > budget) {
            int tmp = shops.back()+days;
            shops.pop_back();
            sumShops -= tmp;
            numShops--;
        }

        if (numShops == 0) {
            cout<<purchased<<endl;
            return 0;
        }


        int x = (budget-sumShops)/numShops;
        purchased += x*numShops;
        days+=x;
        sumShops = sumShops + numShops*(x);

        days++;
        sumShops += numShops;

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