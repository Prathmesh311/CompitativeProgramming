class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = nums.size();
        
        
        generateSubset(nums, ans, sub, n, 0);
        return ans;
    }
    
    void generateSubset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &sub, int n, int i){
        //Base Case
        if(i == n){
            ans.push_back(sub);
            return;
        }
        
        //Recursive Case
        //Including ith Element
        sub.push_back(nums[i]);
        generateSubset(nums, ans, sub, n, i+1);
        //Backtracking
        sub.pop_back();
        
        //Excluding ith Element
        generateSubset(nums, ans, sub, n, i+1);
        
        
        return;
    }
};

