#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
	vector<bool> prime(n, 1);
	for(int i=2; i*i<=n; i++){
		if(!prime[i]) continue;
		for(int j=i*i; j<=n; j+=i){
			prime[j] = 0;
		}
	}

	return prime;
}


