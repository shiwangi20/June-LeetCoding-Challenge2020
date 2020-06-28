class Solution {
public:
    vector<string> ans;
    unordered_map<string,vector<string>> umap;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.size() == 0){
            return ans;
        }
        for(int i = 0;i < tickets.size();i++){
            if(umap.find(tickets[i][0]) == umap.end()){
                vector<string> v;
                umap[tickets[i][0]] = v;
            }
            umap[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto i = umap.begin();i != umap.end();i++){
            sort((i->second).begin(),(i->second).end(),greater<string>());
        }
        dfs("JFK");
        return ans;
    }
    void dfs(string cur){
        while(umap[cur].size() != 0){
            string des = umap[cur].back();
            umap[cur].pop_back();
            dfs(des);
        }
        ans.insert(ans.begin(),cur);
    }
};
