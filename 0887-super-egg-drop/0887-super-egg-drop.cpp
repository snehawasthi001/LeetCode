class Solution {
public:
    int dp[10001][101];

    int solve(int f, int e) {

        if (f == 0 || f == 1)
            return f;

        if (e == 1)
            return f;

        if (dp[f][e] != -1)
            return dp[f][e];

        int low = 1;
        int high = f;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int eggBreak = solve(mid - 1, e - 1);
            int eggNotBreak = solve(f - mid, e);

            int temp = 1 + max(eggBreak, eggNotBreak);

            ans = min(ans, temp);

            if (eggBreak < eggNotBreak) {
                // Need to go higher
                low = mid + 1;
            }
            else {
                // Need to go lower
                high = mid - 1;
            }
        }

        return dp[f][e] = ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};