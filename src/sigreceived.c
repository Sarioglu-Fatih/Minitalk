/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigreceived.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:02:05 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 14:29:40 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigreceived(int sig)
{
	if (sig == 30)
	{
		ft_putstr("Signal received");
		exit(EXIT_SUCCESS);
	}
}
