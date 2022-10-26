class Solution {
public:
    int minOperations(vector<int>& nums) {
        // brute force
        
//         int n = nums.size(); 
//         int ans=n;
        
//         sort(nums.begin(),nums.end());
//         nums.erase(unique(begin(nums),end(nums)),end(nums));
//         int m = nums.size();
        
//         for(int i=0; i<m; i++){
//             int j=0;
//             while(j<m && nums[j]<nums[i]+n)
//                 j++;
//             ans = min(ans,n-j+i);
//         }
//         return ans;
        
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        sort(begin(nums),end(nums));
        nums.erase(unique(begin(nums),end(nums)),end(nums));
        
        int m = nums.size();
        
        while(j<m){
            while(nums[i]+n<=nums[j]){
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return n-ans;
    }
};