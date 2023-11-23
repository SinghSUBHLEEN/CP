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
const int mod = (int) 1e9+7;

int get(){
    int n;
    cin >> n;
    return n;
}

int helper(int i, int s1, int s2, vector<int> &arr){
    if(i==arr.size())   return abs(s1-s2);
    int ans = 1e18;
    ans = min(ans, helper(i+1, s1+arr[i], s2, arr));
    ans = min(ans, helper(i+1, s1, s2+arr[i], arr));
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<helper(0, 0, 0, arr);
    return ;
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
