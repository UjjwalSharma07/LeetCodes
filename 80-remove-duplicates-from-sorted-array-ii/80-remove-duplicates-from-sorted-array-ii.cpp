class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int k=2;
        if(nums.size()<=k)
            return nums.size();
        
        int i=1;
        int count = 1;
        for(int j=1; j<nums.size(); j++){
            if(nums[j] != nums[j-1]){
                nums[i++]=nums[j];   
                count = 1;
            }
            else {
                if(count<k){
                    nums[i++] = nums[j];
                    count++;
                }
            }              
        }
        return i;
    }
};