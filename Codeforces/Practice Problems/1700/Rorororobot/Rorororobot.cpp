#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct RangeMaxQuery {
    ll n;
    vector<ll>segment_tree;
    vector<ll>arr;
    

    // constructor
    RangeMaxQuery(ll num_nodes, vector<ll>&v) {
        n=num_nodes;
        segment_tree.resize(2*pow(2, (ll)ceil(log2(n)))-1);
        arr=v;
        construct_segment_tree(0, n-1, 0);
    }


    // returns mid point of domain
    ll get_mid(ll a, ll b){
        return a+(b-a)/2;
    }


    // automatically called
    ll construct_segment_tree(ll l, ll r, ll i) {
        if(l==r){
            return segment_tree[i]=arr[l];
        }

        ll mid=get_mid(l, r);
        return segment_tree[i]=max(construct_segment_tree(l, mid, 2*i+1), construct_segment_tree(mid+1, r, 2*i+2));
    }


    // i --> the index of current node in segment tree
    // nl --> the left end of the domain covered by current node
    // nr --> the right end of the domain covered by current node
    // ql --> the left end of the domain of the query
    // qr --> the right end of the domain of the query
    ll _get_max(ll i, ll nl, ll nr, ll ql, ll qr){
        
        // entire node domain within range of query
        if(ql<=nl&&nr<=qr){
            return segment_tree[i];
        }

        // node domain out of range of query
        if(nr<ql||nl>qr){
            return 0;
        }

        // partial node domain in the range of query
        ll mid=get_mid(nl, nr);
        return max(_get_max(2*i+1, nl, mid, ql, qr), _get_max(2*i+2, mid+1, nr, ql, qr));
    }


    // Call this function to query the max of a range
    ll get_max(ll l, ll r){
        if(l>r){
            return -1;
        }
        
        if(l==r){
            return arr[l];
        }

        if(l<0||r<0||l>n-1||r>n-1){
            return -1;
        }

        return _get_max(0, 0, n-1, l, r);
    }


    // i --> index of current node
    // nl --> left end of domain covered by current node
    // nr --> right end of domain covered by current node
    // ind --> index to update
    // value --> new value
    ll _update(ll i, ll nl, ll nr, ll ind, ll val){

        // check if zoned onto one node
        if(ind==nl&&ind==nr){
            return segment_tree[i]=val;
        }
        
        // check if index of update is out of the domain of current node
        if(ind<nl||ind>nr){
            return segment_tree[i];
        }

        // update segment tree value
        ll mid=get_mid(nl, nr);
        return segment_tree[i]=max(_update(2*i+1, nl, mid, ind, val), _update(2*i+2, mid+1, nr, ind, val));
    }


    // Call this function to update an index 
    void update(ll ind, ll val){
        if(ind<0||ind>=n){
            return;
        }

        arr[ind]=val;

        _update(0, 0, n-1, ind, val);
    }
};

void solution(){
    ll n, m;
    cin>>n>>m;
    vector<ll>v(m);
    for(ll i=0; i<m; i++){
        cin>>v[i];
    }

    RangeMaxQuery rmq(m, v);
    ll q;
    cin>>q;
    while(q--){
        ll xs, ys, xp, yp, k;
        cin>>xs>>ys>>xp>>yp>>k;
        if(abs(xs-xp)%k!=0||abs(ys-yp)%k!=0){
            cout<<"NO"<<endl;
            continue;
        }

        if(ys==yp){
            cout<<"YES"<<endl;
            continue;
        } else if(yp<ys){
            swap(yp, ys);
        }
        ll max_wall=rmq.get_max(ys-1, yp-1);
        // printf("max_wall: %d\n", max_wall);
        if(n-max_wall>=(n-xs)%k+1){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}