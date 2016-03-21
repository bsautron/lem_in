#include <lem_in.h>

static int    *malloc_nullify(size_t len)
{
  int   *line;

  line = (int *)malloc(len);
  ft_bzero(line, len);
  return (line);
}

void    create_matrix(t_anthill *house)
{
  int     **matrix;
  int     i;
  int     j;
  int     n;

  n = house->htab.length;
  matrix = (int **)malloc(sizeof(int *) * n);
  i = 0;
  while (i < n)
    matrix[i++] = malloc_nullify(sizeof(int) * n);
  i = 0;
  while (i < n)
  {
    j = 0;
    printf("[");
    while (j < n)
    {
      printf("%s%d", (j) ? ", " : "", matrix[i][j]);
      j++;
    }
    printf("]\n");
    i++;
  }
}
