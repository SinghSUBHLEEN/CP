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

vector<string> helper(int n){
    if(n<1) return {""};
    if(n==1) return {"0", "1"};
    auto l = helper(n-1);
    int prev = 0;
    vector<string> ans;
    for(int i=0; i<l.size(); i++){
        l[i].push_back('0'+prev);
        ans.push_back(l[i]);
        prev = 1-prev;
        l[i][l[i].size()-1] = '0'+prev;
        ans.push_back(l[i]);
    }
    return ans;
}

void solve(){
    int n = get();
    auto ans = helper(n);
    for(auto &it:ans)
        cout<<it<<endl;
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
