#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int l1, l2, r1, r2;
        cin>>l1>>l2>>r1>>r2;
        if (l1 < r1 && l2 < r1){
            cout<<l1+r1<<endl;
        } else if (l1<=r1 && l1<=r2 && l2>=r1 && l2<=r2) {
            cout<<r1<<endl;
        } else if (l1>r1 && l2 > r1 && l1 < r2 && l2 < r2) {
            cout<<l1<<endl;
        } else if (l1>=r1 && l1<=r2 && l2>=r1 && l2 >= r2) {
            cout<<l1<<endl;
        } else if (l1<r1&&l1<r2&&l2>r1&&l2>r2) {
            cout<<r1<<endl;
        } else {
            cout<<r1+l1<<endl;
        }
    }

}