# include <iostream>
# include <vector>

using namespace std;

int main() {

    int cases;

    cin >> cases;

    int candy_length_arr[cases];
    string candies_array[cases];

    for (int i = 0; i < cases; i++) {
        
        int tmp_candy_length_arr;
        string tmp_candies_array;

        cin >> tmp_candy_length_arr;

        cin.ignore();

        getline(cin, tmp_candies_array);

        candy_length_arr[i] = tmp_candy_length_arr;
        candies_array[i] = tmp_candies_array;

    }


    for (int i = 0; i < cases; i++) {
        
        int num_candies = candy_length_arr[i];

        string candies = candies_array[i];


        int candies_arr[num_candies];
        int tmp_ca = 0;


        int length = candies.length();

        string a_candy;
        
        // cout << "num_candies --> " << num_candies << endl;
        // cout << "candies --> " << candies << endl;
        // cout << "length --> " << length << endl;


        for (int i = 0; i < length; i++) {
            // cout << "a_candy" << a_candy << endl;
            if (candies[i] == ' ') {
                candies_arr[tmp_ca] = stoi(a_candy);
                tmp_ca++;
                a_candy = " ";
            } else {
                a_candy += candies[i];
            }
        }

        candies_arr[tmp_ca] = stoi(a_candy);


        int lowest_candy = 0;


        for (int i = 0; i < num_candies; i++) {
            if (lowest_candy == 0) {
                lowest_candy = candies_arr[i];
                continue;
            }

            if (candies_arr[i] < lowest_candy) {
                lowest_candy = candies_arr[i];
            }
        }
        

        int too_eat = 0;

        for (int i = 0; i < num_candies; i++) {
            too_eat += (candies_arr[i]-lowest_candy);
        }

        cout << too_eat << endl;
    }

    return 0;
}