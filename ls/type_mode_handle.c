
#include "ft_ls.h"

static char	set_type(mode_t mode)
{
	if (S_ISSOCK(mode)) return('s');
	if (S_ISLNK(mode)) return('l');
	if (S_ISREG(mode)) return('-');
	if (S_ISDIR(mode)) return('d');
	if (S_ISCHR(mode)) return('c');
	if (S_ISBLK(mode)) return('b');
	if (S_ISFIFO(mode)) return('p');
	return ('-');
}

static void set_mode(char **type_mode, mode_t mode)
{
	if (mode & S_IRUSR) (*type_mode)[1] = 'r';
	if (mode & S_IWUSR) (*type_mode)[2] = 'w';
	if (mode & S_IXUSR) (*type_mode)[3] = 'x';
	if (mode & S_IRGRP) (*type_mode)[4] = 'r';
	if (mode & S_IWGRP) (*type_mode)[5] = 'w';
	if (mode & S_IXGRP) (*type_mode)[6] = 'x';
	if (mode & S_IROTH) (*type_mode)[7] = 'r';
	if (mode & S_IWOTH) (*type_mode)[8] = 'w';
	if (mode & S_IXOTH) (*type_mode)[9] = 'x';
}

char		*type_mode_handle(mode_t mode)
{
	char	*type_mode;

	type_mode = (char *)malloc(11);
	if (type_mode == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	ft_memset((void *)type_mode, '-', 10);
	type_mode[10] = '\0';
	type_mode[0] = set_type(mode);
	set_mode(&type_mode, mode);
	return (type_mode);
}
