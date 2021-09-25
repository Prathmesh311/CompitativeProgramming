class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> unique;
       
        combinations(comb, unique, n, k, 1);
        return unique;
    }
    
    void combinations(vector<int> &comb, vector<vector<int>> &unique, int n, int k, int z){
        //Base Case
        if(comb.size() == k){
            unique.push_back(comb);
            return;
        }
        
        
        //Recursive Case  
        for(int i = z; i <= n; i++){
            comb.push_back(i);
            combinations(comb, unique, n, k, i+1);
            
            //Backtracking
            comb.pop_back();
        }
        return;
    }
};

