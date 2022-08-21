class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // for(auto i:intervals){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }
        
        int i=1;
        int count =0;
        while(i<intervals.size()){
            if(intervals[i][0]<intervals[i-1][1]){
                intervals[i][1] = min(intervals[i-1][1],intervals[i][1]);
               
                count++;
            }
            i++;
        }
        return count;
    }
};