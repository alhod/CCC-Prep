#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        string v;
        cin>>n>>v;
        
        ll operations = 0;
        ll j = 0;
        ll stack = 0;
        bool imp = false;
        string rv = v;
        reverse(rv.begin(), rv.end());

        while(true){
            if (j==v.length()){
                // cout<<"a"<<endl;
                // cout<<"length "<<v.length()<<endl;
                // cout<<"v "<<v<<endl;
                cout<<operations<<" "<<j<<endl;
                break;
            } else if(v.length() == 0){
                // cout<<"b"<<endl;
                // cout<<"length "<<v.length()<<endl;
                cout<<operations<<" "<<j<<endl;
            }

            if (v[j] == '('){
                stack++;
            } else if(v[j] == ')'){
                stack--;
            }

            if (stack < 0){
                imp = true;
            }

            if (stack == 0 and imp == false){
                // cout<<"case 1"<<endl;
                v = v.substr(j+1, v.length()-(j+1));
                rv = rv.substr(0, rv.length()-j-1);
                j = 0;
                imp = false;
                stack = 0;
                operations++;
                continue;
            }


            if (j+1>=2){
                if ((j+1)%2!=0){
                    int halfway = j/2;
                    string leftHalf = v.substr(0, halfway+1);
                    string rightHalf = rv.substr(rv.length()-j-1, halfway+1);
                    if (leftHalf == rightHalf){
                        // cout<<"j "<<j<<endl;
                        // cout<<"case 2, a"<<endl;
                        // cout<<"leftHalf "<<leftHalf<<endl;
                        // cout<<"rightHalf"<<rightHalf<<endl;
                        v = v.substr(j+1, v.length()-(j+1));
                        rv = rv.substr(0, rv.length()-j-1);
                        j = 0;
                        imp = false;
                        stack = 0;
                        operations++;
                        continue;
                    }
                } else if ((j+1)%2==0){
                    int halfway = (j+1)/2;
                    string leftHalf = v.substr(0, halfway);
                    string rightHalf = rv.substr(rv.length()-j-1, halfway);
                    if (leftHalf == rightHalf){
                        // cout<<"case 2, b"<<endl;
                        v = v.substr(j+1, v.length()-(j+1));
                        rv = rv.substr(0, rv.length()-j-1);
                        j = 0;
                        imp = false;
                        stack = 0;
                        operations++;
                        continue;
                    }
                }
            }
            j++;
        }

    }

}