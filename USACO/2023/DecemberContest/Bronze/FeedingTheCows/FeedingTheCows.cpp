#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(k==0){
        cout<<n<<endl;
        cout<<s<<endl;
        return;
    }

    vector<char>ans(n, '.');

    if(k>=n/2){
        if(n%2==0){
            ans[n/2]='G';
            ans[n/2-1]='H';
            cout<<2<<endl;
            for(ll i=0; i<n; i++){
                cout<<ans[i];
            }
            cout<<endl;
        } else {
            if(s[0]=='G'&&s[n-1]=='G'){
                ans[n/2]='G';
                ans[n/2-1]='H';
            } else if(s[0]=='G'&&s[n-1]=='H'){
                ans[n/2-1]='G';
                ans[n/2]='H';
            } else if(s[0]=='H'&&s[n-1]=='G'){
                ans[n/2-1]='H';
                ans[n/2]='G';
            } else {
                ans[n/2]='H';
                ans[n/2-1]='G';
            }
            cout<<2<<endl;
            for(ll i=0; i<n; i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    
        return;

    }

    ll patches=0;

    ll p1=0, p2=k*2;
    
    vector<bool>covered(n);
    while(p2<n){
        if(s[p1]=='G'&&!covered[p1]){
            patches++;
            ans[p1+k]='G';
            for(ll i=p1; i<=p2; i++){
                if(s[i]=='G'){
                    covered[i]=true;
                }
            }
        }

        p1++;
        p2++;
    }

    for(ll i=p1; i<p2; i++){
        if(s[i]=='G'&&!covered[i]){
            ans[p1+k]='G';
            patches++;
            break;
        }
    }

    p1=0, p2=k*2;
    while(p2<n){
        if(s[p1]=='H'&&!covered[p1]){
            patches++;
            ans[p1+k]='H';
            for(ll i=p1; i<=p2; i++){
                if(s[i]=='H'){
                    covered[i]=true;
                }
            }
        }

        p1++;
        p2++;
    }

    for(ll i=p1; i<p2; i++){
        if(s[i]=='H'&&!covered[i]){
            if(ans[p1+k]=='G'){
                ans[p1+k-1]='H';
            } else {
                ans[p1+k]='H';
            }
            patches++;
            break;
        }
    }

    cout<<patches<<endl;
    for(ll i=0; i<n; i++){
        cout<<ans[i];   
    }
    cout<<endl;
    
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