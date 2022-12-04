class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        
        for(auto i:s){
            mp[i]++;
        }
        
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            char topChar = pq.top().second;
            int freqChar = pq.top().first;
            pq.pop();
            while(freqChar--){
                ans.push_back(topChar);
            } 
        }
        return ans;
    }
};