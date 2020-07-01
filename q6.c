/*
[Title] Subrectangle Queries
[Level] Medium
[Acceptance] 90.3%
[DATE] June. 22. 2020
[TIME] 4:00PM ~ 5:00PM (1h) 

[Reference Site] LeetCode.com

[Questions]
Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and supports two methods:
1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
2. getValue(int row, int col)
Returns the current value of the coordinate (row,col) from the rectangle.
 
[Example Output & Input]
(Example 1)
- Input
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
 - Output
[null,1,null,5,5,null,10,5]

- Explanation
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
// The initial rectangle (4x3) looks like:
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1

subrectangleQueries.getValue(0, 2); // return 1
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// After this update the rectangle looks like:
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5 

subrectangleQueries.getValue(0, 2); // return 5
subrectangleQueries.getValue(3, 1); // return 5
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// After this update the rectangle looks like:
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10 
subrectangleQueries.getValue(3, 1); // return 10
subrectangleQueries.getValue(0, 2); // return 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int max_row;
int max_col;
int arr[1000][1000];

int Get_update(int row1, int col1, int row2, int col2, int value){
    int i, j;
    //printf("\n %d %d %d %d %d", row1, col1, row2, col2, value);

    for(i=row1; i<=row2; i++){
        for(j=col1; j<=col2; j++){
            arr[i][j] = value;
        }
    }

    //print updated array
    printf("\n[updated array]\n");
    for(i=0; i<max_row; i++){
        for(j=0; j<max_col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int Get_Value(int (*a)[M], int row, int col){
    int x = row;
    int y = col;

    printf("value of arr[%d][%d]: %d\n", x, y, arr[x][y]);
    
    return 0;
}

int main(int argc, char* argv[])
{
    int i, j;
    printf("you will make N x M: ");
    scanf("%d %d", &N, &M);
    printf("\n");

    max_row=N;
    max_col=M;

    // make an array using input data
    // 1 2 1
    // 4 3 4
    // 3 2 1
    // 1 1 1

    for(i=0; i<N; i++){
        printf("Start to put the value of row%d\n", (i+1));
        for(j=0; j<M; j++){
            printf("put the value of arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    //print initialized array
    printf("\n[Initialized Array]\n");
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // call update function
    int row1, col1, row2, col2;
    int value;
    printf("\n[Update Function]\n");
    printf("please put row1, col1, row2, col2, value: ");
    scanf("%d %d %d %d %d", &row1, &col1, &row2, &col2, &value);
    Get_update(row1, col1, row2, col2, value);

    // get value function
    int x, y;
    printf("\n[Get Value Function]\n");
    printf("please put x and y of arr[x][y]: ");
    scanf("%d %d", &x, &y);
    Get_Value(arr, x, y);
    
    printf("\nThis Program is done!\n\n");
}

