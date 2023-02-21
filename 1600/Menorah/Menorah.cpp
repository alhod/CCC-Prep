#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    string a, b;
    cin>>n>>a>>b;

    ll num1a=0, num1b=0, numDifferences=0;
    for(ll i=0; i<n; i++){
        if(a[i]=='1'){
            num1a++;
        }
        if(b[i]=='1'){
            num1b++;
        }
        if(a[i]!=b[i]){
            numDifferences++;
        }
    }

    ll best=1e18;

    if(num1a==num1b){
        // printf("%d == %d so query %d\n", num1a, num1b, numDifferences);
        best=min(best, numDifferences);
    }

    string c=a;
    ll num1c=0, numDifferencesFlipped=0;
    for(ll i=0; i<n; i++){
        if(c[i]=='1'){
            c[i]='0';
        } else {
            c[i]='1';
        }
    }

    for(ll i=0; i<n; i++){
        if(c[i]!=b[i]){
            numDifferencesFlipped++;
        }
        if(c[i]=='1'){
            num1c++;
        }
    }

    for(ll i=0; i<n; i++){
        if(a[i]=='1'){
            if(num1c+1==num1b){
                if(b[i]=='1'){
                    // printf("a[i]==1 and b[i]==1 so query %d\n", 1+numDifferencesFlipped-1);
                    best=min(best, 1+numDifferencesFlipped-1);
                } else {
                    // printf("a[i]==1 and b[i]==0 so query %d\n", 1+numDifferencesFlipped+1);
                    best=min(best, 1+numDifferencesFlipped+1);
                }             
            }
        }
    }

    // printf("num1a: %d, num1b: %d, num1c: %d, numDifferences: %d, numDifferencesFlipped: %d\n", num1a, num1b, num1c, numDifferences, numDifferencesFlipped);

    cout<<(best==1e18?-1:best)<<endl;


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}