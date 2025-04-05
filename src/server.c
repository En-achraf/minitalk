/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:03:02 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/05 13:31:38 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0", 1);
	if (signum == SIGUSR2)
		write(1, "1", 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	signal_received;

	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigemptyset(&signal_received.sa_mask);
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		usleep(50);
}
