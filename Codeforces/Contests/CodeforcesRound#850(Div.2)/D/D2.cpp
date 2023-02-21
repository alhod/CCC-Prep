#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Card_w {
    ll w=0, i=0, n=0, ind;
    Card_w (ll ind){
        this->ind=ind;
    }
};

struct Card_i {
    ll w=0, i=0, n=0, ind;
    Card_i (ll ind){
        this->ind=ind;
    }
};

struct Card_n {
    ll w=0, i=0, n=0, ind;
    Card_n (ll ind){
        this->ind=ind;
    }
};

bool operator < (Card_w a, Card_w b){
    return a.w<b.w;
}

bool operator < (Card_i a, Card_i b){
    return a.i<b.i;
}

bool operator < (Card_n a, Card_n b){
    return a.n<b.n;
}





void solution(){
    ll n;
    cin>>n;

    priority_queue<Card_w>pqw;
    priority_queue<Card_i>pqi;
    priority_queue<Card_n>pqn;
    
    for(ll x=0; x<n; x++){
        string card;
        cin>>card;
        ll num_w=0, num_i=0, num_n=0;
        for(ll y=0; y<3; y++){
            if(card[y]=='w'){
                num_w++;
            } else if(card[y]=='i'){
                num_i++;
            } else {
                num_n++;
            }
        }

        if(num_w>1){
            Card_w obj(x);
            obj.w=num_w;
            obj.i=num_i;
            obj.n=num_n;
            pqw.push(obj);
        } else if(num_i>1){
            Card_i obj(x);
            obj.w=num_w;
            obj.i=num_i;
            obj.n=num_n;
            pqi.push(obj);
        } else if(n>1){
            Card_n obj(x);
            obj.w=num_w;
            obj.i=num_i;
            obj.n=num_n;
            pqn.push(obj);
        }
    }

    vector<tuple<ll, char, ll, char>>ans;

    while(pqw.size()>0){
        cout<<"sec 1"<<endl;
        Card_w curr=pqw.top();
        pqw.pop();
        printf("curr(w): %d %d %d %d\n", curr.w, curr.i, curr.n, curr.ind);

        if(curr.i==0){
            Card_i com=pqi.top();
            pqi.pop();

            printf("com(i): %d %d %d %d\n", com.w, com.i, com.n, com.ind);

            curr.w--;
            curr.i++;
            com.i--;
            com.w++;

            if(com.i>1){
                pqi.push(com);
            } else if(com.w>1){
                Card_w obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqw.push(obj);
            }

            
            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'w', com.ind, 'i'));
        }
        if(curr.n==0){
            Card_n com=pqn.top();
            pqn.pop();
            printf("com(n): %d %d %d %d\n", com.w, com.i, com.n, com.ind);
            curr.w--;
            curr.n++;
            com.n--;
            com.w++;

            if(com.n>1){
                pqn.push(com);
            } else if(com.w>1){
                Card_w obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqw.push(obj);
            }

            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'w', com.ind, 'n'));
        }
    }

    while(pqi.size()>0){
        cout<<"sec 2"<<endl;
        Card_i curr=pqi.top();
        pqi.pop();

        if(curr.w==0){
            Card_w com=pqw.top();
            pqw.pop();

            curr.i--;
            curr.w++;
            com.w--;
            com.i++;

            if(com.w>1){
                pqw.push(com);
            } else if(com.i>1){
                Card_i obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqi.push(obj);
            }

            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'i', com.ind, 'w'));
        }
        if(curr.n==0){
            Card_n com=pqn.top();
            pqn.pop();

            curr.i--;
            curr.n++;
            com.n--;
            com.i++;

            if(com.n>1){
                pqn.push(com);
            } else if(com.i>1){
                Card_i obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqi.push(obj);
            }

            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'i', com.ind, 'n'));
        }
    }

    while(pqn.size()>0){
        cout<<"sec 3"<<endl;
        Card_n curr=pqn.top();
        pqn.pop();

        if(curr.w==0){
            Card_w com=pqw.top();
            pqw.pop();

            curr.n--;
            curr.w++;
            com.w--;
            com.n++;

            if(com.w>1){
                pqw.push(com);
            } else if(com.n>1){
                Card_n obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqn.push(obj);
            }

            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'n', com.ind, 'w'));
        }
        if(curr.i==0){
            Card_i com=pqi.top();
            pqi.pop();

            curr.n--;
            curr.i++;
            com.i--;
            com.i++;

            if(com.i>1){
                pqi.push(com);
            } else if(com.n>1){
                Card_n obj(com.ind);
                obj.w=com.w;
                obj.i=com.i;
                obj.n=com.n;
                pqn.push(obj);
            }

            ans.push_back(tuple<ll, char, ll, char>(curr.ind, 'n', com.ind, 'i'));
        }
    }

    printf("%d\n", ans.size());
    for(auto i:ans){
        printf("%d %c %d %c\n", get<0>(i)+1, get<1>(i), get<2>(i)+1, get<3>(i));
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