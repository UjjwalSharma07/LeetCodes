class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftbar = height[0];
        int rightbar = height[n-1];
        int ans = 0;
        while(left<=right){
            if(leftbar<rightbar){
                if(leftbar<height[left]){
                    leftbar = height[left];
    
                }
                else{
                    ans += leftbar-height[left];
                    left++;
                }
            }
            else{
                if(rightbar<height[right]){
                    rightbar = height[right];
                }
                else{
                    ans += rightbar-height[right];
                    right--;
                }
            }
        }
        return ans;  
    }
};