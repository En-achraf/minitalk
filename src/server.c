/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:07:38 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/12 16:23:16 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handel_sig(int signum, siginfo_t *info, void *content)
{
	static char	c;
	static int	i = 7;
	static int	curr_pid;
	int			new_pid;

	new_pid = info->si_pid;
	(void)content;
	if (curr_pid != new_pid)
	{
		curr_pid = new_pid;
		c = 0;
		i = 7;
	}
	if (signum == SIGUSR2)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = handel_sig;
	signal.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		;
	return (0);
}
