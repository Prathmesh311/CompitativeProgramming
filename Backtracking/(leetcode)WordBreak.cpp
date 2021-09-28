class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> docs;
        int n = s.size();
        string str = "";
        
        //return findWord(s, wordDict, docs, str, n, 0);
        return wb(s, wordDict);
    }
    
    bool wb(string s, vector<string> &wordDict){       //Without generating vector of words
        //Base Case
        if(s.size() == 0){
            return true;
        }
        
        //Recursive Case
        for(int i=1; i <= s.size(); i++){
            cout<<s.substr(0,i)<<" ";
            if(find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end() && wb(s.substr(i), wordDict)){
                cout<<123;
                return true;
            }
        }
        return false;
    }
    
    bool findWord(string s, vector<string> &wordDict, vector<string> &docs, string str, int n, int start){  // Full code with word vector generation
        //Base Case
        if(start == n){
            
            for(int i=0; i < docs.size(); i++){
                cout<<docs[i]<<" ";
                if(find(wordDict.begin(), wordDict.end(), docs[i]) == wordDict.end()){
                    return false;
                }
            }
            return true;
        }
        
        //Recursive Case
        for(int i=start; i < n; i++){
            str = str + s[i];
            if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                docs.push_back(str);
                str = "";
                bool status = findWord(s, wordDict, docs, str, n, i+1);
                
                if(status == true){
                    return true;
                }
                
                //Backtracking
                str = docs.back();
                docs.pop_back();
                
            }
        }
        
        return false;
    }
};
