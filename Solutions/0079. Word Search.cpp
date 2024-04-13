class Solution {
public:
    bool Helper(vector<vector<char>>& board, string word, int n, int m, int row, int col, int index){
        if(index == word.size()){
            return true;
        }

        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '*';

        bool a = Helper(board, word, n, m, row+1, col, index + 1);
        bool b = Helper(board, word, n, m, row, col+1, index + 1);
        bool c = Helper(board, word, n, m, row-1, col, index + 1);
        bool d = Helper(board, word, n, m, row, col-1, index + 1);
        
        board[row][col] = temp;
        return a || b || c || d; 
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Helper(board, word, n, m, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
