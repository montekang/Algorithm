/*
[Title] The 3n+1 Problem
[Level] 1(easy)
[Acceptance] Low
[DATE] June. 16. 2020
[TIME] 7:00PM ~ 8:00PM (1h) 

[Reference Site] BOOK: Programming Challenges 

[Example Output & Input]
[input]     [output]
1 10        1 10 20
100 200     100 200 125
201 210     201 210 89
900 1000    900 1000 174
*/

#include <stdio.h>

func_even(int n){
    int res;
    res = n/2;
    return res;
}

func_odd(int n){
    int res;
    res = (n*3) + 1;
    return res;
}

int main( int argc, char *argv[] )
{
    int i, j, n;
    int cycle;
    int cycle_res = 1;

    // get the value from the input.
    printf("type the first value in range of cycle: ");
    scanf ("%d", &i);
    printf("type the second value in range of cycle: ");
    scanf ("%d", &j);

    if (i >1000000 || j >1000000)
    {
        printf("\n[error!] please put the value less than 1000000 for both i and j\n\n");
    }

    else
    {

        int val = i;

        while (i < j)
        {
            n = i;
            cycle = 1;
            while (n != 1 && n > 0)
            {
                cycle ++;
                if(n%2 == 0){
                    n = func_even(n);
                }
                
                else if (n%2 == 1){
                    n = func_odd(n);
                }
            }
            if (cycle_res <= cycle)
            {
                cycle_res = cycle;
            }
            i++; 
        }

        printf("%d %d %d\n", val, j, cycle_res);
    }
}