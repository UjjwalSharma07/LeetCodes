class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
         if(pushed.size()!= popped.size())
            return 0;
        int i=0;
        int j=0;
        stack<int>st;
        while(i<pushed.size() ){
           st.push(pushed[i]);
           
           while(!st.empty() && st.top()==popped[j]){
               st.pop();
               j++;
           }
           i++;
        }
        if(st.empty())
            return 1;
        return 0;
    }
};