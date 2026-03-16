#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
ssize_t read(int fd, void *buf, size_t count);
char    *get_next_line(int fd);
int	    check_first_n(char *string);
int	    ft_strlen(char *string);
char    *ft_strconcat(char *stash, char *buf, int bytes);
int	    ft_strlen(char *string);

#endif