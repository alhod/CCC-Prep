#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<pair<ll, ll>>v;


bool possible(ll d){
    ll ret=0;
    ll to_place=v[0].first;
    ll ind=0;
    // printf("d: %d\n", d);
    while(true){
        // printf("ind: %d, ret: %d, to_place: %d\n", ind, ret, to_place);

        if(ret==n){
            break;
        }

        while(to_place>v[ind].second){
            ind++;
            if(ind==m){
                return false;
            }

            to_place=max(to_place, v[ind].first);
        }

        ret++;
        to_place+=d;
    }

    return true;
}


void solution(){
    cin>>n>>m;
    v.resize(m);
    for(ll i=0; i<m; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end());

    ll l=1, r=v[m-1].second, mid, ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(possible(mid)){
            l=mid+1;
            ans=mid;
        } else {
            r=mid-1;
        }
    }
    

    cout<<ans<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("socdist.in", "r")) {
		freopen("socdist.in", "r", stdin);
		freopen("socdist.out", "w", stdout);
	}

    solution();
}