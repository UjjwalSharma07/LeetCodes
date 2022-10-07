class MyCalendarThree {
public:
    map<int,int>mp;
    int maxi=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count =0;
        for(auto i:mp){
           count += i.second;
           maxi = max(maxi,count);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */