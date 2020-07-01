/*
[Title] Minesweeper
[Level] 1(easy)
[Acceptance] High
[DATE] June. 16. 2020
[TIME] 8:00PM ~ 10:40PM (2h 40m) 

[Reference Site] BOOK: Programming Challenges 

[Example Output & Input]
[input]     [output]
4 4         Field #1:
*...        *100
....        2210
.*..        1*10
....        1110

3 5         Field #2:
**...       **100
.....       33200
.*...       1*100

0 0         end the game

*/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
    int n=1, m=1; // 0< n,m <=100
    int field=1;  // field number
    int i, j;
    int count=0;
    char res;
    // char value;


    while (n!=0 && m!=0)
    {
        printf("put the value of the size of minesweeper game n * m: ");
        scanf ("%d %d", &n, &m);
        printf("test n=%d m=%d\n\n ", n, m);

        printf("[important!] please put only '*' for mine or '.' for nothing\n\n");
        
        char arr[n][m];

        // get the value for minesweeper
        for (i=0; i<n; i++){
            for (j=0; j<m; j++){
                printf("[test] i=%d, j=%d\n", i, j);
                printf("value: ");
                scanf(" %c", &arr[i][j]);
            }
            printf("\n\n");
        }

        //print input data
        printf("[Input Data]\n");
        for (i=0; i<n; i++){
            for (j=0; j<m; j++){
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }

        //print the result
        printf("\n\nField #%d\n", field);
        for (i=0; i<n; i++){
            for (j=0; j<m; j++){
                if (arr[i][j] == '*')
                {
                    printf("*");
                }
                else
                {
                    //get the count
                    int x, y;
                    for(x=-1; x<=1; x++){
                        for(y=-1; y<=1; y++){
                            //&& ((i+x-1) != i) && ((j+y-1) != j
                            if ( ((i+x) >= 0) && ((j+y) >=0) ) {
                                if(arr[i+x][j+y] == '*'){
                                    //printf("[+]");
                                    count++;
                                }
                                // else if (arr[i][j] == '*'){
                                //     count--;
                                // }
                            }

                        }
                    }
                    printf("%d", count);
                    count = 0;
                }
                //printf("%c ", arr[i][j]);
            }
            printf("\n");
        }
        field++;
    }

    
}
 