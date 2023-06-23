// https://leetcode.com/problems/two-sum

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*) malloc(2*sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(i == j) {
                continue;
            } else {
                if(nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
    }

    return res;
}