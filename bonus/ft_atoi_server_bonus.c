/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_server_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:43:52 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 14:41:37 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_check_minmax(long long nb, int signe)
{
	if (nb > 9223372036854775807 && signe == 1)
		return (-1);
	if (nb < -9223372036854775807 || nb > 9223372036854775807)
	{
		if (signe == 1)
			return (-1);
		return (0);
	}
	return ((int)nb * signe);
}

int	ft_atoi(char *str)
{
	int			i;
	char		*s;
	long long	nb;
	int			signe;

	i = 0;
	signe = 1;
	s = (char *)str;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		signe = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	nb = 0;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nb = ((nb * 10) + s[i]) - '0';
		i++;
	}
	return (ft_check_minmax(nb, signe));
}
