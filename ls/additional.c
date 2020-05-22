
#include "ft_ls.h"

char *link_point_to(const char *file_name)
{
	ssize_t		nbytes;
	char		*point_to;

	point_to = ft_strnew(43);
	if (!point_to)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	nbytes = readlink(file_name, point_to, 42);
	if (nbytes == -1)
	{
		perror("readlink");
		exit(EXIT_FAILURE);
	}
	point_to[42] = '\0';
	return ((char *)point_to);
}

void	free_memory(t_ls *ls)
{
	t_ls *temp;

	temp = ls;
	while (ls)
	{
		if (ls->mode && ls->mode[0] == 'l' && ls->link_to)
			ft_memdel((void **)&(ls->link_to));
		if (ls->mode)
			ft_memdel((void **)&(ls->mode));
		if (ls->mtime)
			ft_memdel((void **)&(ls->mtime));
		temp = ls->next;
		if (ls)
			ft_memdel((void **)&ls);
		ls = temp;
	}
}
