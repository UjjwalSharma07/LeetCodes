class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=n-1;
        int score=0;
        int maxscore= 0;
        while(i<=j){
            
            // face up
            if(tokens[i]<=power){
                power = power-tokens[i];
                score++;
                maxscore = max(score,maxscore);
                i++;
            }
            else if(power<tokens[j] && score>0){
                power = power+tokens[j];
                score--;
                j--;
            }
            else
                break;
        }
        return maxscore;
    }
};