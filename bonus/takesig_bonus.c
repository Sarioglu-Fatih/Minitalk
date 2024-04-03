/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takesig_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:48:39 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 16:40:56 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putustr(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	step1(int sig, int (*bin)[8], int (*i)[3])
{
	if (sig == 30)
		(*bin)[(*i)[0]] = 0;
	else if (sig == 31)
		(*bin)[(*i)[0]] = 1;
	(*i)[0]++;
}

unsigned char	*step2(unsigned char *str, char *size, void *ucontext)
{
	int		i;
	char	*u;

	i = 0;
	u = ucontext;
	str = malloc(sizeof(char) * ft_atoi(size) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	g_dir = 1;
	return (str);
}

void	step3(int (*i)[3], unsigned char *str, siginfo_t *info)
{
	ft_putustr(str);
	usleep(200);
	free(str);
	(*i)[1] = 0;
	(*i)[2] = 0;
	g_dir = 0;
	kill(info->si_pid, SIGUSR1);
}

void	takesig_bonus(int sig, siginfo_t *info, void *ucontext)
{
	static char				c;
	static unsigned char	*str;
	static int				bin[8];
	static char				size[11];
	static int				i[3] = {0, 0, 0};

	step1(sig, &bin, &i);
	if (i[0] >= 8)
	{
		c = bintochar(bin);
		if (g_dir == 0)
			size[i[1]++] = c;
		if (g_dir == 0 && c == 0)
			str = step2(str, size, ucontext);
		else if (g_dir == 1)
		{
			str[i[2]++] = c;
			if (c == 0 && g_dir == 1)
				g_dir = 2;
		}
		if (g_dir == 2)
			step3(&i, str, info);
		i[0] = 0;
	}
}
