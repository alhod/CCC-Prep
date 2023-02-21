// Time Complexity: O(log(n))
// Space Complexity: O(log(n))

// Euclidean Algorithm finds the greatest common divisor between 
// positive integers a and b, and also finds integer coefficients 
// x and y such that ax+by=gcd(a,b)



#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll EuclideanAlgorithmExtended(ll a, ll b, ll &x, ll &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }

    ll x1, y1;
    ll gcd=EuclideanAlgorithmExtended(b%a, a, x1, y1);

    x=y1-(b/a)*x1;
    y=x1;

    return gcd;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, x, y;
    cin>>a>>b;
    ll ret=EuclideanAlgorithmExtended(a, b, x, y);
    cout<<ret<<endl;
}