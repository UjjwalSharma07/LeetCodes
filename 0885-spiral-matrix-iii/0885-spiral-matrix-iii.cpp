class Solution {
public:
    bool check(int i,int j,int n,int m){
        if(i<0 || j<0 || j>=m || i>=n) 
            return false;
        return true;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int len=1;
        
        while(ans.size()<rows*cols){
            for(int i=1; i<=len; i++){
                if(check(rStart,cStart+i,rows,cols)){  // move right
                    ans.push_back({rStart,cStart+i});
                } 
            }
            cStart+=len;
            for(int j=1; j<=len; j++){      // move down
                if(check(rStart+j,cStart,rows,cols)){
                    ans.push_back({rStart+j,cStart});
                }
            }
            rStart+=len;
            len++;
            
            for(int i=1; i<=len; i++){   // move left
                if(check(rStart,cStart-i,rows,cols)){
                    ans.push_back({rStart,cStart-i});
                }
            }
            cStart-=len;
            for(int j=1; j<=len; j++){  // move up
                if(check(rStart-j,cStart,rows,cols)){
                    ans.push_back({rStart-j,cStart});
                }
            }
            rStart-=len;
            len++;
        }
        return ans;
    }
};