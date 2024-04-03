/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:42:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 16:10:57 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	checkpid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			ft_putstr("Veuillez mettre uniquement un PID apres l'executable.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	parsing(int argc, char **argv)
{
	g_timer = 0;
	if (argc <= 2)
	{
		ft_putstr
		("Veuillez mettre un PID et des caracteres apres l'executable.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) < 1)
	{
		ft_putstr("Veuillez mettre un PID apres l'executable.\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 3)
	{
		ft_putstr("Veuillez mettre 2 arguments apres l'executable.\n");
		exit(EXIT_FAILURE);
	}
	checkpid(argv[1]);
	if (!(argv[2][0]))
		exit(EXIT_SUCCESS);
}
