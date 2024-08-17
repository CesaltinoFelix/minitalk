/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:46:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/08/14 12:46:54 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int ft_strlen(const char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void ft_putnbr(int num) {
    if (num >= 10)
        ft_putnbr(num / 10);
    char ch = num % 10 + '0';
    write(STDOUT_FILENO, &ch, 1);
}

void handler_bit_received(int signum, siginfo_t *info, void *ucontext) {
    (void)ucontext;
    static int client_pid = 0;
    static int counter = 0;
    static int n = 0;

    if (client_pid != info->si_pid) {
        counter = 0;
        n = 0;
        client_pid = info->si_pid;
    }

    if (signum == SIGUSR1) 
        n = n * 2 + 1;
     else 
        n = n * 2 + 0;
    
    counter++;

    if (counter == 8) {
        write(STDOUT_FILENO, &n, 1);
        counter = 0;
        n = 0;
        if (kill(client_pid, SIGUSR1) == -1) 
        	write(STDERR_FILENO, "ERROR\n", 6);
    } 
    
}

void show_preloader() {
    const char *message = "STARTING SERVER";
    const char *done_message = "Done!\n";

    while (1) {
        write(STDOUT_FILENO, message, 15);
        usleep(500000);

        write(STDOUT_FILENO, "\rSTARTING SERVER.", 17);
        usleep(500000);

        write(STDOUT_FILENO, "\rSTARTING SERVER..", 18);
        usleep(500000);

        write(STDOUT_FILENO, "\rSTARTING SERVER...", 19);
        usleep(500000);

        break;
    }
    write(STDOUT_FILENO, "\r", 1);
    write(STDOUT_FILENO, done_message, 6);
}

int main(void) {
    show_preloader();

    const char *welcome_message = "Ola eu sou o Cesaltino Felix 😀, seja bem-vindo ao meu servidor!\n";
    write(STDOUT_FILENO, welcome_message, ft_strlen(welcome_message));

    write(STDOUT_FILENO, "Server PID: ", 12);
    ft_putnbr(getpid());
    write(STDOUT_FILENO, "\n", 1);

    struct sigaction action;
    action.sa_sigaction = handler_bit_received;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    while (1) {
        pause();
    }

    return 0;
}

