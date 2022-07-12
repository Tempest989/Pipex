/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:33:48 by druth             #+#    #+#             */
/*   Updated: 2022/05/11 19:33:49 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_return(char *str, int check)
{
	int			track;
	static int	flag;

	if (check == 1)
		return (flag);
	if (check > 1)
		flag = 1;
	if (flag == 0)
	{
		if (str != NULL)
		{
			write(2, "pipex: ", 7);
			track = 0;
			while (str[track] != '\0')
				track++;
			write(2, str, track);
			write(2, ": ", 2);
			perror("");
		}
		else if (flag == 0)
			perror("pipex: error");
		flag = 1;
	}
	exit(errno);
}

void	ft_execute(char *av, char *ev[])
{
	char	**output;
	int		track;

	output = ft_split(av, ev);
	execve(output[0], output, ev);
	if (ft_error_return(av, 1) == 0)
	{
		write(2, "pipex: ", 7);
		track = 0;
		while (output[0][track] != '\0')
			track++;
		write(2, output[0], track);
		write(2, ": command not found\n", 20);
		ft_error_return(NULL, 2);
	}
	ft_freeloader(output, -10, 0);
	exit(127);
}

void	ft_piping(char *av, char *ev[])
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		ft_error_return(NULL, 0);
	pid = fork();
	if (pid < 0)
		ft_error_return(NULL, 0);
	if (pid > 0)
	{
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			ft_error_return(NULL, 0);
		pid = waitpid(0, &status, WNOHANG);
		if (pid == -1)
			ft_error_return(NULL, 0);
	}
	else
	{
		close(fd[0]);
		if (dup2(fd[1], 1) == -1)
			ft_error_return(NULL, 0);
		ft_execute(av, ev);
	}
}

void	ft_initialize(int ac, char *av[])
{
	int	check;

	check = open(av[1], O_RDONLY);
	if (check == -1)
		ft_error_return(av[1], 0);
	if (dup2(check, 0) == -1)
		ft_error_return(NULL, 0);
	close(check);
	check = open(av[ac - 1], O_WRONLY | O_CREAT, 0644);
	if (check == -1)
		ft_error_return(av[ac - 1], 0);
	if (dup2(check, 1) == -1)
		ft_error_return(NULL, 0);
	close(check);
}

int	main(int ac, char *av[], char *ev[])
{
	int	track;

	if (ac < 5)
	{
		write(2, "pipex: error: invalid number of arguments.\n", 44);
		exit(1);
	}
	ft_initialize(ac, av);
	track = 2;
	while (track < ac - 2)
		ft_piping(av[track++], ev);
	ft_execute(av[track], ev);
	return (0);
}
