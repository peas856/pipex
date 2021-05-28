#include "pipex.h"

int		    inputfile(int fdpid, char *path, t_pipe *p, char **env)
{
	int 	fd;

	if ((fd = open(p->infile, O_RDONLY)) == -1)
		    perror("Can not open file\n"); 
	dup2(fd, 0);
	close(fd);
	dup2(fdpid, 1);
	close(fdpid);
	if (execve(path, p->f_cmd, env) == -1)
		perror("ERROR: can't apply first command.\n");
	return (0);
}

int		    sourcefile(int fdpid, char *path, t_pipe *p, char **env)
{
	int		fd;

	 if ((fd = open(p->outfile, O_WRONLY | O_TRUNC) == -1))
		    perror("Can not write file\n");
	dup2(fdpid, 0);
	close(fdpid);
	dup2(fd, 1);
	close(fd);
	if (execve(path, p->s_cmd, env) == -1)
		perror("ERROR: can't apply second command.\n");
	return (0);
}


int		    pipex(t_pipe *p, char **env)
{
	pid_t	pid;
	int		fd[2];
	char	*curr;

	if (pipe(fd))
		perror("Pipe func err\n");
	if ((pid = fork()) == -1)
        perror("Fork func err\n");
	if (pid == 0)
	{
        close(fd[0]);
        if (!(curr = parse_path(p->path, p->f_cmd[0])))
			perror("ERROR: incorrect command.\n");
        inputfile(fd[1], curr, p, env);
        free(curr);
	}   
	else
	{
        close(fd[1]);
        if (!(curr = parse_path(p->path, p->s_cmd[0])))
			perror("ERROR: incorrect command.\n");
        sourcefile(fd[0], curr, p, env);
        free(curr);
	}
	return (0); 
}

