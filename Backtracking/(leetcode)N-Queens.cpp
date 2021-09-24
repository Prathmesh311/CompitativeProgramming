class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        //Making initital matrix
        for(int i=0; i < n; i++){
            temp.push_back(".");
            for(int j=1; j < n; j++){
                temp[i] = temp[i] + '.';
            }
        }

        bool status =  NQueens(n, ans, temp, 0, 0);
        return ans;
    }
    
    bool NQueens(int n, vector<vector<string>> &ans, vector<string> &temp, int i, int j){
        //Base Case
        if(i == n){
            ans.push_back(temp);
            return true;
        }
        
        
        //Recursive Case
        for(int j = 0; j < n; j++){
            if(canPlace(temp, i, j, n)){
                temp[i][j] = 'Q';
                
                bool status = NQueens(n, ans, temp, i+1, j);
                
                //Backtracking
                temp[i][j] = '.';
            }
        }
        return false;
        
    }
    
    bool canPlace(vector<string> &temp, int i , int j, int n){
        
        //Check Row and Column
        for(int x = 0; x < n; x++){
            if(temp[x][j] == 'Q' || temp[i][x] == 'Q'){
                return false;
            }
        }
        
        
        //Checking cross positions
        int x = i;
        int y= j;
        
        while(x >= 0 && y < n){
            if(temp[x][y] == 'Q'){
                return false;
            }
            x--;
            y++;
        }
        
        x = i;
        y = j;
        
        while(x >= 0 && y >= 0){
            if(temp[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }
        
        return true;
        
    }
    
};

