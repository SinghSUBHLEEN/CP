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

void solve(){ 
    int a = get(), b = get();
    if((2*b-a)%3==0 and (2*b-a)/3>=0 and (2*a-b)%3==0 and (2*a-b)/3>=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return;
}

int32_t main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin>>t;
    while (t--) solve();

    return 0;
}
