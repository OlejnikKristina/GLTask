
#include "ft_ls.h"

char	*get_owner_name(uid_t uid)
{
	t_passwd	*userid;
	
	userid = getpwuid(uid);
	return ((char *)userid->pw_name);
}

char	*get_group_name(gid_t gid)
{
	t_group		*groupid;

	groupid = getgrgid(gid);
	return ((char *)groupid->gr_name);
}
