/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <lurossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:00:21 by lurossi           #+#    #+#             */
/*   Updated: 2026/05/22 16:13:45 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static int	ft_use_read(char **stash, char *temp, char *buf, int fd)
{
	ssize_t		bytes;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while (check_first_n(*stash) == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(buf);
			return (0);
		}
		else if (bytes == -1)
		{
			free(buf);
			return (-1);
		}
		buf[bytes] = '\0';
		temp = ft_strconcat(*stash, buf, bytes);
		free(*stash);
		*stash = temp;
		
	}
	free(buf);
	return (1);
}

static char	*ft_extract_line(char **stash)
{
	char		*line;
	char		*temp;
	int			len;

	len = check_first_n(*stash);
	if (*stash != NULL && len != -1)
	{
		line = ft_strisolate(*stash, 0, len);
		temp = ft_strisolate(*stash, len, ft_strlen(*stash) - len);
		free(*stash);
		*stash = temp;
		return (line);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *stash;
	char		*temp;
	int			output;
	char		*buf;

	temp = NULL;
	buf = NULL;
	output = ft_use_read(&stash, temp, buf, fd);
	if (output == 0)
	{
		temp = stash;
		stash = NULL;
		return (temp);
	}
	else if (output == -1)
		return (NULL);
	return (ft_extract_line(&stash));
}