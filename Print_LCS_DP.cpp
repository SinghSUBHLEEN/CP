#include<bits/stdc++.h>

using namespace std;

	string helper(string &s1, string &s2, vector<vector<int>> &dp){
		for(int i=0; i<s1.size(); i++) dp[i][0] = 0;
		for(int i=0; i<s2.size(); i++) dp[0][i] = 0;
		
		for(int i=1; i<=s1.size(); i++){
			for(int j=1; j<=s2.size(); j++){
				if(s1[i-1]==s2[j-1])
					dp[i][j] = 1+dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		int i=s1.size(), j=s2.size();
		int ind = dp[i][j];
		string ans(ind, 'a');
		while(i>0 and j>0){
			if(s1[i-1] == s2[j-1]){
				ans[ind-1] = s1[i-1];
				ind--;
				i--;
				j--;
			}
			else if(dp[i-1][j] < dp[i][j-1]) j--;
			else i--;
		}
		return ans;
	}
	
	void lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];


  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  
  // Printing the sub sequences
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}
	
	int main(){
		char S1[] = "delete";
  		char S2[] = "leet";
  		int m = strlen(S1);
  		int n = strlen(S2);
	
 		lcsAlgo(S1, S2, m, n);
	}
	
//	int main(){
//		string s1 = "delete", s2 = "leet";
//		vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, 0));
//		cout<<helper(s1, s2, dp);
//		return 0;
//	}