
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

static void		display_info(t_ls *ls)
{
	ft_printf("%s %d %s %s %5lld %.12s  %s", \
	ls->mode, ls->links_num, ls->owner_name,\
	ls->group_name, ls->size, &(ls->mtime)[4], ls->name);
	if (ls->mode[0] == 'l')
		ft_printf(" -> %s\n", ls->link_to);
	else
		write(1, "\n", 1);
}

static char *link_point_to(const char *file_name)
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
	if (ls->mode && ls->mode[0] == 'l' && ls->link_to)
		ft_memdel((void **)&(ls->link_to));
	if (ls->mode)
		ft_memdel((void **)&(ls->mode));
}

static bool	get_stat(t_ls *ls)
{
	t_stat	status;

	if (lstat(ls->name, &status) == -1)
	{
		perror("Error in stat");
		return (false);
	}
	ls->mode = type_mode_handle(status.st_mode);
	ls->links_num = status.st_nlink;
	ls->owner_name = get_owner_name(status.st_uid);
	ls->group_name = get_group_name(status.st_gid);
	ls->size = status.st_size;
	ls->mtime = ctime((const time_t *)&(status.st_mtime));
	if (ls->mode[0] == 'l')
		ls->link_to = link_point_to(ls->name);
	display_info(ls);
	free_memory(ls);
	return (true);
}

static bool	read_dear(DIR *dir)
{
	t_dirent	*entry;
	t_ls		ls;

	while ((entry = readdir(dir)) != NULL)
	{
		ls.name = entry->d_name;
		if (get_stat(&ls) ==  false)
			return (false);
	};
	return (true);
}

int		main(int argc, char **argv)
{
	DIR		*dir;

	if (!(dir = open_dir()))
		return (0);
	read_dear(dir);
	closedir(dir);
	return (0);
};
