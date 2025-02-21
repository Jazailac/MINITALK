/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:01 by jazailac          #+#    #+#             */
/*   Updated: 2025/02/21 17:25:47 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>
#include "FT_PRINTF/ft_printf.h"


void signal_handler(int sig, siginfo_t *info, void *x)
{
	static int i = 0;
	static char current = 0;
	static pid_t pid = 0;

	(void)x;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		write(1, "\n", 1);
		current = 0;
		i = 0;
		pid = info->si_pid;	
	}
	current <<= 1;  
	current |= (sig == SIGUSR1);  
	i++;	
	if (i == 8)
	{
		if (current == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current);
		i = 0;
		current = 0;
	}
}

int main(int ac, char **av)
{
	struct sigaction sa;

	if (ac != 1)
		return ft_printf("Usage: %s\n", av[0]);
	
	pid_t pid = getpid();
	if (pid <= 0)
		return ft_printf("Invalid PID\n");
	
	ft_printf("Your pid is %d\n", pid);

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
		sigaction(SIGUSR2, &sa, NULL) == -1)
		return ft_printf("Signal handler setup failed\n");
	
	while (1)
		pause();
	
	return 0;
}
