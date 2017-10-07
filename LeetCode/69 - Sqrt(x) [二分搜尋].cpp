class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = 1 << 16;
        int mid;
        while ( l <= r ) {
            mid = (l + r) >> 1;
            if ( x < double(mid)*mid )
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l-1;
    }
};
