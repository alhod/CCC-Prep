#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool recurse(string s, ll ind, vector<vector<string>>&fib, ll count){
    if(ind==s.length()&&count>=2){
        return true;
    }

    for(ll i=0; i<fib.size(); i++){
        if(ind+i+1>s.length()){
            break;
        }
        
        for(ll j=0; j<fib[i].size(); j++){
            if(s.substr(ind, i+1)==fib[i][j]){
                if(recurse(s, ind+i+1, fib, count+1)){
                    return true;
                }
            }
        }
    }

    return false;
}


void solution(){
    string s;
    cin>>s;
    if(s.length()==1){
        cout<<"NO"<<endl;
        return;
    }

    vector<string>fib1={"0", "1", "2", "3", "5", "8"};
    vector<string>fib2={"13", "21", "34", "55", "89"};
    vector<string>fib3={"144", "233", "377", "610", "987"};
    vector<string>fib4={"1597", "2584", "4181", "6765"};
    vector<string>fib5={"10946", "17711", "28657", "46368", "75025"};

    vector<vector<string>>fib;
    fib.push_back(fib1);
    fib.push_back(fib2);
    fib.push_back(fib3);
    fib.push_back(fib4);
    fib.push_back(fib5);

    cout<<(recurse(s, 0, fib, 0)?"YES":"NO")<<endl;
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