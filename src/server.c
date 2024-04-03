/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:07:52 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/23 16:43:11 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int		i;

	printpid();
	i = -1;
	g_dir = 0;
	signal(SIGUSR1, takesig);
	signal(SIGUSR2, takesig);
	while (1)
		pause();
	return (0);
}
