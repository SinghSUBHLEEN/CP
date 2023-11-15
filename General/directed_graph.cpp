#include<bits/stdc++.h>

using namespace std;

	void heirholzer(int node, vector<vector<int>> &adj, vector<int> &ans){
		while(!adj[node].empty()){
			auto it = adj[node].back();
			adj[node].pop_back();
			heirholzer(it, adj, ans);
		}
		ans.push_back(node);
		return;
	}
	
	void topo_dfs(int i, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans){
		vis[i]=1;
		for(auto it:adj[i]){
			if(!vis[it])
				topo_dfs(it, vis, adj, ans);
		}
		ans.push_back(i);
		return;
	}
	
	vector<int> topo_sort_dfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0), ans;
			if(!vis[i]){
				topo_dfs(i, vis, adj, ans);
			}
		}
		
		reverse(begin(ans), end(ans));return ans;
	}
		queue<int> q;
		for(int i=0; i<=n; i++){
			for(auto it:adj[i])
				incentre[it]++;
		}
		for(int i=0; i<=n; i++)
			if(!incentre[i])	q.push(i);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for(auto it:adj[node]){
				if(incentre[it]>0)
					incentre[it]--;
				if(!incentre[it])
					q.push(it);
			}
		}
		return ans.size()!=n+1;
	}
	
	vector<int> topo_sort_bfs(int n, vector<vector<int>> &adj){
		vector<int> incentre(n+1, 0), ans;
		for(int i=0; i<=n; i++){
			for(auto it:adj[i])
				incentre[it]++;
		}
		queue<int> q;
		for(int i=0; i<=n; i++)
			if(incentre[i]==0)
				q.push(i);
				
		while(!q.empty()){
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for(auto it:adj[node]){
				if(incentre[it]>0)
					incentre[it]--;
				if(!incentre[it])
					q.push(it);
			}
		}
		return ans;
	}

	vector<int> bfs(int n, vector<vector<int>> &adj){
		vector<int> res, vis(n+1, 0);
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				queue<int> q;
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					int val = q.front();
					q.pop();
					res.push_back(val);
					for(auto it:adj[val]){
						if(!vis[it]){
							q.push(it);
							vis[it]=1;
						}
					}
				}
			}
		}
		return res;
	}
	
	int main(){
		int n1=5, n2=4;
		vector<vector<int>> adj1(n1+1), adj2(n2+1);
		adj1[2]={3};
		adj1[3]={1};
		adj1[4]={0, 1};
		adj1[5]={0, 2};
		adj2[1]={2};
		adj2[2]={3};
		adj2[3]={4};
		adj2[4]={2};
		vector<int> ans = topo_sort_bfs(n1, adj1);
		for(auto it:ans)
			cout<<it<<' ';
		cout<<endl;
		cout<<detect_cycle_BFS_kahn_algo(n2, adj2);
		return 0;
	}