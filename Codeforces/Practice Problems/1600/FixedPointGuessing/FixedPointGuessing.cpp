#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool recurse1(ll l, ll r){
    printf("%d %d\n", l, r);
    // if(r-l+1==3){
    //     cout<<"3 case"<<endl;
    //     printf("? %d %d\n", l, r-1);
    //     fflush(stdout);

    //     vector<ll>ret(2);
    //     cin>>ret[0];
    //     fflush(stdout);
    //     cin>>ret[1];
    //     fflush(stdout);

    //     if(ret[0]==l&&ret[1]==l+1){
    //         printf("! %d\n", r);
    //         fflush(stdout);
    //     } else if(ret[0]==l&&ret[1]==l+2){
    //         printf("! %d\n", l);
    //         fflush(stdout);
    //     } else if(ret[0]==l+1&&ret[1]==l+2){
    //         printf("! %d\n", l+1);
    //         fflush(stdout);
    //     }
    //     return true;
    // } else if(r-l+1==2){
    //     cout<<"case 2"<<endl;
    //     printf("? %d %d\n", l, r);
    //     fflush(stdout);
    //     ll a, b;
    //     cin>>a>>b;
    //     fflush(stdout);

    //     if(l<=a&&a<=r&&l<=b&&b<=r){
    //         return false;
    //     } else if(l<=a&&a<=r){
    //         printf("! %d\n", a);
    //         fflush(stdout);
    //         return true;
    //     } else if(l<=b&&b<=r){
    //         printf("! %d\n", b);
    //         fflush(stdout);
    //         return true;
    //     } else {
    //         return false;
    //     }
    // } else if(r-l+1==1){
    //     printf("? %d %d\n", l, r);
    //     fflush(stdout);

    //     ll a;
    //     cin>>a;
    //     if(a==l&&a==r){
    //         printf("! %d\n", l);
    //         fflush(stdout);
    //     } else {
    //         return false;
    //     }
    // }

    if(r-l+1==1){
        printf("? %d %d\n", l, r);
        fflush(stdout);
        ll a;
        cin>>a;
        fflush(stdout);
        if(a==l){
            printf("! %d\n", l);
            fflush(stdout);
            return true;
        } else {
            return false;
        }
    }
    
    
    printf("? %d %d\n", l, (l+r)/2);
    fflush(stdout);

    vector<ll>ret((l+r)/2-l+1);
    for(ll i=0; i<(l+r)/2-l+1; i++){
        cin>>ret[i];
    }

    ll diff=0, same=0;
    for(ll i=0; i<(l+r)/2-l+1; i++){
        if(ret[i]>=l&&ret[i]<=(l+r)/2){
            same++;
        } else {
            diff++;
        }
    }

    if(same%2==1){
        printf("same: %d\n", same);
        if(!recurse1(l, (l+(l+r)/2)/2)){
            if(!recurse1((l+(l+r)/2)/2+1, r)){
                return false;
            }
            return true;
        }
    } else {
        printf("diff: %d\n", diff);
        if(!recurse1((l+r)/2+1, r)){
            return false;
        }
    }

    return true;
}

bool recurse(ll l, ll r){
    // printf("start: %d %d\n", l, r);

    // if(l==r){
    //     printf("? %d %d\n", l, r);
    //     fflush(stdout);
        
    //     ll a;
    //     cin>>a;
    //     fflush(stdout);
        
    //     if(a==l){
    //         printf("! %d\n", l);
    //         fflush(stdout);
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }


    printf("? %d %d\n", l, (l+r)/2);
    fflush(stdout);

    vector<ll>ret((l+r)/2-l+1);
    for(ll i=0; i<(l+r)/2-l+1; i++){
        cin>>ret[i];
        fflush(stdout);
    }


    ll same=0, diff=0;
    for(ll i=0; i<(l+r)/2-l+1; i++){
        if(l<=ret[i]&&ret[i]<=(l+r)/2){
            same++;
        } else {
            diff++;
        }
    }

    // printf("same: %d, diff: %d\n", same, diff);

    if(same%2==1){
        if(l==r){
            printf("! %d\n", l);
            fflush(stdout);
            return true;
        }

        recurse(l, (l+r)/2);
    } else {
        recurse((l+r)/2+1, r);
    }

    return true;
}

void solution(){
    ll n;
    cin>>n;

    recurse(1, n);
    
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