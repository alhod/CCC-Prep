#include<bits/stdc++.h>
#define ll long long
using namespace std;


// int solution(){
//     ll n, x, y;
//     cin>>n>>x>>y;
//     vector<ll>v;
//     v.push_back(n);
//     v.push_back(x);
//     v.push_back(y);
//     ll smallest=1e18;
//     ll smallestInd=-1;
//     for(ll i=0; i<3; i++){
//         if(v[i]<smallest){
//             smallest=v[i];
//             smallestInd=i;
//         }
//     }

//     v.erase(v.begin()+smallestInd);
    
//     ll greatest=-1;
//     ll greatestInd=-1;

//     for(ll i=0; i<2; i++){
//         if(v[i]>greatest){
//             greatest=v[i];
//             greatestInd=i;
//         }
//     }

//     v.erase(v.begin()+greatestInd);

//     cout<<v[0]<<endl;
    
//     return 0;
// }





// int solution(){
//     ll n;
//     cin>>n;
//     string s;
//     cin>>s;
//     ll greatest=-1;
//     for(ll i=0; i<n; i++){
//         greatest=max(greatest, (ll)s[i]-96);
//     }

//     cout<<greatest<<endl;
//     return 0;
// }



// int solution(){
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     ll greatest=-1;
//     ll greatestInd=-1;
//     for(ll i=0; i<n; i++){
//         if(v[i]>greatest){
//             greatest=v[i];
//             greatestInd=i;
//         }
//     }

//     ll secondGreatest=-1;
//     ll secondGreatestInd=-1;

//     for(ll i=0; i<n; i++){
//         if(v[i]>secondGreatest&&i!=greatestInd){
//             secondGreatest=v[i];
//             secondGreatestInd=i;
//         }
//     }

//     vector<ll>ans(n);

//     for(ll i=0; i<n; i++){
//         if(i==greatestInd){
//             ans[i]=greatest-secondGreatest;
//         } else {
//             ans[i]=v[i]-greatest;
//         }
//     }

//     for(auto i:ans){
//         cout<<i<<" ";
//     }
//     cout<<endl; 


//     return 0;
// }




