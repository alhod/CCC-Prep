// Time Complexity: O(nlog(n))
// Space Complexity: O(n)

// Range Sum Query:
//      Should support fast query of the sum of values within a given range.
//      Should support fast update of values.

// Segmented Tree:
//      Range Sum Query (RSQ, as well as other range query problems) can be implemented using a segmented tree.
//      A segmented tree is a Full Binary Tree (each node has either two children or zero children) represented 
//      in an array, in which for a node at index i, the left child is at index 2i+1 and the right at 2i+2, its 
//      parent is floor((i-1)/2) and the root node is indexed at 0.
//      The array is represented by the leaf nodes of the segmented tree, while the internal nodes the merging
//      of the leaf nodes (in which sum, max, min, etc. is taken).
//      Note that it is a Full Binary Tree and there are n nodes, there is a total of 2*n-1 nodes, thus that is
//      the size of the array used to store the segmented tree.

// How to use:
//      Create instance of RangeSumQuery struct by doing "RangeSumQuery obj(n, v)" where n is the number of nodes
//      and v is the array.
//      Call "obj.get_sum(l, r)" to query the sum of all values in the array within the domain [l, r].
//      Call "obj.update(ind, val)" to update the array at index "ind" to value "val.""


#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct RangeSumQuery {
    ll n;
    vector<ll>segment_tree;
    vector<ll>arr;
    

    // constructor
    RangeSumQuery(ll num_nodes, vector<ll>&v) {
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
        return segment_tree[i]=construct_segment_tree(l, mid, 2*i+1)+construct_segment_tree(mid+1, r, 2*i+2);
    }


    // i --> the index of current node in segment tree
    // nl --> the left end of the domain covered by current node
    // nr --> the right end of the domain covered by current node
    // ql --> the left end of the domain of the query
    // qr --> the right end of the domain of the query
    ll _get_sum(ll i, ll nl, ll nr, ll ql, ll qr){
        
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
        return _get_sum(2*i+1, nl, mid, ql, qr)+_get_sum(2*i+2, mid+1, nr, ql, qr);
    }


    // Call this function to query the sum of a range
    ll get_sum(ll l, ll r){
        if(l>r){
            return -1;
        }
        
        if(l==r){
            return arr[l];
        }

        if(l<0||r<0||l>n-1||r>n-1){
            return -1;
        }

        return _get_sum(0, 0, n-1, l, r);
    }


    // i --> index of current node
    // nl --> left end of domain covered by current node
    // nr --> right end of domain covered by current node
    // ind --> index to update
    // diff --> value to add to each domain that ind falls under
    void _update(ll i, ll nl, ll nr, ll ind, ll diff){

        // check if zoned onto one node
        if(nl==nr){
            segment_tree[i]+=diff;
            return;
        }
        
        // check if index of update is out of the domain of current node
        if(ind<nl||ind>nr){
            return;
        }

        // update segment tree value
        segment_tree[i]+=diff;
        ll mid=get_mid(nl, nr);
        _update(2*i+1, nl, mid, ind, diff);
        _update(2*i+2, mid+1, nr, ind, diff);
    }


    // Call this function to update an index 
    void update(ll ind, ll val){
        if(ind<0||ind>=n){
            return;
        }

        ll diff=val-arr[ind];
        arr[ind]=val;

        _update(0, 0, n-1, ind, diff);
    }
};




void solution(){
    ll n, q;
    cin>>n>>q;
    
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    RangeSumQuery rsq(n, v);
    
    while(q--){
        ll l, r;
        cin>>l>>r;
        cout<<rsq.get_sum(l, r)<<endl;

        ll ind, val;
        cin>>ind>>val;
        rsq.update(ind, val);
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}