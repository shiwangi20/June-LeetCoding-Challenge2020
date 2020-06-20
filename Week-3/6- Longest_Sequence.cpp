class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        int fact = 1;
        for(int i = 1;i <= n;i++){
            fact = fact * i;
            nums.push_back(i+'0');
        }
        k--;
        string res = "";
        while(n){
            fact = fact / n;
            int index = k/fact;
            res += nums[index];
            nums.erase(nums.begin() + index);
            k = k%fact;
            n--;
        }
        return res;
    }
};
