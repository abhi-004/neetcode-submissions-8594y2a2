class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool>(n, false));

        int start = 0;
        int maxLength = 1;

        for (int i=0; i<n; i++){
            dp[i][i] = true;
        }

        for (int i=0; i<n-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;

                start = i;
                maxLength = 2;
            }
        }

        for (int gap=2; gap<n; gap++){
            for (int i=0; i<n-gap; i++){
                int j = i+gap;

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;

                    if(gap+1 > maxLength){
                        start = i;
                        maxLength = gap+1;
                    }
                }

            }
        }

        return s.substr(start, maxLength);
    }
};
