#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    
    priority_queue<pair<ll, ll>>pq;
    map<ll, ll>m;
    ll n;
    cin>>n;
    while(n--){
        ll val;
        cin>>val;
        m[val]++;
    }
    for(auto i:m){
        pq.push(pair<ll, ll>(i.second, i.first));
    }

    vector<ll>greatestFreqVec;
    vector<ll>secondGreatestFreqVec;

    ll greatestFrequency = pq.top().first;
    
    while(true){
        if(pq.size()>0&&pq.top().first==greatestFrequency){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            greatestFreqVec.push_back(pq.top().second);
            pq.pop();
        } else {
            break;
        }
    }

    if(pq.size()==0){
        cout<<abs(greatestFreqVec[0]-greatestFreqVec.back())<<endl;
        return 0;
    }

    ll secondGreatestFrequency = pq.top().first;
    
    while(true){
        if(pq.size()>0&&pq.top().first==secondGreatestFrequency){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            secondGreatestFreqVec.push_back(pq.top().second);
            pq.pop();
        } else {
            break;
        }
    }

    // ll diffOne = abs(greatestFreqVec[0]-secondGreatestFreqVec[secondGreatestFreqVec.size()-1]);
    // ll diffTwo = abs(greatestFreqVec[greatestFreqVec.size()-1]-secondGreatestFreqVec[0]);

    // cout<<max(diffOne, diffTwo)<<endl;

    cout<<(abs(greatestFreqVec[0]-secondGreatestFreqVec[secondGreatestFreqVec.size()-1])>=abs(greatestFreqVec[greatestFreqVec.size()-1]-secondGreatestFreqVec[0])?abs(greatestFreqVec[0]-secondGreatestFreqVec[secondGreatestFreqVec.size()-1]):abs(greatestFreqVec[greatestFreqVec.size()-1]-secondGreatestFreqVec[0]))<<endl;

    for(auto i:greatestFreqVec){
        cout<<i<<" "<<endl;
    }
    cout<<endl;
    for(auto i:secondGreatestFreqVec){
        cout<<i<<" "<<endl;
    }
    cout<<endl;

}