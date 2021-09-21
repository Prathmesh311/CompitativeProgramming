class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        
        uniquePermutations(nums, s, 0);
        std::vector v(s.begin(), s.end());

        return v;
    }
    
    void uniquePermutations(vector<int> &nums, set<vector<int>> &s, int i){
        //Base Case
        if(i >= nums.size()){
            s.insert(nums);            
            return;
        }
        
        //Recursive Case
        for(int j=i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            uniquePermutations(nums, s, i+1);
            
            //Backtracking - To retrive the original array
            swap(nums[i], nums[j]);
        }
    }
};
