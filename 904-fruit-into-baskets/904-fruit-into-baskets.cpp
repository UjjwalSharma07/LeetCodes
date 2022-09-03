class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0; 
        int j=0;
        int cnt=0;
        int k=2;
        
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            cnt++;
            
                if(mp.size()>k){
                    mp[fruits[i]]--;
                    cnt--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
            j++;
        }
        return cnt;
    }
};