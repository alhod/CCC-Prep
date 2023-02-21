#include<bits/stdc++.h>
#define ll long long
using namespace std;


// int solution(){
//     string s;
//     cin>>s;

//     bool imp=false;
//     bool imp2=false;
//     bool imp3=false;

//     for(ll i=0; i<s.length(); i++){
//         if(i%3==0){
//             if(s[i]!='Y'){
//                 imp=true;
//                 break;
//             }
//         } else if(i%3==1){
//             if(s[i]!='e'){
//                 imp=true;
//                 break;
//             }
//         } else if(i%3==2){
//             if(s[i]!='s'){
//                 imp=true;
//                 break;
//             }
//         }
//     }

//     for(ll i=0; i<s.length(); i++){
//         if(i%3==0){
//             if(s[i]!='e'){
//                 imp2=true;
//                 break;
//             }
//         } else if(i%3==1){
//             if(s[i]!='s'){
//                 imp2=true;
//                 break;
//             }
//         } else if(i%3==2){
//             if(s[i]!='Y'){
//                 imp2=true;
//                 break;
//             }
//         }
//     }
    
//     for(ll i=0; i<s.length(); i++){
//         if(i%3==0){
//             if(s[i]!='s'){
//                 imp3=true;
//                 break;
//             }
//         } else if(i%3==1){
//             if(s[i]!='Y'){
//                 imp3=true;
//                 break;
//             }
//         } else if(i%3==2){
//             if(s[i]!='e'){
//                 imp3=true;
//                 break;
//             }
//         }
//     }

//     if(!imp||!imp2||!imp3){
//         cout<<"YES"<<endl;
//     } else {
//         cout<<"NO"<<endl;
//     }

//     return 0;
// }


// int solution(){
//     ll m;
//     ll s;
//     cin>>m>>s;
//     vector<ll>v(m);
//     vector<ll>cnt(10000);
//     for(ll i=0; i<m; i++){
//         cin>>v[i];
//         cnt[v[i]]++;
//     }

//     for(ll i=0; i<60; i++){
//         if(cnt[i]>1){
//             cout<<"NO"<<endl;
//             return 0;
//         }
//     }

//     ll sum=0;
//     ll num=1;

//     while(true){
//         if(sum==s){

//             ll maxElement=0;
//             for(auto i:v){
//                 maxElement=max(maxElement, i);
//             }

//             if(v.size()==maxElement){
//                 cout<<"YES"<<endl;
//             } else {
//                 cout<<"NO"<<endl;
//             }
//             return 0;
//         } else if(sum>s){
//             cout<<"NO"<<endl;
//             return 0;
//         } else {
//             while(cnt[num]>0){
//                 num++;
//             }
//             sum+=num;
//             v.push_back(num);
//             num++;
//         }
//     }

//     return 0;


// }


// int solution(){
//     ll l, r, x, a, b;
//     cin>>l>>r>>x>>a>>b;
//     if(a==b){
//         cout<<0<<endl;
//         return 0;
//     }
//     if(abs(a-l)<x&&abs(a-r)<x){
//         cout<<-1<<endl;
//         return 0;
//     }
//     if(abs(b-l)<x&&abs(b-r)<x){
//         cout<<-1<<endl;
//         return 0;
//     }
//     if(abs(a-b)>=x){
//         cout<<1<<endl;
//         return 0;
//     }
//     if(max(a,b)+x<=r){
//         cout<<2<<endl;
//         return 0;
//     }
//     if(min(a,b)-x>=l){
//         cout<<2<<endl;
//         return 0;
//     }
//     cout<<3<<endl;
//     return 0;

// }



int solution(){
    ll n, h;
    cin>>n>>h;
    vector<ll>v(n);
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        pq.push(v[i]);
    }

    ll green=2;
    ll blue=1;
    ll count=0;

    while(pq.size()>0){
        if(pq.top()<h){
            h+=pq.top()/2;
            pq.pop();
            count++;
        } else {
            if(pq.top()<h*2&&green>0){
                h*=2;
                h+=pq.top()/2;
                pq.pop();
                count++;
            } else if(pq.top()<h*3&&blue==1){
                h*=3;
                h+=pq.top()/2;
                pq.pop();
                count++;
            } else if(pq.top()<h*4&&green==2){
                h*=4;
                h+=pq.top()/2;
                pq.pop();
                count++;
            } else if(pq.top()<h*6&&green>0&&blue==1){
                h*=6;
                h+=pq.top()/2;
                pq.pop();
                count++;
            } else if(pq.top()<h*12&&green==2&&blue==1){
                h*=12;
                h+=pq.top()/2;
                pq.pop();
                count++;
            } else {
                break;
            }
        }
    }

    cout<<count<<endl;


    return 0;


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