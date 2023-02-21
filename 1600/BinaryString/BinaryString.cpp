#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll n, c;
vector<ll>p;

bool check(ll k){
    

    ll best=1e18;
    ll p1=0;
    ll p2=c-k-1;
    // printf("k: %d, c: %d, p1: %d, p2: %d\n", k, c, p1, p2);
    while(p2<p.size()){
        best=min(best, p[p2]-p[p1]+1);
        p1++;
        p2++;
    }

    // printf("%d - %d\n", best, c-k);

    best-=c-k;

    // printf("best: %d\n", best);

    return best<=k;
}

void solution(){
    cin>>s;
    n=s.length();
    c=0;
    p.clear();

    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            p.push_back(i);
        }
    }

    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            c++;
        }
    }

    ll left=0, right=c, mid, ans;
    while(left<=right){
        mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }

    printf("%d\n", ans);

    
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