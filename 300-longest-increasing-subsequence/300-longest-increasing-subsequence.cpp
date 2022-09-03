class Solution {
public:
//     int lengthOfLIS(vector<int>& nums) {
//         int maxi=INT_MIN;
//         int length=0;
//         int n= nums.size();
//         vector<int>temp;
      
//         for(int i=0; i<n;i++){
//             maxi = nums[i];
//             temp.push_back(maxi);
//             for(int j=i+1; j<n;j++){
//                 if(nums[j]>maxi){
//                    maxi = nums[j];
//                    temp.push_back(nums[j]);
//                 }
//             }
//             int size = temp.size();
//             for(int i=0; i<temp.size(); i++){
//                 cout<<temp[i]<<" ";
//             }cout<<endl;
//             length = max(size,length);
//             temp.clear();
//         }
//         return length;
//     }
    
//     recursive way
    
//     int solve(int n,int curr,int prev,vector<int>& nums){
//         if(curr == n){
//             return 0;
//         }
//         // include
//         int take = 0;
//         if(prev == -1 || nums[curr]>nums[prev])
//             take = 1+solve(n,curr+1,curr,nums);
        
//         // exclude
//         int notake= 0+solve(n,curr+1,prev,nums);
        
//         return max(take,notake);
//     }
    
//     ********DP memoaization********                      
    
     int solveMem(int n,int curr,int prev,vector<int>& nums,vector<vector<int> >&dp){
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        // include
        int take = 0;
        if(prev == -1 || nums[curr]>nums[prev])
            take = 1+solveMem(n,curr+1,curr,nums,dp);
        
        // exclude
        int notake= 0+solveMem(n,curr+1,prev,nums,dp);
        
        return dp[curr][prev+1]=max(take,notake);
    }
    int solveoptimal(int n,vector<int>& nums){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        // int curr= 0;
        // int prev= -1;
        // return solve(n,0,-1,nums);
        
//         vector<vector<int> >dp(n,vector(n+1,-1));
//         return solveMem(n,0,-1,nums,dp);
        
        return solveoptimal(n,nums);
    }
};