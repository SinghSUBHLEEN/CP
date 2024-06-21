#include<bits/stdc++.h>

using namespace std;


class a{
    public:
    int ele1;
    a(int x):ele1(x){}
};

class b: public a{
    public:
    int ele2;
    b(int x, int y):ele2(x),a(y){}
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    a *ptr1;
    b *ptr2 = new b(1, 265575);
    cout<<ptr2->ele2<<endl;
    ptr1 = ptr2;
    cout<<ptr1->ele1;
    return 0;
}