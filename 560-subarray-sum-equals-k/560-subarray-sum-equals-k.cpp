class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // this solution time complexity O(n^2) so this will give TLE
        
//         int count=0;
//         for(int i =0; i<nums.size(); i++){
//             int sum = nums[i];
//             if(sum == k)
//                 count++;
//             for(int j=i+1; j<nums.size(); j++){
//                 sum+=nums[j];
                
//                 if(sum == k)
//                     count++;
//             }
//         }
//         return count;
        
        
        // hashmap approach 
        
        unordered_map<int,int>mp;
        int sum = 0;
        int res = 0;
        mp[0]=1;
        
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(mp.find(sum-k) != mp.end()){
                res+=mp[sum-k];
            }
            mp[sum]++;
        }
        return res;  
    }
};