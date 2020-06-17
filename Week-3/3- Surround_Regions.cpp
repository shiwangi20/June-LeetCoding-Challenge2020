class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n <= 2){
            return;
        }
        int m = board[0].size();
        if(m <= 2){
            return;
        }
        for(int i = 0;i < m;i++){
            if(board[0][i] == 'O'){
                fillBoard(board,0,i,n,m);
            }
            if(board[n-1][i] == 'O'){
                fillBoard(board,n-1,i,n,m);
            }
        }
        for(int i = 1;i < n-1;i++){
            if(board[i][0] == 'O'){
                fillBoard(board,i,0,n,m);
            }
            if(board[i][m-1] == 'O'){
                fillBoard(board,i,m-1,n,m);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == 'N'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void fillBoard(vector<vector<char>> &board,int row,int col,int n,int m){
        if(row < n && row >= 0 && col < m && col >= 0 && board[row][col] == 'O'){
            board[row][col] = 'N';
            fillBoard(board,row,col-1,n,m);
            fillBoard(board,row-1,col,n,m);
            fillBoard(board,row,col+1,n,m);
            fillBoard(board,row+1,col,n,m);
        }
    }
};
