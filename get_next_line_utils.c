/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <lurossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:00:30 by lurossi           #+#    #+#             */
/*   Updated: 2026/05/22 16:27:09 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

char	*ft_strisolate(char *stash, int start, int len)
{
	char	*isolate;
	int		i;

	i = 0;
	if (len == 0)
		return (NULL);
	isolate = (char *)malloc(len + 1);
	while (i < len)
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
	int		i;
	int		stash_len;

	stash_len = ft_strlen(stash);
	i = 0;
	concat = (char *)malloc(stash_len + bytes + 1);
	while (i < stash_len)
	{
		concat[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		concat[i + stash_len] = buf[i];
		i++;
	}
	concat[i + stash_len] = '\0';
	return (concat);
}
