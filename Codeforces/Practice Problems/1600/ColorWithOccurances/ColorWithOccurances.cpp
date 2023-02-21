#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<pair<ll, ll>>ans;
string s;
ll n, m;
vector<string>v;


ll recurse(ll indStart, ll indEnd){
    // printf("indStart, indEnd: %d %d\n", indStart, indEnd);
    ll best=-1, bestInd, bestPos;
    for(ll i=indStart; i<=indEnd; i++){
        for(ll j=0; j<m; j++){
            if(v[j].length()+i>s.length()){
                continue;
            } else if(v[j].length()+i-1<indEnd){
                continue;
            }

            bool match=true;
            for(ll x=0; x<v[j].length(); x++){
                if(v[j][x]!=s[x+i]){
                    match=false;
                }
            }
            if(match){
                if(i+(ll)v[j].length()-1>best){
                    best=i+v[j].length()-1;
                    bestInd=j+1;
                    bestPos=i+1;
                }
            }
        }
    }
    

    ans.push_back(pair<ll, ll>(bestInd, bestPos));

    return best;
}



void solution(){
    ans.clear();
    cin>>s;
    n=s.length();
    cin>>m;
    v.resize(m);
    for(ll i=0; i<m; i++){
        cin>>v[i];
    }

    ll l=0, r=0;
    while(true){
        ll newStart=recurse(l, r);
        // printf("newStart: %d\n", newStart);
        if(newStart==-1){
            cout<<-1<<endl;
            return;
        } else if(newStart==s.length()-1){
            break;
        }

        if(l==0){
            l=1;
        } else {
            l=r+1;
        }
        if(r==0){
            r=newStart+1;
        } else {
            r=newStart+1;
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }




    
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