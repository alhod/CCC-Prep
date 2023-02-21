#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Card {
    ll w=0, i=0, n=0, ind;

    Card (ll ind){
        this->ind=ind;
    }

    void add_w(){
        w++;
    }
    void add_i(){
        i++;
    }
    void add_n(){
        n++;
    }
    void remove_w(){
        w--;
    }
    void remove_i(){
        i--;
    }
    void remove_n(){
        n--;
    }
};





void solution(){
    ll n;
    cin>>n;

    map<char, queue<Card>>m;
    
    for(ll i=0; i<n; i++){
        string card;
        cin>>card;
        Card obj(i);
        for(ll i=0; i<3; i++){
            if(card[i]=='w'){
                obj.add_w();
            } else if(card[i]=='i'){
                obj.add_i();
            } else {
                obj.add_n();
            }
        }

        if(obj.w>1){
            m['w'].push(obj);
        } else if(obj.i>1){
            m['i'].push(obj);
        } else if(obj.n>1){
            m['n'].push(obj);
        }
    }

    vector<tuple<ll, char, ll, char>>ans;

    for(char c:"win"){
        while(m[c].size()>0){
            Card curr=m[c].front();
            m[c].pop();
            if(curr.w==0){
                Card com=m['w'].front();
                if(c=='i'){
                    curr.i--;
                    curr.w++;
                    com.w--;
                    com.i++;
                    if(com.i>1){
                        m['w'].pop();
                        m['i'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'i', com.ind, c));
                } else if(c=='n'){
                    curr.n--;
                    curr.w++;
                    com.w--;
                    com.n++;
                    if(com.n>1){
                        m['w'].pop();
                        m['n'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'n', com.ind, c));
                }
            }

            if(curr.i==0){
                Card com=m['i'].front();
                if(c=='w'){
                    curr.w--;
                    curr.i++;
                    com.i--;
                    com.w++;
                    if(com.w>1){
                        m['i'].pop();
                        m['w'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'w', com.ind, c));
                } else if(c=='n'){
                    curr.n--;
                    curr.i++;
                    com.i--;
                    com.n++;
                    if(com.n>1){
                        m['i'].pop();
                        m['n'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'n', com.ind, c));
                }
            }

            if(curr.n==0){
                Card com=m['n'].front();
                if(c=='w'){
                    curr.w--;
                    curr.n++;
                    com.n--;
                    com.w++;
                    if(com.w>1){
                        m['n'].pop();
                        m['w'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'w', com.ind, c));
                } else if(c=='i'){
                    curr.i--;
                    curr.n++;
                    com.n--;
                    com.i++;
                    if(com.i>1){
                        m['n'].pop();
                        m['i'].push(com);
                    }
                    ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'i', com.ind, c));
                }
                
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        printf("%d %c %d %c\n", get<0>(i), get<1>(i), get<2>(i), get<3>(i));
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