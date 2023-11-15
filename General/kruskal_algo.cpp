#include<bits/stdc++.h>

using namespace std;

	struct node{
		int w;
		int u;
		int v;
		node(int f, int s, int weight){
			w = f, u = s, v = weight;
		}
	};
	
	static bool comp(struct node &a, struct node &b){
		return (a.w<b.w);
	}
	
	int findParent(int u, vector<int> &parent){
		if(u==parent[u])
			return u;
		return parent[u] = findParent(parent[u], parent);
	}
	
	void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
		u = findParent(u, parent);
		v = findParent(v, parent);
		if(rank[u]<rank[v])
			parent[u] = v;
		else if(rank[v]<rank[u])
			parent[v] = u;
		else{
			parent[v] = u;
			rank[u]++;
		}
		return ;
	}
	
	vector<pair<int, int>> kruskal_min_span_tree(int n, vector<node> &graph){
		vector<pair<int, int>> mst;
		vector<int> parent(n), rank(n, 0);
		for(int i=0; i<n; i++)
			parent[i] = i;
		sort(begin(graph), end(graph), comp);
		int cost = 0;
		for(auto it:graph){
			if(findParent(it.u, parent) != findParent(it.v, parent)){
				cost += it.w;
				mst.push_back({it.u, it.v});
				unionn(it.u, it.v, parent, rank);
			}
		}
		cout<<cost<<endl;
		return mst;
	}
	
	int main(){
		vector<node> graph;
		graph.push_back(node(1, 1, 4));
		graph.push_back(node(2, 1, 2));
		graph.push_back(node(3, 2, 3));
		graph.push_back(node(3, 2, 4));
		graph.push_back(node(4, 1, 5));
		graph.push_back(node(5, 3, 4));
		graph.push_back(node(7, 2, 6));
		graph.push_back(node(8, 3, 6));
		graph.push_back(node(9, 4, 5));
		int n = 7;
		vector<pair<int, int>> ans = kruskal_min_span_tree(n, graph);
		for(auto it:ans)
			cout<<it.first<<"--"<<it.second<<endl;
		return 0;
	}