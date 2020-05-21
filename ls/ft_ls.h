
#ifndef FT_LS_H
#define FT_LS_H

#include <stdbool.h> 
#include <sys/types.h>	/* For opendir */
#include <sys/stat.h>	/* For stat only */
#include <pwd.h>		/* For getpwuid */
#include <dirent.h>
#include "../ft_printf/includes/ft_printf.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct timespec	t_timespec;
typedef struct s_ls		t_ls;
typedef struct passwd	t_passwd;

typedef struct s_ls
{
	mode_t		mode;			/* File type and mode */
	nlink_t		links_num;		/* Number of hard links */
	char		*owner_name;
	char		*group_name;
	off_t		size;			/* Total size, in bytes */
	t_timespec	mtime;			/* last modified */
	const char	*name;			/* File, dir, link name */

}				t_ls;


// typedef struct s_ls
// {
// 	// t_stat		*stat;
// 	// t_dirent	*entries;
// 	// t_ls		*next;
// 	char		*file_mode;
// 	nlink_t		links_num;
// 	char		*owner_name;
// 	char		*group_name;
// 	int			fied_num;
// 	// off_t		st_size;
// 	int			data;
// 	const char	*name; /* File, dir, link name */

// }				t_ls;

#endif