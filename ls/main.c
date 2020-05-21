
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

char	*get_group_name(uid_t userid)
{
	return (NULL);
}

char	*get_owner_name(uid_t userid)
{
	return (NULL);
}

bool	get_stat(t_ls *ls)
{
	t_stat	status;

	if (stat(ls->name, &status) == -1)
	{
		perror("Error in stat");
		return (false);
	}
	ls->mode = status.st_mode;
	ls->links_num = status.st_nlink;
	ls->owner_name = get_owner_name(status.st_uid);
	ls->group_name = get_group_name(status.st_gid);
	ls->size = status.st_size;
	ls->mtime = status.st_mtim;
	ft_printf("mode : %ld\n", status.st_mode);
	ft_printf("links: %ld\n", status.st_nlink);
	ft_printf("size: %ld\n", status.st_size);
	ft_printf("name: %s\n", ls->name);
	return (true);
}

bool	read_dear(DIR *dir)
{
	t_dirent	*entry;
	t_ls		ls;

	while ((entry = readdir(dir)) != NULL)
	{
		ft_printf("%ld - %s [%d] %d\n",
		entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
		ls.name = entry->d_name;
		if (get_stat(&ls))
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
