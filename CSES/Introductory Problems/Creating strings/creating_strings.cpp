#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> p3;
typedef pair<ll, ll> pl;
typedef pair<int, pl> p3l;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(a, b) for (int i = (a); i < (b); i++)
#define REP(n) FOR(0, n)
#define SORT(v) sort(begin(v), end(v))
#define pb push_back
#define int long long

int get(){
    int n;
    cin >> n;
    return n;
}

int n;

void helper(string s, vector<int> &hash){
    if(s.size()==n){
        cout<<s<<endl;
        return ;
    }

    for(int i=0; i<26; i++){
        if(hash[i]<=0) continue;
        hash[i]--;
        s.push_back('a'+i);
        helper(s, hash);
        s.pop_back();
        hash[i]++;
    }
    return ;
}

int fact(int n, int *dp){
    if(n==0 or n==1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = n*fact(n-1, dp);
}

void solve(){
    string s;
    cin>>s;
    int dp[100];
    memset(dp, -1, sizeof dp);
    int n = fact(s.size(), dp);
    vector<int> hash(26, 0);
    for(auto &it:s){
        hash[it-'a']++;
    }
    for(auto &it:hash){
        n /= fact(it, dp);
    }
    cout<<n<<endl;
    ::n = s.size();
    helper("", hash);
}

int32_t main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin>>t;
    while (t--) solve();

    return 0;
}
