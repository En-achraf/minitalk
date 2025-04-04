#ifndef MINITALK_H
# define MINITALK_H

// includes
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// functions
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

#endif