/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:07:41 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/12 16:47:44 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_sig(int p_id, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (((str[i] >> bit) & 1) == 0)
				kill(p_id, SIGUSR1);
			else if (((str[i] >> bit) & 1) == 1)
				kill(p_id, SIGUSR2);
			usleep(700);
			bit--;
		}
		i++;
	}
	bit = 7;
	while (bit >= 0)
	{
		kill(p_id, SIGUSR1);
		usleep(700);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		arg;
	char	*message;

	message = av[2];
	arg = ft_atoi(av[1]);
	if (ac != 3)
		return (ft_putstr_fd("Error : should be./client  <PID> 'MESSAGE'", 2),
			1);
	if (arg <= 1 || arg > 4194304)
		return (ft_putstr_fd("invalid <PID>\n", 2), 0);
	if (!*message)
		return (ft_putstr_fd("invalid message\n", 2), 0);
	(void)message;
	send_sig(arg, message);
	return (0);
}
