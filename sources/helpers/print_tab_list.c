#include <lem_in.h>

void print_tab_list(char *name, t_list_int **tab)
{
  int     i;
  t_list_int    *tmp;

  i = 0;
  printf("%s: ", name);
  while (tab[i])
  {
    tmp = tab[i];
    while (tmp)
    {
      if (tmp->nb == -1)
        printf("%s", "-");
      else
        printf("%d", tmp->nb);
      tmp = tmp->next;
      if (tmp)
        printf(",");
    }
    printf(" ");
    i++;
  }
  printf("%s\n", "");
}
