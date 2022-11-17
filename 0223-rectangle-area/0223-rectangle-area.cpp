class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // supose rectangle A and rectangle B
        int areaofA = (ax2-ax1)*(ay2-ay1);
        int areaofB = (bx2-bx1)*(by2-by1);
        
        int overlap=0;
        
        int overlapA = min(ax2,bx2)-max(ax1,bx1);
        int overlapB = min(ay2,by2)-max(ay1,by1);
        
        if(overlapA>0 && overlapB>0){
            overlap = overlapA*overlapB;
        }
        return (areaofA+areaofB)-overlap;
    }
};