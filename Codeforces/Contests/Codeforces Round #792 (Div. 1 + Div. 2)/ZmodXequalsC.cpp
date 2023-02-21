#include <iostream>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--) {
        int a, b, c;
        cin>>a>>b>>c;
        int x, y, z;
        z = c;
        y = b+z;
        x = y+a;
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

}