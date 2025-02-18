/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:16:58 by jazailac          #+#    #+#             */
/*   Updated: 2025/02/18 13:06:24 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>
#include "FT_PRINTF/ft_printf.h"


void signal_handler(int sig)
{
    if (sig == SIGUSR1)
        ft_printf("Message sent succesfully ✅✅✅\n");
}


void send_signal(int pid, unsigned char c)
{
    int i;  
    
    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                write(1, "failed", 6);
                return;
            }
        }
        else 
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                write(1, "failed2", 7);
                return;
            }
        }
        usleep(75); 
        i--;
    }
}

int main(int ac, char **av)
{
    pid_t pid;
    char *str;
    unsigned int i;

    if (ac != 3)
    {
        ft_printf("Usage <%s> <PID> <Message>", av[0]);
        return (1);
    }
    pid = ft_atoi(av[1]);
    str = av[2];
    signal(SIGUSR1, signal_handler);
    if (!str || pid <= 0 || pid > 4194304)
    {
        ft_printf("Wrong arguments !");
        return (1);
    }
    i = 0;
    while (str[i])
    {
        send_signal(pid, str[i]);
        i++;
    }
    send_signal(pid, '\0');
}
