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
    int k;
    cin>>k;
    int n = sqrt(k);
    while(n*n<k) n++;
    // cout<<n<<endl;
    if(k<=n*n and k>=n*n-n+1ll){
        // cout<<"he"
        cout<<n<<" "<<(n*n-k+1ll)<<endl;
    }
    else{
        cout<<(k-n*n+2ll*n-1ll)<<" "<<n<<endl;
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
