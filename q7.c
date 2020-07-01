/*
[Title] Reducing Dishes
[Level] Hard
[Acceptance] 73%
[DATE] June. 23. 2020
[TIME] 2:10PM ~ 4:00PM (1h 50m) 

[Reference Site] LeetCode.com

[Question]
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

[Example Output & Input]
(example 01)
- Input: satisfaction = [-1,-8,0,5,-9]
- Output: 14
- Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.

(example 02)
- Input: satisfaction = [4,3,2]
- Output: 20
- Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

(example 03)
- Input: satisfaction = [-1,-4,-5]
- Output: 0
- Explanation: People don't like the dishes. No dish is prepared.

(example 04)
- Input: satisfaction = [-2,5,-1,0,3,-3]
- Output: 35
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i, j, x, y, z;
    int max_num = (argc-1);  // the amount of parameter = (argc - 1)
    int check = 0;  // 0: no negative value on arguments 1: at least 1 negative value on arguments
    int res = 0;
    int temp_res = 0;
    int arr[max_num];

    /* initializing time array */
    int time[max_num];
    int temp=0;
    for(i=0; i<max_num; i++){
        time[i] = (i+1);
        //printf("time[%d] = %d\n", i, time[i]);
    }

    /* initializing satisfaction array */
    int satisfaction[max_num];
    for (i=0; i<max_num; i++){
        satisfaction[i] = atoi(argv[(i+1)]);
        //printf("satisfaction[%d] = %d\n", i, satisfaction[i]);
        if (satisfaction[i] < 0 ){
            check = 1;  // has a negative value.
        }
    }

    /* sort the satisfaction values */
    for (i=0; i<max_num; i++){
        for(j=(i+1); j<max_num; j++){
            if(satisfaction[i] > satisfaction[j]){
                temp = satisfaction[i];
                satisfaction[i] = satisfaction[j];
                satisfaction[j] = temp;
            }
        }
    }

    /* [case 1] no negative value */
    if(check == 0){
        for(i=0; i<max_num; i++){
            res += (time[i] * satisfaction[i]);
        }
    }

    /* [case 2] at least 1 negative value */
    /* calculate part */
    for(y=0; y<max_num; y++){
        temp_res = 0;
        x=0;
        for(z=y; z<max_num; z++){
            temp_res += (time[x] * satisfaction[z]);
            //printf("temp_res = %d * %d = %d\n", time[x], satisfaction[z], temp_res);
            x++;
        }
        arr[y] = temp_res;        
        res = arr[0];    
        //printf("\narr[%d] = %d\n\n", y, arr[y]);
        if(y>=1){
            if(arr[y] > arr[y-1]){
                res = arr[y];
            }
        }
    }

    /* get the res value & sort the arr[] values */
    for (i=0; i<max_num; i++){
        for(j=(i+1); j<max_num; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }        
    }

    res = arr[max_num-1];
    if (res < 0){
        res = 0;
    }

    /* print result (input) */
    printf("Input(original): satisfacton = {");
    for(i=1; i<=max_num; i++){
        if (i==(max_num)){
            printf("%d}", atoi(argv[i]));
        }
        else{
            printf("%d, ", atoi(argv[i]));
        }
    }

    /* print result (sorted input) */
    printf("\nInput(sorted)  : satisfacton = {");
    for(i=0; i<=(max_num-1); i++){
        if (i==(max_num-1)){
            printf("%d}", satisfaction[i]);
        }
        else{
            printf("%d, ", satisfaction[i]);
        }
    }

    /* print result (output) */
    printf("\nOutput\t       : %d\n", res);
}