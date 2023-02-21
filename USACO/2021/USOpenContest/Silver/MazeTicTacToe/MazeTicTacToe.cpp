#include<bits/stdc++.h>
#define ll long long
using namespace std;




ll n;
char board[25][25][3];
set<ll>ans;
bool seen[25][25][19684];
ll pow3[10];


bool check(ll b){
    ll cnt[3][3];
    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            cnt[i][j]=b%3;
            b/=3;
        }
    }

    for(ll i=0; i<3; i++){
        if(cnt[i][0]==1&&cnt[i][1]==2&&cnt[i][2]==2)return true;
        if(cnt[i][0]==2&&cnt[i][1]==2&&cnt[i][2]==1)return true;
        if(cnt[0][i]==1&&cnt[1][i]==2&&cnt[2][i]==2)return true;
        if(cnt[0][i]==2&&cnt[1][i]==2&&cnt[2][i]==1)return true;
    }

    if(cnt[0][0]==1&&cnt[1][1]==2&&cnt[2][2]==2)return true;
    if(cnt[0][0]==2&&cnt[1][1]==2&&cnt[2][2]==1)return true;
    if(cnt[0][2]==2&&cnt[1][1]==2&&cnt[2][0]==1)return true;
    if(cnt[0][2]==1&&cnt[1][1]==2&&cnt[2][0]==2)return true;
    

    return false;
}


void dfs(ll r, ll c, ll b){

    if(seen[r][c][b]){
        return;
    }

    seen[r][c][b]=true;

    if(board[r][c][0]=='O'||board[r][c][0]=='M'){
        ll r2=board[r][c][1]-'1';
        ll c2=board[r][c][2]-'1';
        ll ind=r2*3+c2;
        ll curr_char=(b/pow3[ind])%3;
        if(curr_char==0){
            ll new_char=(board[r][c][0]=='M'?1:2);
            b=(b%pow3[ind])+(new_char*pow3[ind])+(b-b%pow3[ind+1]);
            if(!seen[r][c][b]&&check(b)){
                ans.insert(b);
                return;
            }
            seen[r][c][b]=true;
        }
    }



    if(board[r+1][c][0]!='#')dfs(r+1, c, b);
    if(board[r-1][c][0]!='#')dfs(r-1, c, b);
    if(board[r][c+1][0]!='#')dfs(r, c+1, b);
    if(board[r][c-1][0]!='#')dfs(r, c-1, b);
}


void solution(){
    ll bessie_r, bessie_c;
    scanf("%d", &n);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            scanf(" %c%c%c", &board[i][j][0], &board[i][j][1], &board[i][j][2]);
            if(board[i][j][0]=='B'){
                bessie_r=i;
                bessie_c=j;
            }
        }
    }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<n; j++){
    //         printf("%c%c%c ", board[i][j][0], board[i][j][1], board[i][j][2]);
    //     }
    //     printf("\n");
    // }


    pow3[0]=1;
    for(ll i=1; i<10; i++){
        pow3[i]=pow3[i-1]*3;
    }

    dfs(bessie_r, bessie_c, 0);

    printf("%lld", ans.size());
    
}



int main(){
    if (fopen("MazeTicTacToe.cpp.in", "r")) {
		freopen("MazeTicTacToe.cpp.in", "r", stdin);
		freopen("MazeTicTacToe.cpp.out", "w", stdout);
	}

    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}