// int solution(){
    
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     if(n==1){
//         cout<<"YES"<<endl;
//         return 0;
//     }

//     ll count=0;

//     bool leftGreat=true;
//     for(ll i=0; i<n; i++){
//         if(i==n-1&&leftGreat==true){
//             count++;
//         } else if(leftGreat==true&&v[i]<v[i+1]){
//             count++;
//             leftGreat=false;
//         } else if(v[i]==v[i+1]){
//             continue;
//         } else if(v[i]>v[i+1]){
//             leftGreat=true;
//         }
//     }

//     cout<<(count==1?"YES":"NO")<<endl;
    
    
//     return 0;
// }




// int solution(){
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     vector<ll>zerosAfter(n+2);
//     vector<ll>onesBefore(n+2);
//     for(ll i=0; i<n; i++){
//         if(i==0&&v[i]==1){
//             onesBefore[i+1]=1;
//         } else {
//             onesBefore[i+1]=onesBefore[i];
//             if(v[i]==1){
//                 onesBefore[i+1]++;
//             }
//         }
//     }

//     for(ll i=n-1; i>=0; i--){
//         if(i==n-1&&v[i]==0){
//             zerosAfter[i+1]=1;
//         } else {
//             zerosAfter[i+1]=zerosAfter[i+2];
//             if(v[i]==0){
//                 zerosAfter[i+1]++;
//             }
//         }
//     }

//     ll best=0;

//     for(ll i=0; i<n-1; i++){
//         if(v[i]==1){
//             best+=zerosAfter[i+2];
//         }
//     }

//     ll newBest=best;

//     for(ll i=1; i<n+1; i++){
//         if(v[i-1]==1){
//             if(onesBefore[i-1]-zerosAfter[i+1]>0){
//                 newBest=max(newBest, best+(onesBefore[i-1]-zerosAfter[i+1]));
//             }
//         } else {
//             if(zerosAfter[i+1]-onesBefore[i-1]>0){
//                 newBest=max(newBest, best+(zerosAfter[i+1]-onesBefore[i-1]));
//             }
//         }
//     }

//     cout<<newBest<<endl;

//     return 0;
// }


// bool possible(ll c, ll d, ll k, vector<ll>&v){
//     queue<ll>q;
//     priority_queue<ll>pq;
//     ll initDays=k;
//     ll days=1;
//     for(ll i=0; i<v.size(); i++){
//         pq.push(v[i]);
//     }

//     while(days<=d){
//         if(pq.size()>0){
//             c-=pq.top();
//             q.push(pq.top());
//             pq.pop();
//         }
//         if(initDays==0){
//             pq.push(q.front());
//             q.pop();
//         } else {
//             initDays--;
//         }

//         days++;
//     }

//     if(c<=0){
//         return true;
//     } else {
//         return false;
//     }
// }







// bool possible(ll c, ll d, ll k, vector<ll>&v){
//     ll days=1;
//     ll ind=0;
//     ll cycle=k+1;
//     while(days<=d){
//         if(cycle==0){
//             ind=0;
//             cycle=k+1;
//         }
//         if(ind<v.size()){
//             c-=v[ind];
//             ind++;
//         }
//         cycle--;
//         days++;
//     }
//     if(c<=0){
//         return true;
//     } else {
//         return false;
//     }
// }


// int solution(){

//     ll n, c, d;
//     cin>>n>>c>>d;
//     vector<ll>v(n);
//     for(ll i=0; i<n; i++){
//         cin>>v[i];
//     }

//     ll sum=0;
//     sort(v.begin(), v.end(), greater<ll>());
//     for(ll i=0; i<n&&i<d; i++){
//         sum+=v[i];
//     }
//     if(sum>=c){
//         cout<<"Infinity"<<endl;
//         return 0;
//     }

//     ll greatest=-1;
//     for(ll i=0; i<n; i++){
//         greatest=max(greatest, v[i]);
//     }
//     if(greatest*d<c){
//         cout<<"Impossible"<<endl;
//         return 0;
//     }

//     ll left=0;
//     ll right=d;
//     ll ans=0;
//     while(left<=right){
//         ll mid=(left+right)/2;
//         if(possible(c, d, mid, v)){
//             left=mid+1;
//             ans=mid;
//         } else {
//             right=mid-1;
//         }
//     }

//     cout<<ans<<endl;

//     return 0;
// }




// bool dfsEnd(ll curr, ll currVal, ll prev, ll end, map<ll, vector<pair<ll, ll>>>&m, vector<ll>&seen){
//     if(currVal==-1){
//         currVal=0;
//     } else {
//         seen[currVal]=1;
//     }
//     for(auto i:m[curr]){
//         if(i.first==end){
//             if((currVal^i.second)==0){
//                 return true;
//             } else {
//                 continue;
//             }
//         }
//         if(i.first==prev){
//             continue;
//         } else {
//             if(dfsEnd(i.first, currVal^i.second, curr, end, m, seen)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool dfsStart(ll curr, ll currVal, ll prev, ll end, map<ll, vector<pair<ll, ll>>>&m, vector<ll>&seen){
//     if(currVal==-1){
//         currVal=0;
//     } else if (seen[currVal]==1){
//         return true;
//     }
//     for(auto i:m[curr]){
//         if(i.first==end){
//             if((currVal^i.second)==0){
//                 return true;
//             } else {
//                 continue;
//             }
//         }
//         if(i.first==prev){
//             continue;
//         } else {
//             if(dfsStart(i.first, currVal^i.second, curr, end, m, seen)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }


// int solution(){
//     ll n, a, b;
//     cin>>n>>a>>b;
//     map<ll, vector<pair<ll, ll>>>m;
//     for(ll i=0; i<n-1; i++){
//         ll x, y, w;
//         cin>>x>>y>>w;
//         m[x].push_back(pair<ll, ll>(y, w));
//         m[y].push_back(pair<ll, ll>(x, w));
//     }

//     vector<ll>seen(100000);
//     if(dfsEnd(b, -1, b, a, m, seen)){
//         cout<<"YES"<<endl;
//         return 0;
//     }

//     if(dfsStart(a, 0, a, b, m, seen)){
//         cout<<"YES"<<endl;
//     } else {
//         cout<<"NO"<<endl;
//     }

//     return 0;   
// }


ll dfs(ll curr, ll end, map<ll, vector<pair<ll, ll>>>&m, vector<ll>&xorVal){
    for(auto i:m[curr]){
        if(i.first==end){
            continue;
        } else if (xorVal[i.first]==-1){
            xorVal[i.first]=(xorVal[curr]^i.second);
            dfs(i.first, end, m, xorVal);
        }
    }
    return 0;
}


int solution(){
    ll n, a, b;
    cin>>n>>a>>b;
    //vector<vector<pair<ll, ll>>>m(n);
    map<ll, vector<pair<ll, ll>>>m;
    for(ll i=0; i<n-1; i++){
        ll x, y, w;
        cin>>x>>y>>w;
        x--;
        y--;
        m[x].emplace_back(y, w);
        m[y].emplace_back(x, w);
    }
    a--;
    b--;
    vector<ll>xorVal(n, -1);
    vector<ll>xorVal2(n, -1);

    xorVal[a]=0;
    xorVal2[b]=0;

    dfs(a, b, m, xorVal);
    dfs(b, -1, m, xorVal2);
    sort(xorVal.begin(), xorVal.end());

    for(ll i=0; i<n; i++){
        if(i!=b&&xorVal2[i]!=-1){
            auto binSearch=lower_bound(xorVal.begin(), xorVal.end(), xorVal2[i]);
            if(*binSearch==xorVal2[i]&&binSearch!=xorVal.end()){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

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