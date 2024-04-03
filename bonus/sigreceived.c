/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigreceived.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:02:05 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 14:41:48 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigreceived(int sig)
{
	if (sig > 0)
	{
		ft_putstr("Signal received\n");
		exit(EXIT_SUCCESS);
	}
}
