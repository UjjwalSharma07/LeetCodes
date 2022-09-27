class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int time = 1;
        char prev = '.';
        // traverse left to right
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                time = 1;
                prev = 'R';
                continue;
            }
            else if(dominoes[i] == 'L'){
                time = 1;
                prev = 'L';
            }
            else if(dominoes[i] == '.' && prev == 'R'){
                right[i] = time;
                time++;
            }     
        }
        // traverse right to left
        prev ='.';
        time = 1;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L'){
                time = 1;
                prev = 'L';
                continue;
            }
            else if(dominoes[i] == 'R'){
                time = 1;
                prev = 'R';
            }
            else if(dominoes[i] == '.' && prev == 'L'){
                left[i] = time;
                time++;
            }     
        }
        string ans = "";
        
        for(int i=0; i<n; i++){
            if(left[i] == 0 && right[i]==0){
                ans.push_back(dominoes[i]);
            }
            else if(left[i]==0){
                ans.push_back('R');
            }
            else if(right[i] == 0){
                ans.push_back('L');
            }
            else if(left[i] == right[i]){
                ans.push_back('.');
            }
            else if(left[i]<right[i]){
                ans.push_back('L');
            }
            else{
                ans.push_back('R');
            }
        }
        return ans;
    }
};