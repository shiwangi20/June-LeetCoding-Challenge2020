class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int flag = 0;
        if(nums[0] != 1){
            flag = 1;
            nums.insert(nums.begin(),1);
        }
        int size = nums.size();
        int dp[size][2];
        for(int i = size-1;i >= 0;i--){
            dp[i][0] = 0;
            dp[i][1] = i;
            for(int j = i+1;j < size;j++){
                if(nums[j]%nums[i] == 0){
                    if(dp[j][0] > dp[i][0]){
                        dp[i][0] = dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            dp[i][0]++;
        }
        int i = 0;
        vector<int> ans;
        ans.push_back(nums[i]);
        while(dp[i][1] != i){
            i = dp[i][1];
            ans.push_back(nums[i]);
        }
        if(flag){
            ans.erase(ans.begin());
        }
        return ans;
    }
};
