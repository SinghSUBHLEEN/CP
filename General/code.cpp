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
    string s, t;
    cin>>s;
    cin>>t;

    unordered_map<char, vector<int>> map;
    for(int i=0; i<m; i++) map[t[i]].push_back(i);

    for(int i=0; i<s.size()-t.size(); i++){
        if(s.substr(i, t.size())==t){
            for(int j=i; j<i+t.size(); j++) s[j] = '#';
        }
    }

    for(int i=0; i<n; i++){
        if(s[i]=='#') continue;
        if(map.find(s[i]) == map.end()){
            cout<<"No"<<endl;
            return ;
        }
        bool flag = false;
        for(auto &it:map[s[i]]){
            if(isValid(s, t, i, it)){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            return ;
        }
    }

    cout<<"Yes"<<endl;

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
