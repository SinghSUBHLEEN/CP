#include <bits/stdc++.h>
#include <string_view>
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
    int n = get();
    if(n==1) cout<<"1"<<endl;
    else if (n <= 3)
        cout << "NO SOLUTION" << endl;
    else{
        if (n % 2 == 0){
            for(int i=2; i<=n; i+=2) cout<<i<<" ";
            for(int i=1; i<=n; i+=2) cout<<i<<" ";
        }
        else{
            for(int i=1; i<=n; i+=2) cout<<i<<" ";
            for(int i=2; i<=n; i+=2) cout<<i<<" ";
        }
    }
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
