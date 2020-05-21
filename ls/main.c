
#include "ft_ls.h"

DIR		*open_dir()
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

void	display_info(t_ls *ls)
{
	ft_printf("%10s %d %s %s %5d %s\n", \
	ls->mode, ls->links_num, ls->owner_name,\
	ls->group_name, ls->size, ls->name);
}

bool	get_stat(t_ls *ls)
{
	t_stat	status;

	if (stat(ls->name, &status) == -1)
	{
		perror("Error in stat");
		return (false);
	}
	ls->mode = type_mode_handle(status.st_mode);
	ls->links_num = status.st_nlink;
	ls->owner_name = get_owner_name(status.st_uid);
	ls->group_name = get_group_name(status.st_gid);
	ls->size = status.st_size;
	ls->mtime = status.st_mtim;
	display_info(ls);
	ft_memdel((void **)&(ls->mode));
	return (true);
}

bool	read_dear(DIR *dir)
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
