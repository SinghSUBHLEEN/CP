
 class Disjoint_set{
 	public:
 		vector<int> parent;
 		vector<int> rank;
 		Disjoint_set(int n, int s){
 			parent.resize(n+s, -1);
 			rank.resize(n+s, 0);
 			for(int i=s; i<n+s; i++)
 				parent[i] = i;
		}
		
		int findParent(int node){
			if(node==parent[node])
				return node;
			return parent[node] = findParent(parent[node]); 
		}
		
		void unionn(int u, int v){
			u = findParent(u);
			v = findParent(v);
			if(rank[u]>rank[v])
				parent[v] = u;
			else if(rank[v]>rank[u])
				parent[u] = v;
			else{
				parent[v] = u;
				++rank[u];
			}
			return;
		}
 };