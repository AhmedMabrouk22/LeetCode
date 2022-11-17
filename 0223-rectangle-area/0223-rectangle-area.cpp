class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int areaA = (ay2 - ay1) * (ax2 - ax1);
        int areaB = (by2 - by1) * (bx2 - bx1);
        
        int l = max(ax1,bx1);
        int r = min(ax2,bx2);
        int x_overlap = r-l;
        
        int top = min(ay2,by2);
        int bot = max(ay1,by1);
        int y_overlap = top-bot;
        
        int areaOverlap = 0;
        if(x_overlap > 0 && y_overlap > 0)
            areaOverlap = (x_overlap * y_overlap);
        
        return areaA + areaB - areaOverlap;
    }
};