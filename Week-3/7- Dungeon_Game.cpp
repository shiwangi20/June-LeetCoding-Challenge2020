class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if(n == 0){
            return 0;
        }
        int m = dungeon[0].size();
        if(m == 0){
            return 0;
        }
        for(int i = n-1;i >= 0;i--){
            for(int j = m-1;j >= 0;j--){
                if(i == (n-1) && (j == m-1)){
                    if(dungeon[i][j] >= 0){
                        dungeon[i][j] = 1;
                    }else{
                        dungeon[i][j] = (-1*dungeon[i][j]) + 1;
                    }
                    continue;
                }
                if(i == (n-1)){
                    if(dungeon[i][j] >= 0){
                        dungeon[i][j] = max(1,dungeon[i][j+1] - dungeon[i][j]);
                    }else{
                        dungeon[i][j] = (-1*dungeon[i][j] + dungeon[i][j+1]);
                    }
                    continue;
                }
                if(j == (m-1)){
                    if(dungeon[i][j] >= 0){
                        dungeon[i][j] = max(1,dungeon[i+1][j] - dungeon[i][j]);
                    }else{
                        dungeon[i][j] = (-1*dungeon[i][j] + dungeon[i+1][j]);
                    }
                    continue;
                }
                if(dungeon[i][j] >= 0){
                    dungeon[i][j] = min(max(1,dungeon[i][j+1] - dungeon[i][j]),
                                        max(1,dungeon[i+1][j] - dungeon[i][j]));
                }else{
                    dungeon[i][j] = -1*dungeon[i][j] + min(dungeon[i][j+1],dungeon[i+1][j]);
                }
            }
        }
        return dungeon[0][0];
    }
};
