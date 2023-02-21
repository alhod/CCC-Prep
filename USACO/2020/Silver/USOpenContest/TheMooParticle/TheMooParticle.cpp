#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Particle {
    ll min_x, max_x, min_y, max_y;
    Particle(ll a, ll b, ll c, ll d){
        this->min_x=a;
        this->min_x=b;
        this->min_y=c;
        this->max_y=d;
    }
};

bool operator<(Particle a, Particle b){
    if(a.min_x!=b.min_x){
        return a.min_x<b.min_x;
    } else {
        return a.min_y<b.min_y;
    }
}


void solution(){
    ll n;
    cin>>n;
    multiset<Particle>v;
    for(ll i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;
        v.insert(Particle(x, x, y, y));
    }


    multiset<Particle>::iterator iter=v.begin();
    while(v.size()>0){
        // printf("*iter: %d %d\n", (*iter).min_x, (*iter).min_y);

        Particle curr=*iter;
        if(next(iter)==v.end()){
            while(iter!=v.begin()){
                auto prev_iter=prev(iter);
                Particle prev_item=*prev_iter;
                if(prev_item.min_y<=curr.max_y){
                    curr.min_x=min(curr.min_x, prev_item.min_x);
                    curr.max_x=max(curr.max_x, prev_item.max_x);
                    curr.min_y=min(curr.min_y, prev_item.min_y);
                    curr.max_y=min(curr.max_y, prev_item.max_y);
                    v.erase(prev_iter);
                    v.erase(iter);
                    iter=v.insert(curr);
                } else {
                    break;
                }
            }

            break;
        }

        
        auto next_iter=next(iter);
        // printf("%d %d, %d %d\n", curr.min_x, curr.min_y, (*next_iter).min_x, (*next_iter).min_y);
        Particle next_item=*next_iter;
        if(next_item.max_y>=curr.min_y){
            curr.min_x=min(curr.min_x, next_item.min_x);
            curr.max_x=max(curr.max_x, next_item.max_x);
            curr.min_y=min(curr.min_y, next_item.min_y);
            curr.max_y=max(curr.max_y, next_item.max_y);
            v.erase(iter);
            v.erase(next_iter);
            iter=v.insert(curr);
            while(iter!=v.begin()){
                auto prev_iter=prev(iter);
                Particle prev_item=*prev_iter;
                if(prev_item.min_y<=curr.max_y){
                    curr.min_x=min(curr.min_x, prev_item.min_x);
                    curr.max_x=max(curr.max_x, prev_item.max_x);
                    curr.min_y=min(curr.min_y, prev_item.min_y);
                    curr.max_y=max(curr.max_y, prev_item.max_y);
                    v.erase(prev_iter);
                    v.erase(iter);
                    iter=v.insert(curr);
                } else {
                    break;
                }
            }
            
        } else {
            iter=next_iter;
        }
    }

    // for(auto i:v){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    cout<<v.size()<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("moop.in", "r")) {
        freopen("moop.in", "r", stdin);
        freopen("moop.out", "w", stdout);
    }

    solution();
}