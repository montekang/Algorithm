/**
[Title] Shuffle an array
[Level] Easy
[Acceptance] 89.3%
[DATE] June. 20. 2020
[TIME] 2:40PM ~ 3:00PM (20m) 

[Reference Site] LeetCode.com

[Questions]
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

[Example Output & Input]
(Example 1)
- Input: nums = [1,2,3,4]
- Output: [1,3,6,10]
- Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

(Example 2)
- Input: nums = [1,1,1,1,1]
- Output: [1,2,3,4,5]
- Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

(Example 3)
- Input: nums = [3,1,2,10,1]
- Output: [3,4,6,16,17]
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i, j;
    int length = (argc - 1);
    int nums[length];

    // print input data
    printf("Input: nums = [");
    for (i=0; i<length; i++)
    {
        nums[i] = atoi(argv[i+1]);
        if(i==(length-1))
        {
            printf("%d", nums[i]);
        }
        else{
            printf("%d,", nums[i]);
        }
    }
    printf("]\n");

    //print output data
    printf("Output: nums = [");
    for (i=0; i<length; i++){
        for (j=0; i-j>0; j++){
            nums[i] += atoi(argv[j+1]); 
        }
        if(i==(length-1))
        {
            printf("%d", nums[i]);
        }
        else{
            printf("%d,", nums[i]);
        }
    }
    printf("]\n");
}