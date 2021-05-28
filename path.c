#include "pipex.h"

size_t      ft_strlen(const char* s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char        *ft_strjoin(char const* s1, char const* s2)
{
	char    *str;
	int     s1_len;
	int     s2_len;
    int     i;
    int     j;

    i = 0;
    j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (i < s1_len)
    {
        str[i] = s1[i];
        i++;
    }
    while (j < s2_len)
        str[i++] = s2[j++];
    str[i] = '\0';
	return (str);
}

char        *ft_strstr(char *str, char *to_find)
{
    int     i;
    int     j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char		*get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strstr(env[i], "PATH=") != 0)
			return (env[i] + 5);
	}
	return (NULL);
}

char		*parse_path(char *path, char *cmd)
{
	char	**dir_list;
	char	*curr;
	int		i;

	i = -1;
	dir_list = ft_strsplit(path, ':');
	while (dir_list[++i])
	{
		if (cmd[0] == '/')
			curr = ft_strjoin(dir_list[i], cmd);
		else
			curr = ft_strjoin(ft_strjoin(dir_list[i], "/"), cmd);
		if (!access(curr, F_OK))
			return (curr);
	}
	return (NULL);
}