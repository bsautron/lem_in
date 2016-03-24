#include <lem_in.h>

void   print_matrix(t_anthill house)
{
  int   i;
  int   j;
  int   n;
  int   **matrix;

  n = house.nb_rooms;
  matrix = house.dijkstra->adjacent_matrix;
  i = 0;
  while (matrix[i])
  {
    j = 0;
    while (j < n)
    {
      if (j)
        printf(", ");
      printf("%d", matrix[i][j]);
      j++;
    }
    i++;
    printf("\n");
  }
}
