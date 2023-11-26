class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int res = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0; j < m ; ++j) {
                if (i > 0 && matrix[i][j] != 0)
                    matrix[i][j] += matrix[i-1][j];
            }

            int[] cur = matrix[i].clone();
            Arrays.sort(cur);
            for(int x = 0 ; x < m ;++x) res = Math.max(res,cur[x] * (m-x));
        }

        return res;
    }
}