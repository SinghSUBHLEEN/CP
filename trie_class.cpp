class node{
		vector<node *> arr;
		bool flag;
	public:
		node(){
			arr.resize(26, NULL);
			flag = 0;
		}
		
		bool checkkey(char &ch){
			return arr[ch-'a'];
		}	
		
		void putkey(char &ch){
			arr[ch-'a'] = new node;
			return;
		}
		
		node *getref(char &ch){
			return arr[ch-'a'];
		}
		
		bool isend(){
			return flag;
		}
		
		void setend(){
			flag = 1;
			return;
		}
};

class Trie{
		node *root;
	public:
		Trie(){
			root = new node;
		}
		void insert(string s){
			node *temp = root;
			for(int i=0; i<s.size(); i++){
				if(!checkkay(s[i]))
					temp->putkey(s[i]);
				temp = temp->getref(s[i]);
			}
			temp->setend();
			return;
		}
		
		bool search(string s){
			node *temp = root;
			for(int i=0; i<s.size(); i++){
				if(!temp->checkkey(s[i])) return false;
				temp = temp->getref(s[i]);
			}
			return temp->isend();
		}
		
		bool prefix_search(string s){
			node *temp = root;
			for(int i=0; i<s.size(); i++){
				if(!temp->checkkey(s[i])) return false;
				temp = temp->getref(s[i]);
			}
			return true;
		}
};



