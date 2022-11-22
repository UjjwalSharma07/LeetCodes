class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>arr;
        sort(begin(nums),end(nums));
        set<vector<int>>st;
        
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int l = j+1;
                int r = nums.size()-1;
                
                while(l<r){
                    long long sum = (long long) nums[i]+nums[j]+nums[l]+nums[r];
                    
                    if(sum == target){
                        vector<int>pairs(4);
                        pairs[0] = nums[i];
                        pairs[1] = nums[j];
                        pairs[2] = nums[l];
                        pairs[3] = nums[r];
                        
                        st.insert(pairs);
                        l++;
                        r--;
                    }
                    else if(sum>target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};