class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     
        int firstele = INT_MAX;
        int secondele = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]<=firstele)
                firstele = nums[i];
            
            else if(nums[i]<=secondele){
                secondele = nums[i];
            }
            
            else  //third element
                return true;
        }
        
        return false;
    }
};