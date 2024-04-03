/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takesig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:48:39 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 12:37:48 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	step1(int sig, int (*bin)[8], int (*i)[3])
{
	if (sig == 30)
		(*bin)[(*i)[0]] = 0;
	else if (sig == 31)
		(*bin)[(*i)[0]] = 1;
	(*i)[0]++;
}

char	*step2(char *str, char *size)
{
	str = malloc(sizeof(char) * ft_atoi(size) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	g_dir = 1;
	return (str);
}

void	step4(int (*i)[3], char *str)
{
	ft_putstr(str);
	usleep(200);
	free(str);
	(*i)[1] = 0;
	(*i)[2] = 0;
	g_dir = 0;
}

void	takesig(int sig)
{
	static char	c;
	static int	i[3] = {0, 0, 0};
	static char	*str;
	static int	bin[8];
	static char	size[11];

	step1(sig, &bin, &i);
	if (i[0] >= 8)
	{
		c = bintochar(bin);
		if (g_dir == 0)
			size[i[1]++] = c;
		if (g_dir == 0 && c == 0)
			str = step2(str, size);
		else if (g_dir == 1)
		{
			str[i[2]++] = c;
			if (c == 0 && g_dir == 1)
				g_dir = 2;
		}
		if (g_dir == 2)
			step4(&i, str);
		i[0] = 0;
	}
}
