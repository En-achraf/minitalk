/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:03:02 by acennadi          #+#    #+#             */
/*   Updated: 2025/04/05 11:32:52 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(void)
{
	ft_putstr_fd("PID number : ", 1);
	ft_putnbr_fd(getpid(), 1);
	
	while(1)
		usleep(50);
	return (0);
}
