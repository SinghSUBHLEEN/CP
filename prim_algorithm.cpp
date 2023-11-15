#include<bits/stdc++.h>

using namespace std;

	int main(){
		int n=5;
		vector<vector<pair<int, int>>> adj(n);
		adj[0] = {{1, 2}, {3, 6}};
		adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
		adj[2] = {{2, 3}, {4, 7}};
		adj[3] = {{0, 6}, {1, 8}};
		adj[4] = {{1, 5}, {2, 7}};
		vector<int> parent(n, -1), key(n, 1e8);
		vector<bool> mst(n, false);
		key[0] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 0});
		for(int i=0; i<n-1; i++){
			int mini = INT_MAX, node;
			auto val = pq.top();
			pq.pop();
			mini = val.first;
			node = val.second;
			//Brute force
//			Use proiority queue to optimise the process of checking for getting the minvalue and node value corresponding to it
//			for(int j=0; j<n; j++){
//				if(!mst[j] and key[j]<mini){
//					mini = key[j];
//					node = j;
//				}
//			}
			
			mst[node] = true;
			for(auto it:adj[node]){
				if(!mst[it.first] and key[it.first]>it.second){
					key[it.first] = it.second, parent[it.first] = node;
					pq.push({it.second, it.first});
				}
			}
		}
		for(int i=0; i<n; i++)
			cout<<parent[i]<<"--"<<i<<endl;
		return 0;
	}