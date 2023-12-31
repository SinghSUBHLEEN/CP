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

bool isValid(string &s, string &t, int i, int j){
    while(i<s.size() and j<t.size()){
        if(s[i]!=t[j] and s[i]!='#') return false;
        i++, j++;
    }
    return true;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(auto &it:arr) --it;
    vector<unordered_map<int, int>> box(n+1);

    for(int i=0; i<n; i++){
        box[i][arr[i]] = 1;
    }

    unordered_map<int, int> e;

    for(int i=0; i<m; i++){
        int a = get(), b = get();
        a--, b--;
        for(auto &it:box[a]){
            box[b][it.first]  = 1;
        }
        box[a] = e;
        cout<<box[b].size()<<endl;
    }

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
