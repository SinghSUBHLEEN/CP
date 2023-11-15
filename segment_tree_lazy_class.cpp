#include<bits/stdc++.h>

	using namespace std;
	
	class segment_tree_sum{
		vector<int> seg;
		vector<int> lazy;
		int n;
		public:
			segment_tree_sum(vector<int> &arr){
				seg.resize(arr.size()*4, -1);
				lazy.resize(arr.size()*4, 0);
				n = arr.size();
				build(0, 0, n-1, arr);
			}
			void build(int i, int l, int r, vector<int> &arr){
				if(l==r){
					seg[i] = arr[i];
					return;
				}
				int mid = (l+r)/2;
				build(2*i+1, l, mid, arr);
				build(2*i+2, mid+1, r, arr);
				seg[i] = seg[2*i+1] + seg[2*i+2];
				return;
			}
			
			void update_point(int i, int l, int r, vector<int> &q){
				if(l==r){
					seg[i] = q[1];
					return;
				}
				int mid = (l+r)/2;
				if(mid<=q[0])
					update_point(2*i+1, l, mid, q);
				else
					update_point(2*i+2, mid+1, r, q);
				seg[i] = seg[2*i+1]+seg[2*i+2];
				return;
			}
			
			void update_range(int i, int l, int r, vector<int> &q){
				if(lazy[i]!=0){
					seg[i] += (r-l+1)*lazy[i];
					if(l!=r){
						//this means that this node is not a leaf node and it has two childs
						lazy[2*i+1] += lazy[i];
						lazy[2*i+2] += lazy[i];
					}
					lazy[i] = 0;
				}
//				this should be treated as a query and so we have 3 overlap poss
				if(l>q[1] or r<q[0]){
					return;
				}
				if(l>=q[0] and r<=q[1]){
//					if complete overlap, then do the update here and pass on the lazy update to child nodes is present
					seg[i] += (r-l+1)*q[2];
					if(l!=r){
						lazy[2*i+1] += q[2];
						lazy[2*i+2] += q[2];
					}
					return;
				}
				int mid = (l+r)/2;
				update_range(2*i+1, l, mid, q);
				update_range(2*i+2, mid+1, r, q);
				seg[i] = seg[2*i+1] + seg[2*i+2];
				return;
			}
			
			int query(int i, int l, int r, vector<int> &q){
				if(lazy[i]!=0){
					seg[i] += (r-l+1)*lazy[i];
					if(l!=r){
						//this means that this node is not a leaf node and it has two childs
						lazy[2*i+1] += lazy[i];
						lazy[2*i+2] += lazy[i];
					}
					lazy[i] = 0;
				}
				if(l>q[1] or r<q[0]){
					return 0;
				}
				if(l>=q[0] and r<=q[1])
					return seg[i];
				int mid = (l+r)/2;
				return query(2*i+1, l, mid, q)+query(2*i+2, mid+1, r, q);
			}
	};
	
	class segment_tree_min{
		vector<int> seg;
		vector<int> lazy;
		int n;
		public:
			segment_tree_min(vector<int> &arr){
				seg.resize(arr.size()*4, -1);
				lazy.resize(arr.size()*4, 0);
				n = arr.size();
				build(0, 0, n-1, arr);
			}
			void build(int i, int l, int r, vector<int> &arr){
				if(l==r){
					seg[i] = arr[i];
					return;
				}
				int mid = (l+r)/2;
				build(2*i+1, l, mid, arr);
				build(2*i+2, mid+1, r, arr);
				seg[i] = min(seg[2*i+1], seg[2*i+2]);
				return;
			}
			
			void update_point(int i, int l, int r, vector<int> &q){
				if(l==r){
					seg[i] = q[1];
					return;
				}
				int mid = (l+r)/2;
				if(mid<=q[0])
					update_point(2*i+1, l, mid, q);
				else
					update_point(2*i+2, mid+1, r, q);
				seg[i] = min(seg[2*i+1], seg[2*i+2]);
				return;
			}
			
			void update_range(int i, int l, int r, vector<int> &q){
				if(lazy[i]!=0){
					seg[i] += lazy[i];
					if(l!=r){
						//this means that this node is not a leaf node and it has two childs
						lazy[2*i+1] += lazy[i];
						lazy[2*i+2] += lazy[i];
					}
					lazy[i] = 0;
				}
//				this should be treated as a query and so we have 3 overlap poss
				if(l>q[1] or r<q[0]){
					return;
				}
				if(l>=q[0] and r<=q[1]){
//					if complete overlap, then do the update here and pass on the lazy update to child nodes is present
					seg[i] += q[2];
					if(l!=r){
						lazy[2*i+1] += q[2];
						lazy[2*i+2] += q[2];
					}
					return;
				}
				int mid = (l+r)/2;
				update_range(2*i+1, l, mid, q);
				update_range(2*i+2, mid+1, r, q);
				seg[i] = min(seg[2*i+1], seg[2*i+2]);
				return;
			}
			
			int query(int i, int l, int r, vector<int> &q){
				if(lazy[i]!=0){
					seg[i] += lazy[i];
					if(l!=r){
						//this means that this node is not a leaf node and it has two childs
						lazy[2*i+1] += lazy[i];
						lazy[2*i+2] += lazy[i];
					}
					lazy[i] = 0;
				}
				if(l>q[1] or r<q[0]){
					return INT_MAX;
				}
				if(l>=q[0] and r<=q[1])
					return seg[i];
				int mid = (l+r)/2;
				return min(query(2*i+1, l, mid, q), query(2*i+2, mid+1, r, q));
			}
	};
	
	