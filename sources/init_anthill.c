#include <lem_in.h>
#include <libhash.h>

t_anthill     init_anthill(void)
{
  t_anthill    new;

  ft_bzero(&new, sizeof(t_anthill));
  new.htab = HTAB_CREATE(100, &hash_pour_les_nuls);
  return (new);
}
