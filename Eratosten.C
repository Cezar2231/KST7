#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int x;
    scanf("%d", &x);
    
    bool* arr= (bool*) malloc ( (x+1) * sizeof(bool) );
    memset(arr, 0 ,(x+1) * sizeof(bool) );
    
    for (int i = 2 ; i <= x; i++)
    {
        for (int j = i+i ; j <= x; j+= i)
        {
            arr[j] = true;
        }
    }
    
     for (int i = 2 ; i <= x; i++)
     {
         if(!arr[i])
         {
             printf("%d ", i);
         }
     }
     
    return EXIT_SUCCESS;

}
