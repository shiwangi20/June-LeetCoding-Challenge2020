class Solution {
public:
    int numTrees(int n) {
        int *dp = new int[n+1];
        for(int i = 0;i <= n;i++){
            dp[i] = -1;
        }
        dp[0] = 1;
        dp[1] = 1;
        return count(n,dp);
    }
    int count(int n,int *dp){
        if(dp[n] != -1){
            return dp[n];
        }
        int sum = 0;
        for(int i = 1;i <= n;i++){
            sum += (count(i-1,dp)*count(n-i,dp));
        }
        dp[n] = sum;
        return dp[n];
    }
};
