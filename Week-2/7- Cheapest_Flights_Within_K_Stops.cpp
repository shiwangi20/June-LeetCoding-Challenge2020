#include<bits/stdc++.h>
class Solution {
public:
    int min_cost = INT_MAX;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> graph[n];
        for(int i = 0;i < flights.size();i++){
            int s = flights[i][0];
            int d = flights[i][1];
            int c = flights[i][2];
            graph[s].push_back(make_pair(d,c));
        }
        vector<bool> visited(n,false);
        visited[src] = true;
        getCost(src,dst,K,graph,visited,0);
        return min_cost == INT_MAX ? -1 : min_cost;
    }
    void getCost(int src,int des,int K,vector<pair<int,int>> graph[],vector<bool> &visited,int current_cost){
        
        if(src == des){
            min_cost = current_cost;
            return;
        }
        if(K < 0){
            return;
        }
        for(int i = 0;i < graph[src].size();i++){
            pair<int,int> p = graph[src][i];
            int d = p.first;
            int c = p.second;
            if(current_cost + c > min_cost){
                continue;
            }
            if(!visited[d]){
                visited[d] = true;
                getCost(d,des,K-1,graph,visited,current_cost+c);
                visited[d] = false;
            }
        }
    }
    
};
