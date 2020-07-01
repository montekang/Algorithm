/*
[Title] Non-decreasing Array
[Level] Easy
[Acceptance] 19.5%
[DATE] June. 22. 2020
[TIME] 1:30PM ~ 4:00PM + 5:00 ~ 6:50 (4h 20m) 

[Reference Site] LeetCode.com

[Question]
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

[Example Output & Input]
(Example 1)
- Input: nums = [4,2,3]
- Output: true
- Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

(Example 2)
- Input: nums = [4,2,1]
- Output: false
- Explanation: You can't get a non-decreasing array by modify at most one element.
*/

/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

[Example 1]
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

[Example 2]
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
*/

// v1: change the value

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i, j;
    int n = argc;       //argc = (amount of argument) + 1
     nums[n];
    int count[n];
    int res = 1; 

    //initializing count array
    for(i=0; i<(n-1); i++){
        count[i] = 0;
    }

    // make num array 
    for(i=1; i<argc; i++){
        nums[i-1] = atoi(argv[i]);
        //printf("count[%d] = %d\n", i, count[i]);
    }
    //printf("\n\n");

    for (i=0; i<(n-2); i++){
        for (j=i; j<(n-1); j++){
            if (nums[i] > nums[j]){
                count[i]++;
            }
        }
    }

    //algorithm part
    for(i=0; i<(n-2); i++){
        if (count[i] >= 2){
            for(j=0; j<(n-1); j++){
                if(j != i){
                    if(count[j] >= 1){
                        res = 0;    //False
                    }
                }
            }
        }
        //printf("count[%d] = %d\n", i, count[i]);
    }

    //printf("\nres = %d\n\n", res);

    //Pinrt Input and Output
    printf("Input: nums = [");
    for(i=1; i<argc; i++){
        
        if(i == (argc-1)){
            printf("%d", atoi(argv[i]));
        }
        else{
            printf("%d, ", atoi(argv[i]));
        }
    }
    printf("]\n");

    //Output
    printf("Output: ");
    if(res == 0){
        printf("False\n");
    }

    else if(res == 1){
        printf("True\n");
    }
}    
