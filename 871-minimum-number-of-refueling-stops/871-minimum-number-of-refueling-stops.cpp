class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // step 1 : initially startfueal tk ja skta hai
        int maxreach = startFuel;
        
        // make a max heap jisse ki always max fuel mile target ko corss krne k liye
        priority_queue<int>pq;
        int i=0;
        int count =0;
        while(maxreach < target){
            
         // stations[distance] jab tk choti ya eual hai maxreach k tb tk loop chlega
            
            while(i<stations.size() && stations[i][0]<=maxreach){
                
                // heap mai fuel dalenge jisse ki max fuel mile humko or min iterations mai target                    cross kree
                
                pq.push(stations[i][1]);
                i++;
            }
            // heap empty hua mtlb ki startfuel kam h or maxreach jyada so target tk phuchna                      imposible h
            if(pq.empty())
                return -1;
            
            else{
                maxreach += pq.top();
                pq.pop();
                count++;
            }
        }
        return count;
    }
};