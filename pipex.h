#ifndef PIPEX_H

# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	s_pipe
{
	char		**f_cmd;
	char		**s_cmd;
	char		*path;
	char		*infile;
	char		*outfile;
}				t_pipe;

char            *get_path(char **env);
int             inputfile(int fdpid, char *path, t_pipe *p, char **env);
int             sourcefile(int fdpid, char *path, t_pipe *p, char **env);
int             pipex(t_pipe *p, char **env);
void            ft_err(char *str);
char            *parse_path(char *path, char *cmd);

char            **ft_strsplit(char const *str, char c);

#endif