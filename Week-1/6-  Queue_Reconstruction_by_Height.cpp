class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b){
			     return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
             });
        int n = people.size();
        vector<vector<int>> result;
        for(int i = 0;i < n;i++){
            result.insert(result.begin()+people[i][1],people[i]);
        }
        return result;
    }
};
