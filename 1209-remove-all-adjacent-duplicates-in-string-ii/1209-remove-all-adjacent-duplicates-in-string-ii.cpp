class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int i=0; 
        while(i<s.length()){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                auto it = st.top().first;
        
                if(it == s[i]){
                    st.top().second++;
                }
                else{
                    st.push({s[i],1});
                }
            }
            auto it = st.top();
            if(it.second == k){
                st.pop();
            }
            i++;
        }
        string ans=""; 
            while(!st.empty()){
                auto it = st.top();
                st.pop();
                int i = it.second;
                while(i--){
                    ans+=it.first;
                }
            }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};