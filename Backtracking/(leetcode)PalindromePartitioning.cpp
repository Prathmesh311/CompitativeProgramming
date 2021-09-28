class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pal;
        int n = s.size();
        string str = "";
                
        palindromePartitions(s, ans, pal, str, n, 0);
        return ans;
    }
    
    void palindromePartitions(string s, vector<vector<string>> &ans, vector<string> &pal, string &str, int n, int z){
        //Base Case
        if(z == n){
            ans.push_back(pal);
            return;
        }
        
        //Recursive Case
        for(int i=z; i < n; i++){
            str = str + s[i];
            if(isPalindrome(str)){
                pal.push_back(str);
                str = "";
                palindromePartitions(s, ans, pal, str, n, i+1);
                
                //Backtracking
                str = pal.back();
                pal.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(string str){
        int len = str.size();
        int mid = len/2;
        
        if(len == 1){
            return true;
        }
        
        int i=0;
        while(i < mid){
            if(str[i] != str[len-i-1]){
                return false;
            }
            i++;
        }
        return true;
    }
};
