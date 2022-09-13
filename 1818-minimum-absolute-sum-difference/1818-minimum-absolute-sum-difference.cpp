class Solution {
public:
   
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int MOD =  1e9+7;
        int n = nums1.size();
        long sum =0;
        vector<int>diff(n);
        for(int i=0; i<n; i++){
            // store diff of all element nums1-nums2 
            diff[i] = abs(nums1[i]-nums2[i])%MOD;
            // ans store sum of diff array
            sum = (sum+diff[i])% MOD;
        }
      
        // now sort the nums1 for finding lower bound of nums2 element;
        sort(nums1.begin(),nums1.end());
        // now make another array that will store optimal diffrence
        vector<int>arr(n);
        
        for(int i=0; i<n; i++){
            int j = lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            // this will give the index of just bada element of nums2[i] 
            
            if(j !=0 && j != n)
                // j !=0  and j != n bcoz for this case lowerbound give us -1 index or out of array index
                arr[i] = min(abs(nums2[i]-nums1[j]), abs(nums2[i]-nums1[j-1]) )%MOD;
                
             /* arr mai hum minimum store krenge ki nums2[i] se nums1[j] mtlb just bda element minus krne pr               chota element mil rha hai ta fir nums2[i] mai se nums1[j-1] mtlb ki jesa element tha vhi                       same minus krke par chota element mil rha hai dono mai se jo bhi chota hoga hum usko store                      kr lenge */
            
            else if(j == 0)
               arr[i]= abs(nums2[i]-nums1[j])%MOD;
            
            else if(j == n)
               arr[i] = abs(nums2[i]-nums1[j-1])%MOD;
            
        }
        int bestsaveEle =0;
        for(int i=0; i<n; i++){
         /*bestsave element hoga normal diff array or best save diff array mai se minus krke jo bhi hmee bada element milega uskoo agr total sum mai se minus krenge too utna diffrense hum save kr lenge */
            bestsaveEle = max(bestsaveEle,(diff[i]-arr[i])) %MOD;
        }
        return (MOD+sum-bestsaveEle)%MOD;
    }
};