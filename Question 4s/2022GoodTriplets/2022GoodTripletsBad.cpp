#include<bits/stdc++.h>
#define ll long long
using namespace std;


// void solution(){
//     ll n, c;
//     cin>>n>>c;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     vector<ll>points(10000500);
//     for(ll i=0; i<n; i++){
//         points[v[i]]++;
//     }

//     ll ans=0;


//     if(c%2==0){
//         for(ll i=0; i<n; i++){
//             if(v[i]>=c/2){
//                 continue;
//             }
//             for(ll j=i+1; j<n; j++){
//                 if(v[j]>=(i+c/2)||v[j]<i+1){
//                     continue;
//                 }
//                 for(ll k=j+1; k<n; k++){
//                     if(v[k]>=(j+c/2)||v[k]<(i+c/2)+1){
//                         continue;
//                     }

//                     ans++;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     } else {
//         for(ll i=0; i<n; i++){
//             if(v[i]>=(c+1)/2){
//                 continue;
//             }
//             for(ll j=i+1; j<n; j++){
//                 if(v[j]>=(i+(c+1)/2)){
//                     continue;
//                 }
//                 for(ll k=j+1; k<n; k++){
//                     if(v[k]>=(j+(c+1)/2)){
//                         continue;
//                     }
//                     ans++;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }
    
// }

void solution(){
    ll n, c;
    cin>>n>>c;
    vector<ll>v(1000050, 0);
    vector<ll>points;
    map<ll, ll>pointToCount;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v[x]++;
        if(!pointToCount[x]){
            points.push_back(x);
        }
        pointToCount[x]++;
    }

    sort(points.begin(), points.end());

    for(ll i=1; i<1000050; i++){
        v[i]+=v[i-1];
    }

    // for(ll i=0; i<=c; i++){
        // cout<<v[i]<<" ";
    // }
    // cout<<endl;

    ll initialSum=0;
    ll pre1, pre2;
    for(ll j=1; j<points.size()&&points[j]<=(c+1)/2+points[0]-1; j++){
        
        if(points[j]+(c+1)/2-1>=c){
            pre1=v[c];//+v[(points[j]+c/2-1)%c];
        } else {
            pre1=v[(points[j]+(c+1)/2-1)%c];
        }

        if(points[0]+c/2>=c){
            pre2=v[c];
        } else {
            pre2=v[points[0]+c/2];
        }
        initialSum+=pointToCount[points[0]]*pointToCount[points[j]]*(pre1-pre2);
        // printf("points[i], points[j]: %d, %d\n", points[0], points[j]);
        // printf("%d %d %d %d %d\n", pointToCount[points[0]], pointToCount[points[j]], pre1, pre2, pre1-pre2);
        // printf("Adding: %d\n", pointToCount[points[0]]*pointToCount[points[j]]*(pre1-pre2));
    }

    // printf("Initial Sum %d\n", initialSum);


    ll ans=initialSum;

    for(ll i=1; i<points.size()&&points[i]<=(c-1)/2; i++){
        // if(points[i]+(c+1)/2-1>=c){
        //     pre1=v[c];//+v[(points[j]+c/2-1)%c];
        // } else {
        //     pre1=v[points[i]+(c+1)/2-1];
        // }

        // if(points[i-1]+c/2>=c){  // should me impossible
        //     pre2=v[c];
        // } else {
        //     pre2=v[points[i-1]+c/2-1];
        // }
        
        ll numSecondPointsToSubtract=v[points[i-1]+(c+1)/2-1]-v[points[i]-1]+pointToCount[v[points[i]+(c+1)/2]];
        ll countOfFirstPoint=pointToCount[points[i-1]];
        ll numThirdPointsToSubtract=v[points[i]+(c+1)/2]-v[points[i-1]+(c)/2];
        // printf("Subtracting: %d %d %d %d %d %d\n", v[points[i-1]+(c+1)/2-1], v[points[i]-1], pointToCount[points[i-1]], v[points[i]+(c+1)/2], v[points[i-1]+(c+1)/2], (numSecondPointsToSubtract)*(countOfFirstPoint)*(numThirdPointsToSubtract));
        // printf("%d %d %d %d %d %d\n", initialSum, points[i], points[i-1], v[points[i]+(c+1)/2-1], v[points[i-1]+(c+1)/2-1], v[c]-v[points[i]+(c+1)/2]);
        
        initialSum-=(numSecondPointsToSubtract)*(countOfFirstPoint)*(numThirdPointsToSubtract);
        initialSum+=(v[points[i]+(c+1)/2-1]-v[points[i-1]+(c+1)/2-1])*(v[c]-v[points[i]+(c+1)/2]);
        ans+=initialSum;
    }

    // for(ll i=0; i<points.size()&&points[i]<=(c-1)/2; i++){
    //     for(ll j=i+1; j<points.size()&&points[j]<=(c+1)/2+points[i]-1; j++){
    //         ans+=initialSum;
    //         initialSum-=v[points[i]+(c+1)/2-1]-v[points[i]]*pointToCount[points[i+1]];


    //         // ll pre1;
    //         // // printf("v[c], v[(points[j]+(c+1)/2-1)mod c], %d %d\n", v[c], v[(points[j]+(c+1)/2-1)%c]);
    //         // if(points[j]+(c+1)/2-1>=c){
    //         //     pre1=v[c];//+v[(points[j]+c/2-1)%c];
    //         // } else {
    //         //     pre1=v[(points[j]+(c+1)/2-1)%c];
    //         // }

    //         // ll pre2;
    //         // if(points[i]+c/2>=c){
    //         //     pre2=v[c];
    //         // } else {
    //         //     pre2=v[points[i]+c/2];
    //         // }
    //         // ans+=pointToCount[points[i]]*pointToCount[points[j]]*(pre1-pre2);
    //         // // printf("points[i], points[j]: %d, %d\n", points[i], points[j]);
    //         // // printf("%d %d %d %d %d\n", pointToCount[points[i]], pointToCount[points[j]], pre1, pre2, pre1-pre2);
    //         // // printf("Adding: %d\n", pointToCount[points[i]]*pointToCount[points[j]]*(pre1-pre2));
    //     }
    // }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}