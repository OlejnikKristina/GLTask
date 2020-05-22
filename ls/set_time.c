
#include "ft_ls.h"

char	*set_time(t_timespec *mtime)
{
	char	*time;

	// time = (char *)malloc(13);
	// ft_memset((void *)time, ' ', 12);
	// time[12] = '\0';
	time = ctime((const time_t *)mtime);
	return (time);
}
