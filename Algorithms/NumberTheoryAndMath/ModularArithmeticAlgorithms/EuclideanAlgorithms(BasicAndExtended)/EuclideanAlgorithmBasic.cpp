// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))

// Euclidean Algorithm (Basic) finds the greatest common
// denominator for two numbers.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll EuclideanAlgorithmBasic(ll x, ll y){
    if(x==0){
        return y;
    }
    return gcd(y%x, x);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x, y;
    cin>>x>>y;
    cout<<EuclideanAlgorithmBasic(x, y)<<endl;
}