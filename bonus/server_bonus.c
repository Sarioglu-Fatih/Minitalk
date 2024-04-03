/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:07:52 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 14:41:46 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
 i[0] bin
 i[1] size
 i[2] str
*/

void	printpid(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
}

char	bintochar(int *bin)
{
	int		i;
	int		c;
	char	ch;

	i = 0;
	c = 0;
	while (i <= 7)
	{
		c = c * 2 + bin[i];
		i++;
	}
	ch = c;
	return (ch);
}

int	main(void)
{
	int					i;
	struct sigaction	sa;

	printpid();
	i = -1;
	g_dir = 0;
	sa.sa_sigaction = takesig_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
