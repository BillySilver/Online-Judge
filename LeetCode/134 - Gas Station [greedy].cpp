class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int trueStart = gas.size();
        for (int i = 0; i < trueStart; ++i) {
            tank += gas[i] - cost[i];
            if ( tank < 0 ) {
                do {
                    --trueStart;
                    if ( i == trueStart )
                        return -1;

                    tank += gas[trueStart] - cost[trueStart];
                } while ( tank < 0 );
            }
        }

        return trueStart % gas.size();
    }
};
