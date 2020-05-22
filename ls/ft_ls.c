
#include "ft_ls.h"

static DIR		*open_dir()
{
	DIR			*dir;

	dir = opendir(".");
	if (!dir)
	{
		perror("Error in diropen");
		return (NULL);
	};
	return (dir);
}

static void		la_style(t_ls *ls, int pad)
{
	ft_printf("%s %d %s %s %*lld %.12s  %s", \
	ls->mode, ls->links_num, ls->owner_name, \
	ls->group_name, pad, ls->size, \
	&(ls->mtime)[4], ls->name);
	if (ls->mode[0] == 'l')
		ft_printf(" -> %s", ls->link_to);
	write(1, "\n", 1);
}

static void		display_info(t_ls *ls_head, int pad, long long blocks_size)
{
	t_ls	*ls;

	ls = ls_head;
	ft_printf("total: %lld\n", blocks_size / 2);
	while (ls)
	{
		la_style(ls, pad);
		ls = ls->next;
	}
}

t_ls		*add_node(char	*name)
{
	t_ls	*ls;
	t_stat	status;

	ls = (t_ls *)ft_memalloc(sizeof(t_ls));
	if (!ls)
	{
		perror("malloc");
		return(NULL);
	}
	if (lstat(name, &status) == -1)
	{
		perror("Error in stat");
		return (NULL);
	}
	ls->name = name;
	ls->mode = type_mode_handle(status.st_mode);
	ls->links_num = status.st_nlink;
	ls->owner_name = get_owner_name(status.st_uid);
	ls->group_name = get_group_name(status.st_gid);
	ls->size = status.st_size;
	ls->mtime = ft_strdup(ctime((const time_t *)&(status.st_mtime)));
	ls->blocks_num = (long long)status.st_blocks;
	if (ls->mode[0] == 'l')
		ls->link_to = link_point_to(ls->name);
	ls->next = NULL;
	return (ls);
}

static bool	read_dir(DIR *dir)
{
	t_dirent	*entry;
	t_ls		*ls_top;
	t_ls		*ls;
	int			pad;
	long long	blocks_size;

	pad = 1;
	entry = readdir(dir);
	ls_top = add_node(entry->d_name);
	ls = ls_top;
	blocks_size = ls->blocks_num;
	while (entry = readdir(dir))
	{
		if (!(ls->next = add_node((char *)entry->d_name)))
			return (false);
		if (pad < ft_count_digit((int)ls->size))
			pad = ft_count_digit((int)ls->size);
		blocks_size += ls->blocks_num;
		ls = ls->next;
	};
	display_info(ls_top, pad, blocks_size);
	free_memory(ls_top);
	return (true);
}

int		main(int argc, char **argv)
{
	DIR		*dir;

	if (!(dir = open_dir()))
		return (0);
	read_dir(dir);
	closedir(dir);
	return (0);
};
