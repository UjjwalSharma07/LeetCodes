class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int dupli = -1;
        int missEle = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]){
                dupli = nums[i];
            }
            else if(nums[i-1]+1 < nums[i]){
                missEle = nums[i-1]+1;
            }
        }
        return {dupli,nums.back() != n ? n : missEle};
    }
};