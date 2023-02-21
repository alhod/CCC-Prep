#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 300005

ll n;
vector<ll>v;
vector<vector<ll>>prime_factor_to_node;
vector<ll>prev_arr;
vector<bool>visited;
vector<bool>visited_prime_factors;


ll spf[MAXN];

void sieve()
{
	spf[1] = 1;
	for (ll i=2; i<MAXN; i++)
		spf[i] = i;
	for (ll i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (ll i=3; i*i<MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (ll j=i*i; j<MAXN; j+=i){
				if (spf[j]==j){
					spf[j] = i;
                }
            }
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
set<ll> PrimeFactorization(ll x)
{
	set<ll> ret;
	while (x != 1)
	{
		ret.insert(spf[x]);
		x = x / spf[x];
	}
	return ret;
}


void solution(){
    cin>>n;
    v.resize(n);
    prime_factor_to_node.resize(MAXN);
    visited.resize(n);
    prev_arr.resize(n);
    visited_prime_factors.resize(MAXN);

    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    for(ll i=0; i<n; i++){
        set<ll>prime_factors=PrimeFactorization(v[i]);
        for(auto prime_factor:prime_factors){
            prime_factor_to_node[prime_factor].push_back(i);
        }
    }

    bool found=false;

    ll s, t;
    cin>>s>>t;
    s--;
    t--;
    queue<ll>q;
    q.push(s);
    prev_arr[s]=s;
    while(q.size()>0){
        ll curr=q.front();
        q.pop();

        visited[curr]=true;

        if(curr==t){
            found=true;
            break;
        }

        set<ll>prime_factors=PrimeFactorization(v[curr]);

        for(auto prime_factor:prime_factors){
            if(visited_prime_factors[prime_factor]){
                continue;
            }

            visited_prime_factors[prime_factor]=true;

            for(auto neighbor:prime_factor_to_node[prime_factor]){
                if(!visited[neighbor]){
                    prev_arr[neighbor]=curr;
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    }

    if(!found){
        cout<<-1<<endl;
        return;
    }

    vector<ll>ans;
    ll curr=t;
    while(curr!=prev_arr[curr]){
        // printf("a curr: %d\n", curr);
        ans.push_back(curr);
        curr=prev_arr[curr];
    }
    ans.push_back(curr);
    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i+1<<" ";
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    solution();
}