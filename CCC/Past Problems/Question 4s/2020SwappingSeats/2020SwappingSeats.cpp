#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s;


struct section {
    ll num_a=0, num_b=0, num_c=0;
    void add(char letter){
        if(letter=='A'){
            num_a++;
        } else if(letter=='B'){
            num_b++;
        } else {
            num_c++;
        }
    }

    void remove(char letter){
        if(letter=='A'){
            num_a--;
        } else if(letter=='B'){
            num_b--;
        } else {
            num_c--;
        }
    }
};


ll count_ops(section as, section bs, section cs){
    return as.num_b+as.num_c+bs.num_a+bs.num_c-min(as.num_b, bs.num_a);
}


ll do_shit(string &s, ll n){
    section total;
    for(ll i=0; i<n; i++){
        total.add(s[i]);
    }

    section as, bs, cs;
    ll j=0;
    for(ll i=0; i<total.num_a; i++){
        as.add(s[j]);
        j++;
    }

    for(ll i=0; i<total.num_b; i++){
        bs.add(s[j]);
        j++;
    }

    for(ll i=0; i<total.num_c; i++){
        cs.add(s[j]);
        j++;
    }

    ll best=1e18;
    for(ll i=0; i<n; i++){
        best=min(best, count_ops(as, bs, cs));

        as.remove(s[i]);
        as.add(s[i+total.num_a]);

        bs.remove(s[i+total.num_a]);
        bs.add(s[i+total.num_a+total.num_b]);

        cs.remove(s[i+total.num_a+total.num_b]);
        cs.add(s[i+total.num_a+total.num_b+total.num_c]);
    }

    return best;
}


void solution(){
    cin>>s;
    n=s.length();
    s+=s;

    ll ans=1e18;

    ans=min(ans, do_shit(s, n));

    for(ll i=0; i<2*n; i++){
        if(s[i]=='A'){
            s[i]='C';
        } else if(s[i]=='C'){
            s[i]='A';
        }
    }

    ans=min(ans, do_shit(s, n));

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}