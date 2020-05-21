
#include "ft_ls.h"

static char	set_type(mode_t mode)
{
	if (S_ISSOCK(mode)) return('s');
	if (S_ISREG(mode)) return('-');
	if (S_ISDIR(mode)) return('d');
	if (S_ISCHR(mode)) return('c');
	if (S_ISBLK(mode)) return('b');
	if (S_ISFIFO(mode)) return('p');
	if (S_ISLNK(mode)) return( 'l');
	if (S_ISSOCK(mode)) return('s');
}

char		*type_mode_handle(mode_t mode)
{
	char	*type_mode;

	type_mode = (char *)ft_strnew(11);
	type_mode[10] = '\0';
	type_mode[0] = set_type(mode);
	return (type_mode);
}
