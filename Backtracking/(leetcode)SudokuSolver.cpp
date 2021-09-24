class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();

        bool ans = sudoku(board, 0, 0, n); 
    }
    
    bool sudoku(vector<vector<char>> &board, int i, int j, int n){
        //Base Case
        if(i == n){
            return true;
        }
        
        //Row end case
        if(j == n){
            return sudoku(board, i+1, 0, n);
        }
        
        //skip the prefilled cells
        if(board[i][j] != '.'){
            return sudoku(board, i, j+1, n);
        }
        
        //Recursive Case
        for(int num=1; num <= n; num++){
            char tempNum = '0' + num;
            if(canPlace(board, i, j, n, tempNum)){
                board[i][j] = tempNum;
                
                bool status = sudoku(board, i, j+1, n);
                if(status){
                    return true;
                }
            }
        }
        
        //Backtracking
        board[i][j] = '.';
        return false;
    }
    
    
    bool canPlace(vector<vector<char>> &board, int i, int j, int n, char num){
        
        //check row and column
        for(int x=0; x < n; x++){
            if(board[x][j] == num || board[i][x] == num){
                return false;
            }
        }
        
        int rootN = sqrt(n);
        int startX = (i/3)*3;
        int startY = (j/3)*3;
        
        //check smaller sudoku box
        for(int x = startX; x < startX+rootN; x++){
            for(int y = startY; y < startY+rootN; y++){
                if(board[x][y] == num){
                    return false;
                }
            }
        }
        return true;
    }  
};


