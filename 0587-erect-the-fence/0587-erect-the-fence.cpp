class Solution {
public:
    int findEquationVal(pair<int,int>& p1,pair<int,int>&p2, pair<int,int> p3){
        int x1 = p1.first , y1 = p1.second;
        int x2 = p2.first , y2 = p2.second;
        int x3 = p3.first , y3 = p3.second;
        
        return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees),end(trees));
        vector<vector<int>>ans;
        
        deque<pair<int,int>>upper,lower;
        
        for(auto &point : trees){
            int l = lower.size();
            int u = upper.size();
            
            while(l>=2 && findEquationVal(lower[l-2],lower[l-1],{point[0],point[1]})<0){
                l--;
                lower.pop_back();
            }
            while(u>=2 && findEquationVal(upper[u-2],upper[u-1],{point[0],point[1]})>0){
                u--;
                upper.pop_back();
            }
            upper.push_back({point[0],point[1]});
            lower.push_back({point[0],point[1]});
        }
        set<pair<int,int>>st;
        for(auto &point : upper){
            st.insert(point);
        }
        for(auto &point : lower){
            st.insert(point);
        }
        for(auto &point : st){
            ans.push_back({point.first,point.second});
        }
        return ans;
    }
};