class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0 || n == -2147483648){
            return false;
        }
        return !(n&n-1);
    }
};


