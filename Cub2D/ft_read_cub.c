#include "./includes/cub.h"

char  **ft_read_cub(char *argv)
{
	char *line;
	t_list *head;
	char **data;
	int fd;
	t_list *tmp;
	int i;

	line = NULL;
	head = NULL;

	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_error(ERR_FILE_OPEN);
	//printf("fd is: %d\n",fd);
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head,ft_lstnew(line));
	ft_lstadd_back(&head,ft_lstnew(line));
	//malloc error
	if(!(data = ft_calloc(ft_lstsize(head) + 1, sizeof(char *))))
		ft_error(ERR_MALLOC);
	tmp = head;

	i = -1;
	while (tmp)
	{
		data[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (data);
}

