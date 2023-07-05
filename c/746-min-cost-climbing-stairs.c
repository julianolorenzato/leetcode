// https://leetcode.com/problems/min-cost-climbing-stairs

int minCostClimbingStairs(int* cost, int costSize){
    int i = 2;

    for(i; i < costSize; i++) {
        if(cost[i - 1] > cost[i - 2]) {
            cost[i] += cost[i - 2];
        } else {
            cost[i] += cost[i - 1];
        }
    }

    if(cost[i - 1] > cost[i - 2]) {
        return cost[i - 2];
    } else {
        return cost[i - 1];
    }
}