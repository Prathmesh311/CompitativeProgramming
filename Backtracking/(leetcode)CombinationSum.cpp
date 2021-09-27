class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> comb;
        
        std::sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        
        combinations(candidates, ans, comb, target, n, 0, 0);
        std:: vector v(ans.begin(), ans.end());
        return v;
    }
    
    void combinations(vector<int> &candidates, set<vector<int>> &ans, vector<int> &comb,int target, int n, int sum, int z){
        //Base Case
        if(sum == target){
            ans.insert(comb);
            return;
        }
        
        
        //Recursive Case
        for(int i=z; i < n && (target-sum) >= candidates[i]; i++){
            comb.push_back(candidates[i]);
            combinations(candidates, ans, comb, target, n, sum + candidates[i], i);
            
            //Backtracking
            comb.pop_back();
        }
    }
};
