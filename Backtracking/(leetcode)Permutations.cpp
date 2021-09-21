class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permutations(nums, ans, 0);
        return ans;
    }
    
    void permutations(vector<int> &nums, vector<vector<int>> &ans, int i){
        //Base Case
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        
        //Recursive case
        for(int j=i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            permutations(nums, ans, i+1);
            
            //Backtracking - To restore the original array
            swap(nums[i], nums[j]);
        }
    
    }
};
