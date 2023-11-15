#include<bits/stdc++.h>

using namespace std;

	class segment_tree{
		vector<int> seg;
		public:
			segment_tree(vector<int> &nums){
				seg.resize(4*nums.size(), -1);
				build(0, 0, nums.size()-1, nums);
			}
			void build(int , int, int, vector<int> &);
			int query(int, int, int , vector<int> &);
			void update(int, int , int , vector<int> &, vector<int> &);
	};
	
	void segment_tree::update(int i, int l, int r, vector<int> &q, vector<int> &nums){
		if(l==r){
			seg[i] = nums[l] = q[1];
			return;
		}
		int mid = l + (r-l)/2;
		if(q[0]<=mid)
			segment_tree::update(2*i+1, l, mid, q, nums);
		else
			segment_tree::update(2*i+2, mid+1, r, q, nums);
		seg[i] = min(seg[2*i+1], seg[2*i+2]);
		return;
	}
	
	void segment_tree::build(int i, int l, int r, vector<int> &nums){
		if(l==r){
			seg[i] = nums[l];
			return;
		}
		int mid = l+(r-l)/2;
		segment_tree::build(2*i+1, l, mid, nums);
		segment_tree::build(2*i+2, mid+1, r, nums);
		seg[i] = min(seg[2*i+1], seg[2*i+2]);
		return;
	}
	
	int segment_tree::query(int i, int l, int r, vector<int> &q){
		if(q[0]<=l and q[1]>=r) return seg[i];
		if(q[0]>r or l>q[1]) return INT_MAX;
		int mid = l+(r-l)/2;
		int left = segment_tree::query(2*i+1, l, mid, q);
		int right = segment_tree::query(2*i+2, mid+1, r, q);
		return min(left, right);
	}
	
	int main(){
		#ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("out.txt", "w", stdout);
		#endif
		vector<int> nums = {2, -1, 0, -2, 3, 4, 5}, q = {1, 2};
		segment_tree seg(nums);
		cout<<seg.query(0, 0, nums.size()-1, q);
		string str = "letsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcode";
		cout<<str.size();
		return 0;
	}