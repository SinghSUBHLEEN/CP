#include<bits/stdc++.h>

using namespace std;

    class segment_tree_max{
		vector<pair<int, int>> seg;
        int n;
		public:
			segment_tree_max(vector<int> &nums){
				seg.resize(4*nums.size());
                n = nums.size();
				build(0, 0, nums.size()-1, nums);
			}
			
            void build(int i, int l, int r, vector<int> &nums){
                if(l==r){
                    seg[i] = {nums[l], l};
                    return;
                }
                int mid = l+(r-l)/2;
                build(2*i+1, l, mid, nums);
                build(2*i+2, mid+1, r, nums);
                if(seg[2*i+1].first>seg[2*i+2].first){
                    seg[i] = seg[2*i+1];
                }
                else if(seg[2*i+1].first<seg[2*i+2].first){
                    seg[i] = seg[2*i+2];
                }
                else{
                    seg[i].first = seg[2*i+1].first;
                    seg[i].second = max(seg[2*i+1].second, seg[2*i+2].second);
                }
                return;
            }
        
            pair<int, int> query_util(int i, int l, int r, int lq, int rq){
                if(lq<=l and rq>=r) return seg[i];
                if(lq>r or l>rq) return {INT_MIN, INT_MIN};
                int mid = l+(r-l)/2;
                auto left = query_util(2*i+1, l, mid, lq, rq);
                auto right = query_util(2*i+2, mid+1, r, lq, rq);
                if(left.first>right.first) return left;
                else if(right.first>left.first) return right;
                else return {left.first, max(left.second, right.second)};
            }
            
            pair<int, int> query(int l, int r){
                return query_util(0, 0, n-1, l, r);
            }
            
            void update_util(int i, int l, int r, int idx, int val, vector<int> &nums){
            	if(l==r){
					seg[i] = {val, l};
            		nums[l] = val;
            		return;
            	}
            	int mid = l + (r-l)/2;
            	if(idx<=mid)
            		update_util(2*i+1, l, mid, idx, val, nums);
            	else
            		update_util(2*i+2, mid+1, r, idx, val, nums);
            	// seg[i] = min(seg[2*i+1], seg[2*i+2]);
				if(seg[2*i+1].first>seg[2*i+2].first){
					seg[i] = seg[2*i+1];
				}
				else if(seg[2*i+2].first>seg[2*i+1].first){
					seg[i] = seg[2*i+2];
				}
				else{
					// do the math for index ot get left or right indices
					if(seg[2*i+1].second>seg[2*i+2].second)
						seg[i] = seg[2*i+2];
					else
						seg[i] = seg[2*i+1];
				}
            	return;
            }
        
            void update(int idx, int val, vector<int> &nums){
                update_util(0, 0, n-1, idx, val, nums);
                return ;
            }
	};
	
	int main(){
		#ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		#endif
		vector<int> nums = {2, -1, 0, -2, 3, 4, 5};
		segment_tree_max seg(nums);
		vector<int> q = {2, nums.size()-1};
		cout<<seg.query(1,  4).first<<" "<<seg.query(1, 4).second<<endl;
		// cout<<seg.query(0, 0, nums.size()-1, q);
		// string str = "letsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcodeletsleetcode";
		// cout<<str.size();
		return 0;
	}