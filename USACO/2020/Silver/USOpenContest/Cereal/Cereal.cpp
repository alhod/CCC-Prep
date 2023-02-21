#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Cow {
    ll first_choice=-1, second_choice=-1, index=-1;
    Cow(ll a, ll b, ll c){
        first_choice=a;
        second_choice=b;
        index=c;
    }
};


ll n, m;
vector<bool>has_cereal;
vector<bool>removed;


ll add_cow_here(ll ind, vector<queue<Cow>>&v, vector<Cow>&cows){
    // cout<<"ind: "<<ind<<endl;
    ll ret=0;
    while(v[ind].size()>0){
        if(removed[v[ind].front().index]){
            v[ind].pop();
            continue;
        }

        if(v[ind].front().first_choice==ind){  // this is cow's first choice
            // cout<<"first choice"<<endl;
            if(has_cereal[v[ind].front().index]){  // currently chosing their second choice
                v[v[ind].front().second_choice].pop();
                ret+=add_cow_here(v[ind].front().second_choice, v, cows);
                break;
            } else {
                ret++;
                has_cereal[v[ind].front().index]=true;
                break;
            }
        } else {  // this is cows second choice
            // cout<<"second choice"<<endl;
            if(has_cereal[v[ind].front().index]){  // already secured their first choice
                v[ind].pop();
                continue;
            } else {
                ret++;
                has_cereal[v[ind].front().index]=true;
                break;
            }
        }
    }

    return ret;
}


void solution(){
    cin>>n>>m;

    vector<queue<Cow>>v(m);
    vector<Cow>cows;

    has_cereal.resize(n);
    removed.resize(n);

    // cout<<"aleud"<<endl;

    for(ll i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        Cow obj(x, y, i);
        v[x].push(obj);
        v[y].push(obj);
        cows.push_back(obj);
    }

    
    ll ans=0;
    
    
    for(ll i=0; i<n; i++){
        if(v[cows[i].first_choice].front().index==cows[i].index){
            ans++;
            has_cereal[cows[i].index]=true;
            if(v[cows[i].second_choice].front().index==cows[i].index){
                v[cows[i].second_choice].pop();
            }
        } else if(v[cows[i].second_choice].front().index==cows[i].index){
            ans++;
            has_cereal[cows[i].index]=true;
        } else {
            // fuck
        }
    }


    cout<<ans<<endl;

    // for(ll i=0; i<m; i++){
    //     cout<<v[i].front().index<<" ";
    // }    
    // cout<<endl;

    for(ll i=0; i<n-1; i++){
        
        // for(ll i=0; i<m; i++){
        //     cout<<v[i].front().index<<" ";
        // }
        // cout<<endl;


        removed[cows[i].index]=true;

        if(!has_cereal[cows[i].index]){
            cout<<ans<<endl;
            continue;
        }

        ans--;

        ll ind;
        if(v[cows[i].first_choice].front().index==cows[i].index){  // current cow secured first choice
            v[cows[i].first_choice].pop();
            ind=cows[i].first_choice;
        } else {  // current cow secured second choice
            v[cows[i].second_choice].pop();
            ind=cows[i].second_choice;
        } 
        // cout<<"i: "<<i<<endl;
        ans+=add_cow_here(ind, v, cows);


        cout<<ans<<endl;
    }


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("cereal.in", "r")) {
        freopen("cereal.in", "r", stdin);
        freopen("cereal.out", "w", stdout);
    }

    solution();
}