#include<bits/stdc++.h>

using namespace std;

	    class segment_tree{
		vector<long long int> seg;
		public:
			segment_tree(vector<int> &nums){
				seg.resize(4*nums.size(), -1ll);
				build(0, 0, nums.size()-1, nums);
			}
        
			void build(int i, int l, int r, vector<int> &nums){
                if(l==r){
                    seg[i] = nums[l];
                    return;
                }
                int mid = l+(r-l)/2;
                build(2*i+1, l, mid, nums);
                build(2*i+2, mid+1, r, nums);
                seg[i] = seg[2*i+1]+seg[2*i+2];
                return;
            }
        
			long long query(int i, int l, int r, vector<int> &q){
                if(q[0]<=l and q[1]>=r) return seg[i];
                if(q[0]>r or l>q[1]) return 0ll;
                int mid = l+(r-l)/2;
                long long left = query(2*i+1, l, mid, q);
                long long right = query(2*i+2, mid+1, r, q);
                return left+right;
            }
        
			void update_point(int i, int l, int r, vector<long long> &q, vector<int> &nums){
                if(l==r){
                    seg[i] = nums[l] = q[1];
                    return;
                }
                int mid = l + (r-l)/2;
                if(q[0]<=mid)
                    update_point(2*i+1, l, mid, q, nums);
                else
                    update_point(2*i+2, mid+1, r, q, nums);
                seg[i] = seg[2*i+1]+seg[2*i+2];
                return;
            }
	};
	
	int main(){
		nums = {2,2,8,2,-1,0,5,6,4,-8};
		vector<int> q = {2, 4};
		seg.resize(4*nums.size(), -1);
		build_segment_tree(0, 0, nums.size()-1);
		cout<<query_min(0, 0, nums.size(), q);
		cout<<endl;
		return 0;
	}