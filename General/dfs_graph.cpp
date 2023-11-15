#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

	vector<int> bfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0), res;
		queue<int> q;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					int val=q.front();
					q.pop();
					res.push_back(val);
					for(auto it:adj[val]){
						if(!vis[it]){
							vis[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return res;
	}
	
	void helper(int i, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans){
			vis[i]=1;
			ans.push_back(i);
			for(int it:adj[i]){
				if(!vis[it])
					helper(it, vis, adj, ans);
			}
			return;
	}
	
	vector<int> recur_dfs(int n, vector<vector<int>> &adj){
		
		vector<int> vis(n+1, 0), ans;
		for(int i=1; i<=n; i++){
			if(!vis[i])
				helper(i, vis, adj, ans);
		}
		return ans;
	}
	
	vector<int> iter_dfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0), res;
		stack<int> q;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					int val=q.top();
					q.pop();
					res.push_back(val);
					for(auto it:adj[val]){
						if(!vis[it]){
							vis[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return res;
	}

	int main(){
		int n=8;
		vector<vector<int>> adj(n+1);
		adj[1]={3};
		adj[2]={5};
		adj[3]={1, 4};
		adj[4]={3};
		adj[5]={2, 6, 8};
		adj[6]={5, 7};
		adj[7]={6, 8};
		adj[8]={5, 7};
		vector<int> b = bfs(n, adj), d=iter_dfs(n, adj);
		for(auto it:d)
			cout<<it<<" ";
		getch();
		return 0;
	}