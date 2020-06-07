class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n == 0){
            if(amount == 0){
                return 1;
            }
            return 0;
        }
        int table[amount+1][n];
        for(int i = 0;i < n;i++){
            table[0][i] = 1;
        }
        for(int i = 1;i <= amount;i++){
            for(int j = 0;j < n;j++){
                int x = (i - coins[j] >= 0) ? table[i-coins[j]][j] : 0;
                int y = (j >= 1) ? table[i][j-1] : 0;
                table[i][j] = x + y;
            }
        }
        return table[amount][n-1];
    }
};
