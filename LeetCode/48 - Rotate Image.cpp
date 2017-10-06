class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int oi, oj;
        for (int i=0; i < (n >> 1); ++i) {
            oi = n-1 - i;
            for (int j=i; j < oi; ++j) {
                oj = n-1 - j;
                swap(matrix[i][j], matrix[j][oi]);
                swap(matrix[i][j], matrix[oi][oj]);
                swap(matrix[i][j], matrix[oj][i]);
            }
        }
    }
};
