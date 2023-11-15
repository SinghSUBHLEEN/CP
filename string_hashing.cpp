#include<bits/stdc++.h>

using namespace std;

static long long int mult(int a, int b, int mod){
        int res = (1ll*a*b)%mod;
        return res<0?res+mod:res;
    }

    static long long int power(int a, int b, int mod){
        long long int res = 1ll;
        while(b){
            if(b%2==1)
                res = mult(res, a, mod);
            a = mult(a, a, mod);
            b = b/2;
        }
        return res;
    }

    class Hash {
    private:
        int length;
        const int mod1 = 1e9 + 7, mod2 = 1e9 + 9, p1 = 31, p2 = 37;
        vector<int> hash1, hash2, inv1, inv2;

    public:
        
        Hash(const string& s) {
            length = s.size();
            hash1.resize(length+1);
            hash2.resize(length+1);
            inv1.resize(length+1);
            inv2.resize(length+1);
            int h1 = 0, h2 = 0;
            long long pow1 = 1, pow2 = 1;
            hash1[0] = s[0]-'a'+1;
            hash2[0] = s[0]-'a'+1;
            for(int i = 1; i < length; i++) {
                hash1[i] = (hash1[i-1] + (s[i] - 'a' + 1) * pow1) % mod1;
                hash2[i] = (hash2[i-1] + (s[i] - 'a' + 1) * pow2) % mod2;
                pow1 = (pow1 * p1) % mod1;
                pow2 = (pow2 * p2) % mod2;
            }

            long long int inv_pow1 = power(p1, mod1-2, mod1), inv_pow2 = power(p2, mod2-2, mod2);
            inv1[0] = inv2[0] = 1;
            for(int i=1; i<length; i++){
                inv1[i] = mult(inv1[i-1], inv_pow1, mod1);
                inv2[i] = mult(inv2[i-1], inv_pow2, mod2);
            }
        }

        pair<int, int> getHash(const int l, const int r) {
            if(l == 0) return {hash1[r], hash2[r]};
            int temp1 = hash1[r] - hash1[l - 1];
            int temp2 = hash2[r] - hash2[l - 1];
            temp1 += (temp1 < 0 ? mod1 : 0);
            temp2 += (temp2 < 0 ? mod2 : 0);
            temp1 = (temp1 * 1LL * inv1[l]) % mod1;
            temp2 = (temp2 * 1LL * inv2[l]) % mod2;
            return {temp1, temp2};
        }
    };

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string s = "banana";
	Hash hash(s);
	cout<<hash.getHash(0, 4).first<<" "<<hash.getHash(0, 4).second<<endl;
	cout<<hash.getHash(1, 5).first<<" "<<hash.getHash(1, 5).second<<endl;
	return 0;
}