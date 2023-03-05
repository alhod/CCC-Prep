// Import C++ standard library stuff
#include<bits/stdc++.h>


// Shorten "long long" to just "ll"
#define ll long long


// Makes syntax a bit cleaner
using namespace std;


// The solution
void solution(){

    // n = number of rows
    // m = number of columns
    // r = number of row palindromes
    // c = number of column palindromes
    ll n, m, r, c;
    cin>>n>>m>>r>>c;


    // number of row palindromes to remove
    ll rows_to_remove=n-r;

    // number of column palindromes to remove
    ll columns_to_remove=m-c;


    // initialize 2D array with n rows, m columns, filled with a's
    vector<vector<char>>v(n, vector<char>(m, 'a'));


    // if all columns are palindromes, and the number of rows is even,
    // and the number of row palindromes is odd, it is impossible
    if(c==m&&n%2==0&&rows_to_remove%2==1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }


    // if all rows are palindromes, and the number of columns is even, 
    // and the number of column palindromes is odd, it is impossible
    if(r==n&&m%2==0&&columns_to_remove%2==1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }


    // if no row palindromes and no column palindromes
    if(r==0&&c==0){

        // remove all row palindromes
        for(ll i=0; i<n; i++){
            v[i][0]='b';
        }

        // remove all column palindromes
        for(ll j=0; j<m; j++){
            v[0][j]='b';
        }

        // set top left corner to 'c'
        v[0][0]='c';
    }

    // if no row palindromes
    else if(r==0){

        // remove all row palindromes
        for(ll i=0; i<n; i++){
            v[i][0]='b';
        }

        // remove desired number of column palindromes
        for(ll j=0; j<m&&columns_to_remove; j++){
            v[0][j]='c';

            // decrement
            columns_to_remove--;
        }
    }

    // if no column palindromes
    else if(c==0){

        // remove all column palindromes
        for(ll j=0; j<m; j++){
            v[0][j]='b';
        }

        // remove desired number of row palindromes
        for(ll i=0; i<n&&rows_to_remove; i++){
            v[i][0]='c';

            // decrement
            rows_to_remove--;
        }
    }

    // if all rows are palindromes
    else if(r==n){

        // if the number of column palindromes is odd
        if(columns_to_remove%2==1){

            // remove middle column palindrome
            v[0][m/2]='b';

            // decrement
            columns_to_remove--;
        }
        
        // remove desired number of column palindromes in pattern:
        // **numbers represent the iteration at which this palindrome is removed**
        // **'a' represents this palindrome is not removed**
        // 1 3 5 a a a X a a a 6 4 2 (if c is odd, X is removed in previous if statement)

        // 1 3 5 a a a a a a a 6 4 2 (c is even, middle column is not removed)
        for(ll j=0; j<m&&columns_to_remove; j++){
            if(j%2==0){
                v[0][j/2]='b';
            } else {
                v[0][m-j/2-1]='b';
            }

            // decrement
            columns_to_remove--;
        }
    }


    // if all columns are palindromes
    else if(c==m){

        // if the number of row palindromes is odd
        if(rows_to_remove%2==1){

            // remove middle row palindrome
            v[n/2][0]='b';

            // decrement
            rows_to_remove--;
        }

        // remove desired number of row palindromes in pattern:
        // **numbers represent the iteration at which this palindrome is removed**
        // **'a' represents this palindrome is not removed**
        // 1
        // 3
        // 5
        // a
        // a
        // a
        // X (if r is odd, X is removed in previous if statement)
        // a
        // a
        // a
        // 6
        // 4
        // 2

        // (if r is even)
        // 1
        // 3
        // 5
        // a
        // a
        // a
        // a
        // a
        // a
        // a
        // 6
        // 4
        // 2
        for(ll i=0; i<n&&rows_to_remove; i++){
            if(i%2==0){
                v[i/2][0]='b';
            } else {
                v[n-i/2-1][0]='b';
            }

            // decrement
            rows_to_remove--;
        }
    }

    // 0<r<n and 0<c<m
    else {

        // remove desired number of row palindromes
        for(ll i=0; i<n&&rows_to_remove; i++){
            v[i][0]='b';

            // decrement
            rows_to_remove--;
        }

        // remove desired number of column palindromes
        for(ll j=0; j<m&&columns_to_remove; j++){
            v[0][j]='b';

            // decrement
            columns_to_remove--;
        }
    }

    
    // print 2D array
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}


// Main function
int main(){
    
    
    // Faster input
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    // Call solution function
    solution();
}
