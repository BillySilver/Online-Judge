class Solution {
    int inner(int a1, int a2, int b1, int b2) {
        if ( a2 <= b1 || b2 <= a1 )
            return 0;

        if ( a2 < b2 )
            return a2 - max(a1, b1);
        else
            return b2 - max(b1, a1);
    }

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C-A)*(D-B) + (G-E)*(H-F) - inner(A, C, E, G)*inner(B, D, F, H);
    }
};
