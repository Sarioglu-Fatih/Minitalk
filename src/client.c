/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:43:46 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/23 13:15:31 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itoa_rev(int size, char *str)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		str[i] = size % 10 + 48;
		size = size / 10;
		i++;
	}
	str[i] = '\0';
}

void	endofsize(char *pid)
{
	int	c;

	c = 0;
	while (c < 8)
	{
		usleep(200);
		kill(ft_atoi(pid), SIGUSR1);
		c++;
	}
	g_timer = 1;
	usleep(1000);
}

void	sizetobin(char *pid, char *str)
{
	int		i;
	int		*bin;
	int		size;
	char	*lenght;

	i = 0;
	size = 0;
	bin = malloc(sizeof(int) * 8);
	lenght = malloc(sizeof(char) * 11);
	if (!bin || !lenght)
		exit(EXIT_FAILURE);
	while (str[size])
		size++;
	ft_itoa_rev(size, lenght);
	while (lenght[i])
		i++;
	i--;
	while (i >= 0)
	{
		bin = getbin(pid, lenght[i], bin);
		i--;
	}
	free(bin);
	free(lenght);
	endofsize(pid);
}

void	argtobin(char *pid, char *arg)
{
	int	i;
	int	*bin;

	i = 0;
	bin = malloc(sizeof(int) * 8);
	if (!bin)
		return ;
	while (arg[i])
	{
		bin = getbin(pid, arg[i], bin);
		i++;
	}
	endofsize(pid);
	free(bin);
}

int	main(int argc, char **argv)
{
	parsing(argc, argv);
	sizetobin(argv[1], argv[2]);
	argtobin(argv[1], argv[2]);
	return (0);
}
