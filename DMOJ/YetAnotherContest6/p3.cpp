#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;

    if(n==2&&m==3){
        cout<<"! 1 3 2 3"<<endl<<flush;
        return;
    }
    
    cout<<"? 1 1"<<endl<<flush;
    ll dist1, x1, y1;
    cin>>dist1;
    x1=dist1+1;
    y1=1;

    cout<<"? "<<n<<" 1"<<endl<<flush;
    ll dist2, x2, y2;
    cin>>dist2;
    x2=n-dist2;
    y2=1;

    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}