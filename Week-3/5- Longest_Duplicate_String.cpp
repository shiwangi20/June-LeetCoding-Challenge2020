#include<unordered_map>
class Solution {
    int prime = 10000007;
    vector<int> power;
public:
    string longestDupSubstring(string S) {
        int n = S.length(), low = 0, high = n-1;
        power = vector<int>(n);
        for(int i = 0; i < n; i++){
            power[i] = (i == 0) ? 1 : (power[i-1] * 26) % prime;
        }
        string ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            string temp = rabinKarp(S, mid);
            if(temp.length() > ans.length()) {
                ans = temp;
                low = mid+1;
            } else  high = mid-1;
        }
        return ans;
    }
    
    string rabinKarp(string s, int len) {
        if(len == 0)    return "";
        int n = s.size(), curr = 0;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < len; i++) {
            curr = (curr * 26 + (s[i]-'a')) % prime;
        }
        hash[curr] = {0};
        for(int i = len; i < n; i++) {
            curr = ((curr - power[len-1] * (s[i-len]-'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i]-'a')) % prime;
            if(hash.find(curr) == hash.end())   hash[curr] = {i-len+1};
            else {
                for(int index: hash[curr]) {
                    if(s.substr(index, len) == s.substr(i-len+1, len))  return s.substr(index, len);
                }
                hash[curr].push_back({i-len+1});
            }
        }
        return "";
    }
};
