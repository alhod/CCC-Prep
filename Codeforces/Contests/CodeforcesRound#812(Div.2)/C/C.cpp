#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    bool display=false;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);  // base zero inputted vector
        for(ll i=0; i<n; i++){
            v[i]=i;
        }

        vector<ll>out(n);  // base zero output vector

        vector<ll>perfectSquares;  // vector of perfect squares
        
		vector<ll>used(n); // 0 indexed based show whether number has been used

        // generate perfect squares
        ll inc=1;  // incrementer
        perfectSquares.push_back(0);
        ll newPerfectSquare;
        while(true){
            newPerfectSquare=perfectSquares.back()+inc;
            if(newPerfectSquare>(n-1)*2){
                break;
            }
            perfectSquares.push_back(perfectSquares.back()+inc);
            inc+=2;

        }
        
		
        if(display==true){
			cout<<"perfect squares: "<<endl;
            for(auto i:perfectSquares){
                cout<<i<<" ";
            }
			cout<<endl;
        }


		ll indPerfectSquares=perfectSquares.size()-1;
		ll indVector=v.size()-1;
		ll complement;
		while(true){
			// cout<<perfectSquares[indPerfectSquares]<<" "<<v[indVector]<<endl;
			complement = perfectSquares[indPerfectSquares]-v[indVector];
			// cout<<"comp: "<<complement<<endl;
			if(used[complement]==0){
				// cout<<"indVector: "<<indVector<<endl;
				ll inc=0;
				for(ll i=indVector; i>=complement; i--){
					out[i]=complement+inc;
					used[out[i]]=1;
					inc++;
				}
			} else {
				indPerfectSquares--;
				continue;
			}
			indPerfectSquares--;
			indVector=complement-1;
			if(indVector<0){
				break;
			}
		}

		for(auto i:out){
			cout<<i<<" ";
		}
		cout<<endl;

    }

    return 0;
}