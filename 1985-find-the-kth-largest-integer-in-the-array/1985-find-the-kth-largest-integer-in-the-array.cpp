class Solution {
public:
    bool static cmp( const string& a , const string& b){
        return( a.size()!=b.size())? ( a.size()>b.size()) :(a>b);
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums),end(nums),cmp);
        
        return nums[k-1];
    }
};