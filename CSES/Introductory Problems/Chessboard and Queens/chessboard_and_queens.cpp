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

bool isValid(int r, int c, vector<vector<char>> &m){
    int i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i++;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        j++;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i++, j++;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i--;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        j--;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i--, j--;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i++, j--;
    }
    i = r, j = c;
    while(i<8 and j<8 and i>=0 and j>=0){
        if(m[i][j]=='Q') return false;
        i--, j++;
    }
    return true;
}

int helper(int r, int n, vector<vector<char>> &chess){
    if(n==0) return 1;
    if(r==8) return 0;
    int ans = 0;
    for(int c=0; c<8; c++){
        if(chess[r][c]=='.' and isValid(r, c, chess)){
            chess[r][c] = 'Q';
            ans += helper(r+1, n-1, chess);
            chess[r][c] = '.';
        }
    }
    return ans;
}

void solve(){ 
    vector<vector<char>> chess(8, vector<char>(8, '.'));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>chess[i][j];
        }
    }
    cout<<helper(0, 8, chess);
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
