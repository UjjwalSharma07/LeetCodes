class Solution {
public:
    int minSetSize(vector<int>& arr) {
      
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        
        // greater<int> for desending order 
        multimap<int,int,greater<int>>desendingmap;
        for(auto j:mp){
            desendingmap.insert({j.second,j.first});
        }
        int sum = arr.size();
        int count =0;
       
        for(auto it = desendingmap.begin(); it!= desendingmap.end(); it++){
            sum -= it->first;
            count++;
            if(sum <= arr.size()/2)
                return count;
        }
        return count;
    }
};