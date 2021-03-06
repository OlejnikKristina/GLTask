
#ifndef FT_LS_H
#define FT_LS_H

#include <time.h>
#include <stdbool.h>
#include <sys/types.h>	/* For opendir */
#include <sys/stat.h>	/* For stat only */
#include <pwd.h>		/* For getpwuid */
#include <grp.h>		/* For getgrgid */
#include <dirent.h>
#include "../ft_printf/includes/ft_printf.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct timespec	t_timespec;
typedef struct s_ls		t_ls;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct s_ls
{
	char		*mode;			/* File type and mode */
	nlink_t		links_num;		/* Number of hard links */
	char		*owner_name;
	char		*group_name;
	off_t		size;			/* Total size, in bytes */
	char		*mtime;			/* last modified */
	const char	*name;			/* File, dir, link name */
	char		*link_to;		/* Name of file to which link pointed */
	long long	blocks_num;		/* file system blocks, used by the listed files*/
	t_ls		*next;
}				t_ls;

char		*get_group_name(uid_t gid);
char		*get_owner_name(gid_t uid);
char		*type_mode_handle(mode_t mode);
char		*link_point_to(const char *file_name);
void		free_memory(t_ls *ls);
#endif