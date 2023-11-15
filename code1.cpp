#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
using namespace std;

typedef long long ll;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        int a, b, c;
        string s;
        cin>>a>>b>>c;
        cin>>s;
        cout<<(a+b+c)<<" "<<s<<endl;
    }
    return 0;
}
