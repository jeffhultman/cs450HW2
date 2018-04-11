#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> 

void *threaded_function(void *thread_args);
int valid_square(int puzzle[9][9], int square_number);
void print_list(int puzzle[9][9]);

struct thread_arguments
{
    int puzzle[9][9];
    int square_or_col_or_box;
    int number;
    

};

int main()
{
  long thread_id;

  pthread_t* thread_handles;
  thread_handles = malloc(27 * sizeof(pthread_t));
  
  int i, j;



  struct thread_arguments thread_args;
  for(i=0; i<9; i++)
  {
    for(j=0;j<9;j++)
    {
      scanf("%d", &thread_args.puzzle[i][j]);
    }
  }
  print_list(thread_args.puzzle);
  thread_args.square_or_col_or_box = -1;
  for (i=0;i<27;i++)
  {
    thread_args.number = i;
    if (i%9 == 0 )
      thread_args.square_or_col_or_box++;
    pthread_create(&thread_handles[i], NULL, threaded_function, (void*) &thread_args);
  }
  for (i = 0; i<27; i++)
  {
    pthread_join(thread_handles[i], NULL);
  } 
  return 0;
}

void *threaded_function(void *thread_args)
{
    struct thread_arguments *thread_args1 = (struct thread_arguments *)thread_args;
    int number = thread_args1->number;
    if (number >= 9 && number < 18)
        number-=9;
    else if (number>=18)
        number-=18;
        
    int row_or_col = thread_args1->square_or_col_or_box;
    
    printf("running row_col_or_box: %d, number: %d\n", row_or_col, number);
    if (row_or_col < 2)
    {
      int i,j;
      for (i=0;i<9;i++)
      {
          int occured = 0;
          for (j=0;j<9;j++)
          {
              if (row_or_col == 0)
              {
                  if (thread_args1->puzzle[number][j] == i+1)
                      occured++;
              }
              else if (row_or_col == 1)
              {
                  if (thread_args1->puzzle[j][number] == i+1)
                      occured++;
              }
          }
          if (occured != 1)
          {
              printf("there was an mistake in row or column %d\n", number+1);
              return 0;
          }

      }
    }
    else
    {
      int square_col = (number % 3)*3;
      int square_row = (number) - ((number%3));
      for (int k = 0; k < 9; k++)
      {
          int occured = 0;
          for (int i=square_row; i < square_row+3; i++)
          {
              for (int j = square_col; j < square_col+3; j++)
              {
                  if (thread_args1->puzzle[i][j] == k+1)
                      occured++;
              }
          }
          if (occured != 1)
          {
              printf("There was an error in box %d\n", number+1);
              return NULL;
          }
      }
    }

    return NULL;

}
/*
int valid_square(int puzzle[9][9], int square_number)
{
    int square_col = (square_number % 3)*3;
    int square_row = (square_number - (square_number%3));
    for (int k = 0; k < 9; k++)
    {
        int occured = 0;
        for (int i=square_row; i < square_row+3; i++)
        {
            for (int j = square_col; j < square_col+3; j++)
            {
                if (puzzle[i][j] == k+1)
                    occured++;
            }
        }
        if (occured != 1)
        {
            printf("There was an error in box %d\n", square_number+1);
            return 0;
        }
    }
    return 0;
}
*/

void print_list(int puzzle[9][9])
{
 int i,j;
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
  
}
