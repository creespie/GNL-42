/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <lurossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:00:44 by lurossi           #+#    #+#             */
/*   Updated: 2026/05/22 16:24:56 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

ssize_t	read(int fd, void *buf, size_t count);
char	*get_next_line(int fd);
char	*ft_strconcat(char *stash, char *buf, int bytes);
char	*ft_strisolate(char *stash, int start, int len);
int		check_first_n(char *string);
int		ft_strlen(char *string);

#endif