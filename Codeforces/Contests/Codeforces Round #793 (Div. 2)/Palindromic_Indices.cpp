# include <iostream>
# include <algorithm>

using namespace std;

int main() {

    int test;

    cin>>test;

    while (test--) {
        int n;
        
        cin>>n;

        string str;
        cin>>str;

        int centre = n/2;
        int iterate_left = centre;
        int iterate_right = centre;
        char centre_letter = str[centre];


        int counter = 1;

        while (true) {
            if (str[iterate_left-1] != centre_letter or iterate_left<0) {
                break;
            } else {
                counter++;
                iterate_left--;
            }
        }

        while (true) {
            if (str[iterate_right+1] != centre_letter or iterate_right>=n) {
                break;
            } else {
                counter++;
                iterate_right++;
            }
        }

        cout<<counter<<endl;

    }

    return 0;
}