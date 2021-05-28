#include "pipex.h"

int		main(int ac, char **av, char **env)
{
	t_pipe		p;

	if (ac != 5)
		perror("Invalid arg\n");
    p.infile = av[1];
    p.outfile = av[4];
	p.f_cmd = ft_strsplit(av[2], ' ');
    p.s_cmd = ft_strsplit(av[3], ' ');
    p.path = get_path(env);
	if (!(p.f_cmd[0]) || !(p.s_cmd[0]))
		perror("Command err\n");
	pipex(&p, env);
	return (0);
}

// PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin