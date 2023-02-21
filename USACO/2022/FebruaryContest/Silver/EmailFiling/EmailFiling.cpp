#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll m, n, k;
    cin>>m>>n>>k;
    vector<ll>allEmails(n);
    vector<ll>countTotalEmails(m+1);
    vector<ll>emailsPresent(m+1);
    queue<ll>q;
    stack<ll>leftOverEmails;
    for(ll i=0; i<n; i++){
        cin>>allEmails[i];
        countTotalEmails[allEmails[i]]++;
        q.push(allEmails[i]);
    }

    // quick check
    for(ll i=0; i<n; i++){
        if(allEmails[i]>m){
            cout<<"NO"<<endl;
            return 0;
        }
    }


    for(ll i=0; i<k; i++){
        emailsPresent[allEmails[i]]++;
    }


    ll indFolders=1;
    while(q.size()>0){
        if(countTotalEmails[indFolders]==0){
            indFolders++;
            continue;
        }
        ll curr=q.front();
        q.pop();
        if(indFolders<=curr&&curr<indFolders+k){
            countTotalEmails[curr]--;
        } else {
            leftOverEmails.push(curr);
        }
    }
    

    while(true){
        if(leftOverEmails.size()==0){
            break;
        }

        ll curr=leftOverEmails.top();
        leftOverEmails.pop();

        if(indFolders<=curr&&curr<indFolders+k){
            continue;
        } else if(curr<indFolders){
            cout<<"NO"<<endl;
            return 0;
        } else {
            while(true){
                if(indFolders<=curr&&curr<indFolders+k){
                    break;
                }
                indFolders++;
            }
            continue;
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