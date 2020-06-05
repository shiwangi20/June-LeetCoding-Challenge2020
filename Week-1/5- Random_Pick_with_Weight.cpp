class Solution {
public:
    vector<int> w_sum;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i = 0;i < w.size();i++){
            sum += w[i];
            w_sum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int n = w_sum.back();
        int ind = rand()%n;
        auto it = upper_bound(w_sum.begin(), w_sum.end(),ind);
        return it - w_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
