class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int infixPoint = 0;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                infixPoint =i;
                break;
            }
        }
        if(infixPoint == 0){
            sort(nums.begin(),nums.end());
        }
        else{
            int min = INT_MAX;
            int twoSwap = nums[infixPoint-1];
            for(int j=infixPoint; j<nums.size(); j++){
                if(nums[j]-twoSwap >0 && nums[j]-twoSwap<min){
                    int temp = nums[j];
                    nums[j] = nums[infixPoint-1];
                    nums[infixPoint-1] = temp;
                }
            }
            sort(nums.begin()+infixPoint,nums.end());
        }
    }
};