class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        int mid;

        while ( l <= r ) {
            mid = (l + r) >> 1;
            if ( target == matrix[mid / n][mid % n] )
                return true;

            if ( target < matrix[mid / n][mid % n] )
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};
