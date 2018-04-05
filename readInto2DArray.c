#include<stdio.h>
int main()
{
  int puzzle[9][9];
  int i, j;


  for(i=0; i<9; i++)
  {
    for(j=0;j<9;j++)
    {
      scanf("%d", &puzzle[i][j]);
    }
  }
  for(i=0; i<9; i++)
  {
    for(j=0;j<9;j++)
    {
      printf("%d ", puzzle[i][j]);
      if(j==8)
      {
        printf("\n");
      }
    }
  }
  return 0;
}
