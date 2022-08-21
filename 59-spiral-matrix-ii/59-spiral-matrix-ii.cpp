class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n,vector<int>(n,0));
       
        int left = 0;
        int right = n-1;
        int top = 0;
        int down = n-1;
        int count =1;
        while(top<=down && left<=right){
            for(int i=left; i<=right; i++){
                arr[top][i] = count;
                count++;
            }
            top++;
            
            for(int i=top; i<=down; i++){
                arr[i][right] = count;
                count++;
            }
            right--;
            
            if(top<=down){
                for(int i=right; i>=left;i--){
                    arr[down][i] = count;
                    count++;
                }
                down--;
            }
            
            if(left<=right){
                for(int i=down; i>=top; i--){
                    arr[i][left] = count;
                    count++;
                }
                left++;
            }
        }
        return arr;
    }
};