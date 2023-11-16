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
    int n;
    cin>>n;
    if(n%2==0 and (n/2)%2==0){
        cout<<"YES"<<endl;
        int pairs1 = n/4;
        int i = 1, j = n;
        cout<<(n/2)<<endl;
        while(pairs1--){
            cout<<i<<" "<<j<<" ";
            i++, j--;
        }
        cout<<endl<<(n/2)<<endl;
        pairs1 = n/4;
        while(pairs1--){
            cout<<i<<" "<<j<<" ";
            i++, j--;
        }
        cout<<endl;
    }
    else if(n%2==1 and ((n-1)/2)%2==1){
        int i = 2, j = n-2;
        int pairs1 = (n-3)/4;
        cout<<"YES"<<endl<<((n-3)/2+2)<<endl<<"1"<<" "<<(n-1)<<" ";
        while(pairs1--){
            cout<<i<<" "<<j<<" ";
            i++, j--;
        }
        cout<<endl;
        pairs1 = (n-3)/4;
        cout<<((n-3)/2+1)<<endl<<n<<" ";
        while(pairs1--){
            cout<<i<<" "<<j<<" ";
            i++, j--;
        }
    //    cout<<
    }
    else cout<<"NO"<<endl;
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
