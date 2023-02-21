#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    ll ans=0;
    ll bestLeft=n, bestRight=0;
    for(ll i=0, l=-1; i<=n; i++){
        if(i==n||a[i]==0){
            ll total2s=0;
            bool neg=false;
            ll firstNeg=-1, lastNeg=-1;
            ll num2sleft=0, num2sright=0;
            for(ll j=l+1; j<i; j++){
                neg^=a[j]<0;
                if(a[j]<0){
                    lastNeg=j;
                    num2sright=0;
                }

                if(abs(a[j])==2){
                    total2s++;
                    num2sright++;
                    if(firstNeg==-1){
                        num2sleft++;
                    }
                }

                if(a[j]<0&&firstNeg==-1){
                    firstNeg=j;
                }
            }

            if(neg){
                if(total2s-num2sleft>total2s-num2sright){
                    lastNeg=i;
                    total2s-=num2sleft;
                } else {
                    firstNeg=l;
                    total2s-=num2sright;
                }
            } else {
                firstNeg=l, lastNeg=i;
            }

            if(ans<total2s){
                ans=total2s;
                bestLeft=firstNeg+1, bestRight=n-lastNeg;
            }

            l=i;

        }
        
    }

    printf("%lld %lld\n", bestLeft, bestRight);
    
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