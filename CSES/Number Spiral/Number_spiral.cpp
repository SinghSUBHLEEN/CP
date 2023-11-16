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

void solve(){
    int x, y;
    cin>>x>>y;
    if(x>=y){
        if(x%2==0)
            cout<<(x*x - y + 1)<<endl;
        else
            cout<<(x*x - 2*x + 1 + y)<<endl;
    }
    else{
        if(y%2==1)
            cout<<(y*y - x + 1)<<endl;
        else
            cout<<(y*y - 2*y + 1 + x)<<endl;
    }
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
