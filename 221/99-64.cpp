class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(); if(m==0) return 0;
        int n=matrix[0].size();
        int **dp = new int*[m];
        int res=0;
        for(int i=0;i<m;++i){
            dp[i] = new int[n];
            dp[i][0] = (matrix[i][0]=='0')?0:1;
            if(dp[i][0]>res) res=dp[i][0];
        }
        for(int i=0;i<n;++i){
            dp[0][i] = (matrix[0][i]=='0')?0:1;
            if(dp[0][i]>res) res=dp[0][i];
        }

        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                int t = (matrix[i][j] == '1') ? 
                (min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1])) + 1 : 0;

                dp[i][j] = t;
                if(dp[i][j]>res) res = dp[i][j];
            }
        }
        return res*res;
    }
};