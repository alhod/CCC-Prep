#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        string a;
        cin>>n>>a;
        int operations = 0;
        int stack = 0;
        int stackCount = 0;
        bool impossibleCase1 = false;
        int pi = 0;
        int pj = 0;
        while(true){
            if (a.size() == 0 or pj==a.size()){
                break;
            }

            //update stack
            if (a[pj] == '(') {
                stack++;
                stackCount++;
            } else {
                stack--;
                stackCount++;
            }

            // if case 1 is true
            if (impossibleCase1 == false){
                cerr<<"check case 1"<<endl;
                if (stack < 0) {
                    impossibleCase1 = true;
                } else if (stack == 0) {
                    impossibleCase1 = false;
                    operations++;
                    a = a.substr(pj+1, a.length()-(pj+1));
                    cerr<<"cutting to size "<<a.length()-pj+1-pi<<endl;
                    cerr<<"pi "<<pi<<endl;
                    cerr<<"pj "<<pj<<endl;
                    cerr<<"a.length()-pj+1 "<<a.length()-pj+1<<endl;
                    cerr<<"new a --> "<<a<<endl;
                    stack = 0;
                    stackCount = 0;
                    pj = 0;
                }
            }

            if (a.size() == 0 or pj==a.size()){
                break;
            }

            // if case 2 is true
            if (pj-pi+1>=2) {
                cerr<<"check case 2"<<endl;
                cerr<<pi<<" "<<pj<<endl;
                if ((pj-pi+1)%2!=0){
                    int halfway = (pj-pi+1)/2;
                    string firstHalf, secondHalf;
                    firstHalf = a.substr(0, halfway+1);
                    secondHalf = a.substr(halfway, halfway+1);
                    reverse(secondHalf.begin(), secondHalf.end());
                    if (firstHalf == secondHalf){
                        impossibleCase1 = false;
                        operations++;
                        a = a.substr(pj+1, a.length()-(pj+1));
                        cerr<<"new a --> "<<a<<endl;
                        stack = 0;
                        stackCount = 0;
                        pj = 0;
                    }
                } else if ((pj-pi+1)%2==0) {
                    int halfway = (pj-pi+1)/2;
                    string firstHalf, secondHalf;
                    firstHalf = a.substr(0, halfway);
                    secondHalf = a.substr(halfway, halfway);
                    reverse(secondHalf.begin(), secondHalf.end());
                    if (firstHalf == secondHalf){
                        impossibleCase1 = false;
                        operations++;
                        a = a.substr(pj+1, a.length()-(pj+1));
                        cerr<<"new a --> "<<a<<endl;
                        stack = 0;
                        stackCount = 0;
                        pj = 0;
                    }
                }

            }

            if (a.size() == 0 or pj==a.size()){
                break;
            }

            pj++;
        }

        cout<<operations<<" "<<(a.size())<<endl;
    }

}