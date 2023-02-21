// Time Complexity: O(n+log(MOD)) (preprocess), O(1) (query)
// Space Complexity: O(n+log(MOD))

// Binommial coefficient (n r) ("n choose r" or "nCr") is defined as the number of unique subsets of 
// r elements from a set of n elements such that the order of the subset doesn't matter. nCr can be 
// calculated using factorials (n!/(k!(n-k)!)) or Pascal's Triangle (dynamic programming, where (n r)
// = (n-1 r-1)+(n-1 r), or in Pascal's Triangle starting from row i=0 and column j=0, the value at 
// i j is (j i) or iCj). Pascal's Triangle can be expressed an iCj, and the coefficients in a binomial
// expansion (binomial coefficients) can be expressed using Pascal's Triangle, thus iCj can also be
// used to express binomial coefficients (which is why nCr is also called binomial coefficient).

// The value of binomial coefficients can be very large, which is why they are usually taken to the
// modulo p. Below is the factorial definition of a binomial coefficient, which involves modulus in
// division. Thus, we must take the modular inverse of the denominator. The dp approach doesn't 
// require taking modular inverse, but its time complexity is O(n^2).


#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];
		
/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) {
		inv[i - 1] = inv[i] * i % p;
	}
}
		
/** Computes nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

int main(){
    ll p;
    cin>>p;
    factorial(p);
    inverses(p);

    ll t;
    cin>>t;
    while(t--){
        ll n, r;
        cin>>n>>r;
        cout<<choose(n, r, p)<<endl;
    }
}