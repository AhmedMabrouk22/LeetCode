class Solution {

    int count(String str,char c) {
        int cnt = 0;
        for(int i = 0 ; i < str.length(); ++i)
            cnt += (str.charAt(i) == c ? 1 : 0);
        return cnt;
    }
    public int garbageCollection(String[] garbage, int[] travel) {
        int res = 0;
        int n = garbage.length;

        int em = 0 , eg = 0 , ep = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < garbage[i].length(); ++j) {
                if (garbage[i].charAt(j) == 'M') em = i;
                if (garbage[i].charAt(j) == 'G') eg = i;
                if (garbage[i].charAt(j) == 'P') ep = i;
            }
        }

        for(int i = 0 ; i < n ; ++i) {
            int m = 0,g = 0,p = 0;
            if (i <= em) {
                res += count(garbage[i],'M');
                if (i < em) res += travel[i];
            }
            if (i <= eg) {
                res += count(garbage[i],'G');
                if(i < eg) res += travel[i];
            }
            if (i <= ep) {
                res += count(garbage[i],'P');
                if (i < ep) res += travel[i];
            }

            
        }
        return res;
    }
}