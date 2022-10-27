class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>vp1,vp2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vp1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vp2.push_back({i,j});
                }
            }
        }
        int max_overlap=0;
        map<pair<int, int>, int> translate; 
        
        for(auto i : vp1){
            for(auto j : vp2){
                
                // calculate the translation (coordinate-shift) required for a 
				// img1 point to overlap  img2 point
				
                int x = j.first - i.first;
                int y = j.second - i.second;
                translate[{x, y}]++;
                
                max_overlap = max(max_overlap, translate[{x, y}]);
            }
        }
        return max_overlap;
    }
};