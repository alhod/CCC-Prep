#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m, r, c;
    cin>>n>>m>>r>>c;

    ll tmpr=r, tmpc=c;

    vector<vector<char>>v(n, vector<char>(m, 'a'));

    if(n%2==1&&m%2==1){
        r=n-r;
        c=m-c;
        if(c==0){
            if(r%2==1){
                v[n/2][0]='b';
                r--;
            }
            
            for(ll i=0; i<n&&r; i++){
                if(i%2==0){
                    v[i/2][0]='b';
                    r--;
                } else {
                    v[n-i/2-1][0]='b';
                    r--;
                }
            }

            // for(ll col=0; col<m; col++){
            //     v[0][col]='b';
            // }
        } else if(r==0){
            if(c%2==1){
                v[0][m/2]='b';
                c--;
            }
            
            for(ll col=0; col<m&&c; col++){
                if(col%2==0){
                    v[0][col/2]='b';
                } else {
                    v[0][m-col/2-1]='b';
                }
                c--;
            }
        } else {
            for(ll i=0; i<n&&r; i++){
                v[i][0]='b';
                r--;
            }
            
            for(ll col=0; col<m&&c; col++){
                v[0][col]='b';
                c--;
            }
        }

        if(tmpr==0&&tmpc==0){
            v[0][0]='c';
        }
    } else if(n%2==0&&m%2==0){
        if((r%2==1&&c==m)||(r==n&&c%2==1)){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        r=n-r;
        c=m-c;

        if(c==0){
            for(ll i=0; i<n&&r; i++){
                if(i%2==0){
                    v[i/2][0]='b';
                } else {
                    v[n-i/2-1][0]='b';
                }
                r--;
            }
        } if(r==0){
            for(ll col=0; col<m&&c; col++){
                if(col%2==0){
                    v[0][col/2]='b';
                } else {
                    v[0][m-col/2-1]='b';
                }
                c--;
            }
        } else {
            for(ll i=0; i<n&&r; i++){
                v[i][0]='b';
                r--;
            }

            for(ll col=0; col<m&&c; col++){
                v[0][col]='b';
                c--;
            }
        }

        if(tmpr==0&&tmpc==0){
            v[0][0]='c';
        }
    } else if(n%2==0&&m%2==1){
        if(r%2==1&&c==m){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        r=n-r;
        c=m-c;

        if(c==0){
            for(ll i=0; i<n&&r; i++){
                if(i%2==0){
                    v[i/2][0]='b';
                } else {
                    v[n-i/2-1][0]='b';
                }
                r--;
            }
        } else if(r==0){
            if(c%2==1){
                v[0][m/2]='b';
                c--;
            }

            for(ll col=0; col<m&&c; col++){
                if(col%2==0){
                    v[0][col/2]='b';
                } else {
                    v[0][m-col/2-1]='b';
                }
                c--;
            }
        } else {
            for(ll i=0; i<n&&r; i++){
                v[i][0]='b';
                r--;
            }
            for(ll col=0; col<m&&c; col++){
                v[0][col]='b';
                c--;
            }
        }

        if(tmpr==0&&tmpc==0){
            v[0][0]='c';
        }
    } else if(n%2==1&&m%2==0){
        if(r==n&&c%2==1){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        r=n-r;
        c=m-c;

        if(c==0){
            if(r%2==1){
                v[n/2][0]='b';
                r--;
            }

            for(ll i=0; i<n&&r; i++){
                if(i%2==0){
                    v[i/2][0]='b';
                } else {
                    v[n-i/2-1][0]='b';
                }
                r--;
            }
        } else if(r==0){
            for(ll col=0; col<m&&c; col++){
                if(col%2==0){
                    v[0][col/2]='b';
                } else {
                    v[0][m-col/2-1]='b';
                }
                c--;
            }
        } else {
            for(ll i=0; i<n&&r; i++){
                v[i][0]='b';
                r--;
            }
            for(ll col=0; col<m&&c; col++){
                v[0][col]='b';
                c--;
            }
        }

        if(tmpr==0&&tmpc==0){
            v[0][0]='c';
        }
    }

    if((tmpr==0&&tmpc<m)||(tmpr<n&&tmpc==0)){
        v[0][0]='c';
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}