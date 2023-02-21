#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll m, n, k;
    cin>>m>>n>>k;
    vector<ll>emails(n);
    vector<ll>countEmails(m+1);
    for(auto &i:emails){
        cin>>i;
        countEmails[i]++;
    }

    ll top=1;
    ll indEmails=0;
    stack<ll>skipped;

    while(indEmails<n){
        while(countEmails[top]==0){
            top++;
        }

        if(top<=emails[indEmails]&&emails[indEmails]<top+k){
            countEmails[emails[indEmails]]--;
        } else {
            skipped.push(emails[indEmails]);
        }

        indEmails++;
    }


    vector<ll>scroll;
    for(ll i=0; i<k&&i<skipped.size(); i++){
        scroll.push_back(skipped.top());
        skipped.pop();
    }
    while(skipped.size()>0&&scroll.size()>0){
        bool erased=false;
        while(countEmails[top]==0){
            top++;
        }
        for(ll i=0; i<scroll.size(); i++){
            if(scroll[i]<top){
                cout<<"NO"<<endl;
                return 0;
            } else if(top<=scroll[i]&&scroll[i]<top+k){
                scroll.erase(scroll.begin()+i);
                if(skipped.size()!=0){
                    scroll.push_back(skipped.top());
                    skipped.pop();
                }
                i--;
                erased=true;
            }
        }
        if(erased==false){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;



    
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