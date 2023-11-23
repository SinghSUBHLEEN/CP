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

void solve(){
    string s;
    cin>>s;
    vector<int> hash(26, 0);
    for(auto &it:s) hash[it-'A']++;
    int count = 0;
    for(auto &it:hash){
        count += (it%2==1);
    }

    if(count>1){
        cout<<"NO SOLUTION"<<endl;
        return ;
    }

    char ch = '#';
    for(int i=0; i<26; i++){
        if(hash[i]%2==1){
            ch = i+'A';
            hash[i]--;
            break;
        }
    } 

    for(int i=0; i<26; i++){
        int s = hash[i]/2;
        hash[i] -= s;
        while(s--) cout<<(char)(i+'A');
    }

    if(ch!='#') cout<<ch;

    for(int i=25; i>=0; i--){
        int s = hash[i];
        hash[i] = 0;
        while(s--) cout<<(char)(i+'A');
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
