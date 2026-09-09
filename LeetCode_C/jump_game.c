#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReachable = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReachable) {
            return false;
        }
        maxReachable = (i + nums[i] > maxReachable) ? i + nums[i] : maxReachable;
        if (maxReachable >= numsSize - 1) {
            return true;
        }
    }
}

int main() {
    int nums[] = {2,3,1,1,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    bool result = canJump(nums, numsSize);
    printf("%s", result ? "true" : "false");
    return 0;
}