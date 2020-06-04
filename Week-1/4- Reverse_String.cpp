// reverse a string using O(1) extra space

// Approach
// swap the i and n-ith character till mid
// Example : s = ["h","e","l","l","o"]
// After swaping output = ["o","l","l","e","h"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0;i < n/2;i++){
            char ch = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = ch;
        }
    }
};
