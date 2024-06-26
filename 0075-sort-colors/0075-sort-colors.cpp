class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0 , w = 0 , b =0;
        for(auto i : nums)
        {
            r += i == 0;
            w += i == 1;
            b += i == 2;
        }
        
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if (r)
            {
                 nums[i] = 0;
                --r;
            } else if (w)
            {
                nums[i] = 1;
                --w;
            } else {
                nums[i] = 2;
                --b;
            }
            
        }
    }
};