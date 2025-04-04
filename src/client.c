/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:03:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/04 22:56:28 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    send_signal(char *message, int id_server)
{
    
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
		return (ft_putstr_fd("Error: wrong Arg", 1), 1);
    send_signal(message, pid_num);
	return (0);
}
