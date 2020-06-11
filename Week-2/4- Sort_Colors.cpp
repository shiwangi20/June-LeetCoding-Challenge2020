class Solution {
public:
    void swap(int *a,int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sortColors(vector<int>& nums) {
        int i = 0,j = nums.size()-1,k = 0;
        while(i <= j){
            if(nums[i] == 0){
                if(i == k){
                    i++;
                    k++;
                }else{
                    swap(&nums[i],&nums[k]);
                    k++;
                }
            }else if(nums[i] == 1){
                i++;
            }else{
                swap(&nums[i],&nums[j]);
                j--;
            }
        }
    }
};
