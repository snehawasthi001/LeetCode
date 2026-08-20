class Solution {
public:

    int minCut(string s) {

        int n = s.size();

        // pal[i][j] = true agar s[i...j] palindrome hai
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Palindrome table banana
        for(int len = 1; len <= n; len++) {

            for(int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // Length 1
                if(len == 1) {
                    pal[i][j] = true;
                }

                // Length 2
                else if(len == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }

                // Length > 2
                else {
                    pal[i][j] = (s[i] == s[j]) &&
                                pal[i + 1][j - 1];
                }
            }
        }


        // dp[i] = s[0...i] ke liye minimum cuts
        vector<int> dp(n);

        for(int i = 0; i < n; i++) {

            // Agar s[0...i] itself palindrome hai,
            // toh koi cut nahi chahiye
            if(pal[0][i]) {
                dp[i] = 0;
                continue;
            }

            dp[i] = i;  // Maximum possible cuts

            // Last palindrome part s[j...i] choose karo
            for(int j = 1; j <= i; j++) {

                if(pal[j][i]) {

                    // s[j...i] palindrome hai
                    // toh sirf s[0...j-1] ko cut karna padega
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};