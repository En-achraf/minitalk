/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:03:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/05 17:42:16 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(char c, int id_server)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
			kill(id_server, SIGUSR1);
		if (((c >> i) & 1) == 1)
			kill(id_server, SIGUSR2);
		usleep(700);
		i--;
	}
}

void	send_signal(char *message, int id_server)
{
	while (message && *message)
		send_char(*message++, id_server);
	send_char('\0', id_server);
}

int	main(int ac, char **av)
{
	int		pid_num;
	char	*message;

	if (ac != 3)
	{
		ft_putstr_fd("Error: Enter the arg like This\n", 2);
		return (ft_putstr_fd("Error: ./client <PID NUM> message\n", 2), 1);
	}
	pid_num = ft_atoi(av[1]);
	message = av[2];
	if (!pid_num || message[0] == 0)
		return (ft_putstr_fd("Error: wrong Arg", 1), 2);
	send_signal(message, pid_num);
	return (0);
}
