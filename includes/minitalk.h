/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:18:52 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/05 11:42:14 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// includes
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// functions
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

#endif