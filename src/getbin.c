/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:33:55 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/22 19:53:20 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*getbin(char *pid, char c, int *bin)
{
	int	i;

	i = 0;
	while (c >= 1)
	{
		bin[i] = c % 2;
		c = c / 2;
		i++;
	}
	while (i <= 7)
		bin[i++] = 0;
	i--;
	while (i >= 0)
	{
		if (g_timer == 0)
			usleep(500);
		else
			usleep(200);
		if (bin[i] == 0)
			kill(ft_atoi(pid), SIGUSR1);
		else if (bin[i] == 1)
			kill(ft_atoi(pid), SIGUSR2);
		i--;
	}
	return (bin);
}
