#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order -> used as index operator (similar to .at() function)
// order_of_key -> used to find the number of elements smaller than a certain number (passed as key)
// lower_bound(int x) -> find the lower bound of x
// upper_bound(int x) -> find the upper bound of x
// insert and erase operations just like set.

int main(){
	return 0;
}