#include <lem_in.h>

int		main(void)
{
	t_room	*start;
	t_room	*one;
	t_room	*two;
	t_room	*three;

	start = create_room(ft_strdup("Bruno"), 1);
	one = create_room(ft_strdup("ONe"), 0);
	two = create_room(ft_strdup("Tow2"), 0);
	three = create_room(ft_strdup("TREE"), 0);

	ft_lstadd(&start->list_tube, ft_lstnew(one, sizeof(t_room *)));
	ft_lstadd(&start->list_tube, ft_lstnew(two, sizeof(t_room *)));
	ft_lstadd(&start->list_tube, ft_lstnew(three, sizeof(t_room *)));
	dprintf(1, "%s\n", start->name);
	while (start->list_tube)
	{
		dprintf(1, "  %s\n", ((t_room *)start->list_tube->content)->name);
		start->list_tube = start->list_tube->next;
	}
	return (0);
}
