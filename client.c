/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:46:14 by cefelix           #+#    #+#             */
/*   Updated: 2024/08/14 13:52:41 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

char	g_character;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	if (str[i] != '\0')
	{
		return (-1);
	}
	return (res);
}

void	handler_bit_received(int signum)
{
	(void)signum;
	ft_putchar(g_character);
}

void	eg_usage(void)
{
	const char	*msg;

	msg = "Usage: ./client <PID> <message>\n";
	write(2, msg, ft_strlen(msg));
}

void	invalid_pid(void)
{
	const char	*error_msg;

	error_msg = "Easy boy 😀... Your PID must be a (INTEGER) positive value.\n";
	write(2, error_msg, ft_strlen(error_msg));
	eg_usage();
}

void	server_error(void)
{
	write(2, "Check if the server is still running\n", 37);
}

void	convert_to_bits(char c, int pid)
{
	char	bit;
	int		i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error sending SIGUSR1\n", 23);
				server_error();
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error sending SIGUSR2\n", 23);
				server_error();
				exit(EXIT_FAILURE);
			}
		}
		i--;
		g_character = c;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	signal(SIGUSR1, handler_bit_received);
	if (argc != 3)
	{
		eg_usage();
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	if (pid <= 0)
	{
		invalid_pid();
		return (EXIT_FAILURE);
	}
	while (argv[2][i])
	{
		convert_to_bits(argv[2][i], pid);
		i++;
	}
	i = 0;

	while(i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
	ft_putchar('\0');
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}
