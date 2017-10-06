class Solution {
    void setZeroesRow(vector<vector<int>>& matrix, int r) {
        for (int j = 0; j < matrix[0].size(); ++j)
            matrix[r][j] = 0;
    }
    void setZeroesColumn(vector<vector<int>>& matrix, int c) {
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][c] = 0;
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        // use 0th row/column to record zero rows/columns.
        bool zero0thR = false, zero0thC = false;

        // check if the 0th row/column will be zeroes.
        for (int i = 0; i < matrix.size(); ++i)
            if ( 0 == matrix[i][0] )
                zero0thC = true;

        for (int j = 0; j < matrix[0].size(); ++j)
            if ( 0 == matrix[0][j] )
                zero0thR = true;

        // start recording.
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 1; j < matrix[0].size(); ++j)
                if ( 0 == matrix[i][j] )
                    matrix[i][0] = matrix[0][j] = 0;

        // set zeroes.
        for (int i = 1; i < matrix.size(); ++i)
            if ( 0 == matrix[i][0] )
                setZeroesRow(matrix, i);

        for (int j = 1; j < matrix[0].size(); ++j)
            if ( 0 == matrix[0][j] )
                setZeroesColumn(matrix, j);

        if ( zero0thR )
            setZeroesRow(matrix, 0);

        if ( zero0thC )
            setZeroesColumn(matrix, 0);
    }
};
