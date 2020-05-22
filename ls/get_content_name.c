
#include "ft_ls.h"

char	*get_owner_name(uid_t uid)
{
	t_passwd	*userid;
	
	userid = getpwuid(uid);
	return (userid->pw_name);
}

char	*get_group_name(uid_t gid)
{
	t_group		*groupid;

	groupid = getgrgid(gid);
	return (groupid->gr_name);
}
