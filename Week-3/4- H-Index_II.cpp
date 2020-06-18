class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0){
            return 0;
        }
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(citations[mid] >= n-mid){
                ans = n-mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
