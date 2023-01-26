class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while(l < r)
        {
            int w = r - l;
            int h = min(height[l],height[r]);
            res = max(res,w*h);
            if (height[l] < height[r])
                ++l;
            else if (height[l] > height[r])
                --r;
            else 
            {
                ++l;
                --r;
            }
        }
        return res;
    }
};