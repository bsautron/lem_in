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
  ft_putendl("ADJACENCY MATRIX:");
  while (matrix[i])
  {
    j = 0;
    ft_putchar('\t');
    while (j < n)
    {
      if (j)
        ft_putstr(", ");
      ft_putnbr(matrix[i][j]);
      j++;
    }
    i++;
    ft_putstr("\n");
  }
  ft_putstr("\n");
}
