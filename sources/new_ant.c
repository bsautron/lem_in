#include <lem_in.h>

t_ant     new_ant(int id, int y, int x, int type)
{
  t_ant   ant;

  ant.id = id;
  ant.y = y;
  ant.x = x;
  ant.type = type;
  return (ant);
}
