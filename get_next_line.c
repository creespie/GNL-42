#include "get_next_line.h" 

char *get_next_line(int fd)
{
	static char *stash;
	char 		*buf;
	char		*line;
	char		*temp;
	ssize_t		bytes;
	int			len;

	while (check_first_n(stash) == -1)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			{
				free(buf);
				temp = stash;
				stash = NULL;
				return (temp);
			}
		else if (bytes == -1)
			{
				free(buf);
				return (NULL);
			}
		buf[bytes] = '\0';
		temp = ft_strconcat(stash, buf, bytes);
		free(stash);
		stash = temp;
		free(buf);
	}
	len = check_first_n(stash);
	if (stash != NULL && len != -1)
	{
		line = ft_strisolate(stash, 0, len);
		temp = ft_strisolate(stash, len, ft_strlen(stash) - len);
		free(stash);
		stash = temp;
		return (line);
	}
	return (NULL);
}

int	check_first_n(char *string)
{
	int	i;

	i = 0;
	if (!string)
    	return (-1);
	while (string[i])
	{
		if (string[i] == '\n')
			{
				i++;
				return(i);
			}
		i++;
	}
	return(-1);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return(i);
}

char	*ft_strisolate(char *stash, int start, int len)
{
	char	*isolate;
	int 	i;

	i = 0;
	isolate = (char *)malloc(len - start + 1);
	while(start < len)
	{
		isolate[i] = stash[start];
		i++;
		start++;
	}
	isolate[i] = '\0';
	return (isolate);
}

char	*ft_strconcat(char *stash, char *buf, int bytes)
{
	char	*concat;
	int 	i;
	int		stash_len;

	stash_len = ft_strlen(stash);
	i = 0;
	concat = (char *)malloc(stash_len + bytes + 1);
	while(i < stash_len)
	{
		concat[i] = stash[i];
		i++;
	}
	i = 0;
	while(i < bytes)
	{
		concat[i + stash_len] = buf[i];
		i++;
	}
	concat[i + stash_len] = '\0';
	return (concat);
}