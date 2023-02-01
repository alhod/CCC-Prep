// Lmao read the statement wrong thought it was output the sum of the sub triangle of size k with the maximum sum


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;

    vector<vector<ll>>v(n, vector<ll>(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<=i; j++){
            cin>>v[i][j];
        }
    }


    vector<ll>pre_vertical(n+1);

    for(ll i=1; i<n+1; i++){

        pre_vertical[i]=pre_vertical[i-1];

        for(ll j=1; j<=i; j++){
            pre_vertical[i]+=v[i-1][j-1];
        }

    }   


    vector<vector<ll>>pre_diagnol_top_right(n+1, vector<ll>(n+1));

    for(ll j=1; j<n+1; j++){
        for(ll i=j; i<n+1; i++){
            pre_diagnol_top_right[i][j]=pre_diagnol_top_right[i-1][j]+v[i-1][j-1];
        }
    }

    for(ll j=2; j<n+1; j++){
        for(ll i=j; i<n+1; i++){
            pre_diagnol_top_right[i][j]+=pre_diagnol_top_right[i-1][j-1-1];
        }
    }




    vector<vector<ll>>copy_v=v;
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<(i+1+1)/2; j++){
            swap(copy_v[i-1][j-1], copy_v[i-1][i-j]);
        }
    }

    vector<vector<ll>>pre_diagnol_top_left(n+1, vector<ll>(n+1));

    for(ll j=1; j<n+1; j++){
        for(ll i=j; i<n+1; i++){
            pre_diagnol_top_left[i][j]=pre_diagnol_top_left[i-1][j]+copy_v[i-1][j-1];
        }
    }

    for(ll j=2; j<n+1; j++){
        for(ll i=j; i<n+1; i++){
            pre_diagnol_top_left[i][j]+=pre_diagnol_top_left[i][j-1];
        }
    }
    


    cout<<"copy_v:"<<endl;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<copy_v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"pre vertical:"<<endl;
    for(ll i=0; i<n+1; i++){
        cout<<pre_vertical[i]<<" ";
    }
    cout<<endl;

    cout<<"pre_diagonal_top_right:"<<endl;
    for(ll i=0; i<n+1; i++){
        for(ll j=0; j<n+1; j++){
            cout<<pre_diagnol_top_right[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"pre_diagonal_top_left:"<<endl;
    for(ll i=0; i<n+1; i++){
        for(ll j=0; j<n+1; j++){
            cout<<pre_diagnol_top_left[i][j]<<" ";
        }
        cout<<endl;
    }

    ll best=0;

    for(ll i=1; i<n-k+1; i++){
        for(ll j=1; j<=i+1; j++){
            ll section_sum=pre_vertical[i+k-1]-pre_vertical[i-1];
            ll left_section=pre_diagnol_top_right[i-1][j+k-1]-pre_diagnol_top_right[i-1][j-1];
            ll right_section=pre_diagnol_top_left[i-1][j+k-1]-pre_diagnol_top_left[i-1][j-1];
            best=max(best, section_sum-left_section-right_section);
        }
    }

    cout<<best<<endl;
    
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}