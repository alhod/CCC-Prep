#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<char, ll>leftToRight;
        map<char, ll>rightToLeft;
        map<string, ll>stringToCount;
        for(int i=0;i<n;i++){
            string val;
            cin>>val;
            leftToRight[val[0]]++;
            rightToLeft[val[1]]++;
            stringToCount[val]++;
        }
        
        ll combinations = 0;
        ll repetitions = 0;
        
        //find number of combinations (including repeating)
        for(auto char_int : leftToRight){
            combinations+=(char_int.second*(char_int.second-1))/2;
        }
        for(auto char_int : rightToLeft){
            combinations+=(char_int.second*(char_int.second-1))/2;
        }
        
        //find number of repetitions
        for(auto char_int : stringToCount){
            repetitions+=((char_int.second*(char_int.second-1))/2)*2;
        }
        combinations-=repetitions;
        cout<<combinations<<endl;
        
    }
    
    return 0;
}