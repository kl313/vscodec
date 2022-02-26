#include <stdio.h>

int main()
{
    int i, j, k;
    
    for (i=1; i <= 4; i++)
    {
      for (j=1, k = 0; j <= 6; j++, k++)
      {
          if (k % j == 0)
          printf ("\n");
          printf ("%d\t", i*j);
      }

    }
    printf("\n");
    
    return 0;
}
