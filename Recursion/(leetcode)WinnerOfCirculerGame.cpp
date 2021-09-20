class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> Q;
        for(int i=1; i <= n; i++){
            Q.push(i);
        }
        
        int winner = Game(n, k, Q);
        return winner;
    }
    
    int Game(int n, int k, queue<int> Q){
        //Base Case
        if(Q.size() == 1){
            return Q.front();
        }
        
        int pointer = 1;
        
        while(pointer < k){
            int contestant = Q.front();
            Q.pop();
            Q.push(contestant);
            pointer++;
        }
        
        Q.pop();
        
        int ans = Game(n, k, Q);
        return ans;
    }
};
