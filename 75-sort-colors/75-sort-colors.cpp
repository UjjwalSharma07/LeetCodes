class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;;
        int e = nums.size()-1;
        int s=0;
        while(i<=e){
            if(nums[i]==0){
                swap(nums[i],nums[s]);
                i++;
                s++;
            }
            else if(nums[i] == 1){
                i++;
            }
            else{
                swap(nums[i],nums[e]);
                e--;
            }
        }
    }
};