class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sum=0;
        int count=0;
        sort(people.begin(),people.end());
        
        int i=0;
        int j = people.size()-1;
        
        while(i<=j){
            if(people[i]+people[j] <= limit){
                i++;
                j--;
            }
            else
                j--;
            count++;
        }
        return count;
    }
};