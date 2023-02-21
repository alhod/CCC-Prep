#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solutionA(){
    ll n, a, b;
    cin>>n>>a>>b;
    if(n==a&&n==b){
        cout<<"Yes"<<endl;
        return 0;
    }

    if(n-a-b>=2){
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;

    return 0;
}




bool checkAllEq(vector<ll>&v){
    for(ll i=0; i<v.size(); i++){
        if(i==0){
            if(v[v.size()-1]!=v[1]){
                return false;
            }
        } else if(i==v.size()-1){
            if(v[i-1]!=v[0]){
                return false;
            }
        } else if(v[i-1]!=v[i+1]){
            return false;
        }
    }

    return true;
}



int solutionB(){


    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    if(n==1||n==2||n==3){
        cout<<n<<endl;
        return 0;
    }
    ll count=0;

    for(ll i=0; i<n; i++){
        bool erased=false;
        vector<ll>best;
        vector<ll>secondBest;
        if(v.size()<=2){
            break;
        }
        for(ll j=0; j<v.size(); j++){
            if(j==0){
                if(v[v.size()-1]!=v[1]){
                    vector<ll>tmp = v;
                    tmp.erase(tmp.begin()+j);
                    if(checkAllEq(tmp)){
                        secondBest=tmp;
                    } else {
                        best=tmp;
                    }
                    erased=true;
                }
            } else if(j==v.size()-1){
                if(v[v.size()-2]!=v[0]){
                    vector<ll>tmp=v;
                    tmp.erase(tmp.begin()+j);
                    if(checkAllEq(tmp)){
                        secondBest=tmp;
                    } else {
                        best=tmp;
                    }
                    erased=true;
                }
            } else if(v[j-1]!=v[j+1]){
                vector<ll>tmp=v;
                tmp.erase(tmp.begin()+j);
                if(checkAllEq(tmp)){
                    secondBest=tmp;
                } else {
                    best=tmp;
                }
                erased=true;
            }
        }
        if(erased==false){
            break;
        }

        if(best.size()==0){
            v=secondBest;
        } else {
            v=best;
        }
        count++;

    }

    count+=2+(v.size()-2)/2;

    cout<<count<<endl;
    
    return 0;
}


vector<ll>largestCommonSubset(vector<ll>a, vector<ll>b){
    vector<ll>subset(a.size());
    for(ll i=0; i<a.size(); i++){
        if(a[i]==b[i]){
            subset[i]=a[i];
        }
    }
    return subset;
}


vector<ll>removeInd(vector<ll>&v, ll ind){
    ll currNum=0;
    for(ll i=0; i<v.size(); i++){
        if(currNum==ind&&v[i]==1){
            v.erase(v.begin()+i);
            return v;
        }
        if(v[i]==1){
            currNum++;
        }
    }
    return v;
}


ll count(string s, char c){
    ll n=0;
    for(ll i=0; i<s.length(); i++){
        if(s[i]==c){
            n++;
        }
    }
    return n;
}


bool found(string s, char c, vector<ll>pos){
    for(ll i=0; i<s.length(); i++){
        if(s[i]==c&&pos[i]==0){
            return false;
        }
    }
    return true;
}

int solutionC(){

    ll n;
    cin>>n;
    vector<string>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    map<vector<ll>, bool>seen;

    vector<vector<ll>>solution(n);

    ll root=-1;

    for(ll i=0; i<n; i++){
        vector<ll>tmp(n);
        
        if(found(v[i], '1', tmp)){
            root=i;
        }
    }

    for(ll i=1; i<=n; i++){
        solution[root].push_back(i);
    }

    seen[solution[root]]=true;
    vector<ll>solved(n);
    solved[root]=1;

    vector<ll>order;

    queue<ll>q;
    for(ll i=0; i<n; i++){
        if(solved[i]==0){
            q.push(i);
        }
    }

    while(q.size()>0){
        ll curr=q.front();
        q.pop();
        if(found(v[curr], '1', solved)){
            order.push_back(curr);
            solved[curr]=1;
        } else {
            q.push(curr);
        }
    }

    cout<<"root: "<<root<<endl;
    for(auto i:order){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<ll>nextIndRemove(n);

    for(ll nextSet=0; nextSet<order.size(); nextSet++){
        ll count1s=count(v[order[nextSet]], '1');
        cout<<"count1s: "<<count1s<<endl;
        if(count1s==1&&v[order[nextSet]][root]=='1'){
            vector<ll>tmp=solution[root];
            removeInd(tmp, nextIndRemove[root]);
            nextIndRemove[root]++;
            cout<<"tmp"<<endl;
            for(auto i:tmp){
                cout<<i<<" ";
            }
            cout<<endl;
            solution[order[nextSet]]=tmp;
        } else if(count1s==1){
            ll parent=-1;
            for(ll i=0; i<n; i++){
                if(v[order[nextSet]][i]=='1'){
                    parent=i;
                    break;
                }
            }
            vector<ll>tmp=solution[parent];
            removeInd(tmp, nextIndRemove[parent]);
            nextIndRemove[parent]++;
            solution[order[nextSet]]=tmp;
        } else if(count1s>1){
            vector<ll>parents;
            for(ll i=0; i<n; i++){
                if(v[order[nextSet]][i]=='1'){
                    parents.push_back(i);
                }
            }
            vector<ll>commonSubset=largestCommonSubset(solution[parents[0]], solution[parents[1]]);
            for(ll i=2; i<parents.size(); i++){
                commonSubset=largestCommonSubset(commonSubset, solution[parents[i]]);
            }
            ll ind=0;
            while(seen[commonSubset]==true){
                removeInd(commonSubset, ind);
                ind++;
            }
            cout<<"common subset; "<<endl;
            for(auto i:commonSubset){
                cout<<i<<" ";
            }
            cout<<endl;
            solution[order[nextSet]]==commonSubset;
        }
    }

    for(auto i:solution){
        cout<<i.size()<<" ";
        for(auto j:i){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }



    return 0;


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solutionC();
    }
}