#include "pipex.h"

static size_t		ft_counter(char const *s, char c)
{
	size_t	        count;
	size_t	        flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (!flag && *s != c)
		{
			count++;
			flag = 1;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static size_t		word_size(char const *s, char c)
{
	size_t	        len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char const	*word_cpy(char *dst, char const *s, char c)
{
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		*dst++ = *s++;
	}
	*dst = '\0';
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	        count;
	size_t	        i;
	size_t	        len;
	char	        **dst;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = ft_counter(s, c);
	if (NULL == (dst = malloc(sizeof(*dst) * (count + 1))))
		return (0);
	while (i < count)
	{
		len = word_size(s, c);
		if (NULL == (dst[i] = malloc(sizeof(**dst) * (len + 1))))
			return (NULL);
		s = word_cpy(dst[i], s, c);
		i++;
	}
	dst[i] = (char*)malloc(sizeof(*dst));
	dst[i] = 0;
	return (dst);
}