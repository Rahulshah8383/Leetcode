class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0;i<board.size();i++){
            if(board[row][i] == ch){
                return false;
            }
            if(board[i][col] == ch){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch){
                return false;
            }
        }
        return true;
    }

    bool solver(vector<vector<char>>& board){
        int size = board.size();

        for(int row=0;row<size;row++){
            for(int col=0;col<size;col++){
                if(board[row][col] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board, row, col, ch)){
                            board[row][col] = ch;
                            bool flag = solver(board);
                            if(flag){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};
