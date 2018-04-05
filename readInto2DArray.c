#include<stdio.h>
int main(){

   int disp[9][9];

   int i, j;
   for(i=0; i<9; i++) {
      for(j=0;j<9;j++) {
         // printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%d", &disp[i][j]);
      }
   }

   printf("Two Dimensional array elements:\n");
   for(i=0; i<9; i++)
   {
      for(j=0;j<9;j++)
      {
         printf("%d ", disp[i][j]);
         if(j==8)
         {
            printf("\n");
         }
      }
   }
   return 0;
}
