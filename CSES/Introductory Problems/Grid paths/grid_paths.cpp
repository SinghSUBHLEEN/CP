#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")


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

int helper(int i, int j, int k,  string &s){
    if(i==6 and j==0) return k==s.size();
    if(i<0 or j<0 or i>6 or j>6) return 0;
    int ans = 0;
    
}

void solve(){
    string s;
    cin>>s;

}

int32_t main(){
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin>>t;
    while (t--) solve();

    return 0;
}
