#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool display = true;

vector<string> replace(ll n, ll newMaxVal, ll ind){  // n is length, m is max value in string + 1, 
    vector<string>str(n);
    for(ll i=0; i<n; i++){
        str[i]=to_string(i%(newMaxVal-1)+1);
    }
    if(display == true){
        for(auto i:str){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"--------------------"<<endl;
    }
    while(ind>0){
        str[n-ind]=to_string(newMaxVal);
        ind-=newMaxVal;
    }
    if(display == true){
        for(auto i:str){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"--------------------"<<endl;
    }
    return str;
}

vector<string> solution(ll n, ll k, ll leftMax, ll newMaxVal, ll leftComb){
    ll ind = (k-leftComb)*leftMax;
    if (display == true){
        cout<<"n: "<<n<<endl;
        cout<<"k: "<<k<<endl;
        cout<<"leftMax: "<<leftMax<<endl;
        cout<<"newMaxVal: "<<newMaxVal<<endl;
        cout<<"ind: "<<ind<<endl;
    }
    return replace(n, newMaxVal, ind);
}

int calCombs(ll n, ll m){
    m--;
    return (n+n*m-((m*(m+1))/2));
}

int main1(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll tmp;
    if(n<=k&&k<=calCombs(n, m)){
        tmp=1;
    } else{
        cout<<-1<<endl;
        return 0;
    }

    ll leftMax=1;
    ll rightMax=n;
    ll curr=(leftMax+rightMax)/2;
    ll leftComb=calCombs(n, leftMax);
    ll rightComb=calCombs(n, rightMax);
    ll currComb=calCombs(n, curr);
    
    ll index;
    bool early = false;

    while(true){
        curr=((leftMax+rightMax)/2);
        leftComb=calCombs(n, leftMax);
        rightComb=calCombs(n, rightMax);
        currComb=calCombs(n, curr);
        if(display==true){
            cout<<"1"<<endl;
        }
        if(k==leftComb){
            vector<string>str(n);
            for(ll i=0; i<n; i++){
                str[i]=to_string(i%(leftMax)+1);
            }
            early = true;
            for(auto i:str){
                cout<<i<<" ";
            }
            cout<<endl;
            break;
        }
        if(k==rightComb){
            vector<string>str(n);
            for(ll i=0; i<n; i++){
                str[i]=to_string(i%(rightMax)+1);
            }
            early = true;
            for(auto i:str){
                cout<<i<<" ";
            }
            cout<<endl;
            break;
        }
        if(k==currComb){
            vector<string>str(n);
            for(ll i=0; i<n; i++){
                str[i]=to_string(i%(curr)+1);
            }
            early = true;
            for(auto i:str){
                cout<<i<<" ";
            }
            cout<<endl;
            break;
        }
        if(rightMax-leftMax==1){
            index=leftMax;
            break;
        }
        if(k<currComb){
            rightMax=curr;
            continue;
        }
        if(k>currComb){
            leftMax=curr;
            continue;
        }
    }

    if(early==true){
        return 0;
    }
    if(display==true){
        cout<<"2"<<endl;
    }
    vector<string>str = solution(n, k, leftMax, rightMax, leftComb);
    for(auto i:str){
        cout<<i<<" ";
    }
    cout<<endl;



    return 0;
}

int main(){
    ll t; 
    if(display==true){
        cin>>t;
        while(t--){
            main1();
        }
    }
    else{
        main1();
    }
    return 0;
}