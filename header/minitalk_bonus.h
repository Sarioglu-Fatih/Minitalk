/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:32:50 by fsariogl          #+#    #+#             */
/*   Updated: 2022/10/24 15:29:46 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

int	g_dir;
int	g_timer;

void	printpid(void);
void	takesig(int sig);
void	ft_putnbr(int nb);
void	sigreceived(int sig);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	parsing(int argc, char **argv);
void	takesig_bonus(int sig, siginfo_t *info, void *ucontext);
char	bintochar(int *bin);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		*getbin(char *pid, unsigned char c, int *bin);

#endif