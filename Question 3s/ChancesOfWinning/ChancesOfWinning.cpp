// number of possible outcomes is 3^remaining games
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t;
vector<ll>scores(4);
map<ll, vector<ll>>m;

ll isFavouriteTeamWinning(vector<ll>scores){
    ll favouriteTeamScore = scores[t];
    if(*max_element(scores.begin(), scores.end())==favouriteTeamScore&&count(scores.begin(), scores.end(), favouriteTeamScore)==1){
        // cout<<"favourite team is winning"<<endl;
        return 1;
    } else {
        // cout<<"favourite team is losing"<<endl;
        return 0;
    }
}

ll team3(vector<ll>scores, ll ind, map<ll, vector<ll>>m){
    
    ll teamToPlay;
    ll numOfWins=0;

    // for(auto i:scores){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"m:"<<endl;
    // for(auto i:m){
    //     cout<<i.first<<"-->"<<i.second[0]<<" "<<i.second[1]<<" "<<i.second[2]<<" "<<i.second[3]<<endl;
    // }
    // cout<<"--end--"<<endl;

    if(count(m[2].begin(), m[2].end(), 0)==0){
        // cout<<"calculating isFavouriteTeamWinning"<<endl;
        return isFavouriteTeamWinning(scores);
    }
    for(ll i=ind; i<4; i++){
        if(m[2][i]==0){
            teamToPlay=i;
            // cout<<"team 3 vs. team "<<teamToPlay+1<<endl;
            m[2][i]=1;
            m[i][2]=1;
            ind = i+1;
            break;
        }
    }
    for(ll i=0; i<3; i++){
        // cout<<"current numebr of wins: "<<numOfWins<<endl;
        if(i==0){  // win
            vector<ll>copyScores=scores;
            copyScores[2]+=3;
            numOfWins+=team3(copyScores, ind, m);
        } else if(i==1){  // tie
            vector<ll>copyScores=scores;
            copyScores[2]+=1;
            copyScores[teamToPlay]+=1;
            numOfWins+=team3(copyScores, ind, m);
        } else {
            vector<ll>copyScores=scores;
            copyScores[teamToPlay]+=3;
            numOfWins+=team3(copyScores, ind, m);
        }
    }

    return numOfWins;
}

ll team2(vector<ll>scores, ll ind, map<ll, vector<ll>>m){
        
    ll teamToPlay;
    ll numOfWins=0;

    // for(auto i:scores){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"m:"<<endl;
    // for(auto i:m){
    //     cout<<i.first<<"-->"<<i.second[0]<<" "<<i.second[1]<<" "<<i.second[2]<<" "<<i.second[3]<<endl;
    // }
    // cout<<"--end--"<<endl;

    if(count(m[1].begin(), m[1].end(), 0)==0){
        // cout<<"going to team 3"<<endl;
        return team3(scores, 0, m);
    }
    for(ll i=ind; i<4; i++){
        if(m[1][i]==0){
            teamToPlay=i;
            // cout<<"team 2 vs. team "<<teamToPlay+1<<endl;
            m[1][i]=1;
            m[i][1]=1;
            ind = i+1;
            break;
        }
    }
    for(ll i=0; i<3; i++){
        // cout<<"current numebr of wins: "<<numOfWins<<endl;
        if(i==0){  // win
            vector<ll>copyScores=scores;
            copyScores[1]+=3;
            numOfWins+=team2(copyScores, ind, m);
        } else if(i==1){  // tie
            vector<ll>copyScores=scores;
            copyScores[1]+=1;
            copyScores[teamToPlay]+=1;
            numOfWins+=team2(copyScores, ind, m);
        } else {
            vector<ll>copyScores=scores;
            copyScores[teamToPlay]+=3;
            numOfWins+=team2(copyScores, ind, m);
        }
    }

    return numOfWins;
}

ll team1(vector<ll>scores, ll ind, map<ll, vector<ll>>m){
    
    // for(auto i:scores){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"m:"<<endl;
    // for(auto i:m){
    //     cout<<i.first<<"-->"<<i.second[0]<<" "<<i.second[1]<<" "<<i.second[2]<<" "<<i.second[3]<<endl;
    // }
    // cout<<"--end--"<<endl;
    
    ll teamToPlay;
    ll numOfWins=0;

    if(count(m[0].begin(), m[0].end(), 0)==0){
        // cout<<"going to team 2"<<endl;
        return team2(scores, 0, m);
    }
    for(ll i=ind; i<4; i++){
        if(m[0][i]==0){
            teamToPlay=i;
            // cout<<"team 1 vs. team "<<teamToPlay+1<<endl;
            m[0][i]=1;
            m[i][0]=1;
            ind = i+1;
            break;
        }
    }
    for(ll i=0; i<3; i++){
        // cout<<"current numebr of wins: "<<numOfWins<<endl;
        if(i==0){  // win
            vector<ll>copyScores=scores;
            copyScores[0]+=3;
            numOfWins+=team1(copyScores, ind, m);
        } else if(i==1){  // tie
            vector<ll>copyScores=scores;
            copyScores[0]+=1;
            copyScores[teamToPlay]+=1;
            numOfWins+=team1(copyScores, ind, m);
        } else {
            vector<ll>copyScores=scores;
            copyScores[teamToPlay]+=3;
            numOfWins+=team1(copyScores, ind, m);
        }
    }

    return numOfWins;
}

int main(){
    ll g;
    cin>>t>>g;
    t--;
    
    
    for(ll i=0; i<4; i++){
        m[i]={0, 0, 0, 0};
        m[i][i]++;
    }

    for(ll i=0; i<g ;i++){
        ll t1, t2, t1score, t2score;
        cin>>t1>>t2>>t1score>>t2score;
        if(t1score>t2score){
            scores[t1-1]+=3;
        } else if(t1score<t2score){
            scores[t2-1]+=3;
        } else{
            scores[t1-1]++;
            scores[t2-1]++;
        }
        
        m[t1-1][t2-1]++;
        m[t2-1][t1-1]++;

    }

    cout<<team1(scores, 0, m)<<endl;

}