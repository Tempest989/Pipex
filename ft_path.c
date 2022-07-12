/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:32 by druth             #+#    #+#             */
/*   Updated: 2022/05/11 16:22:33 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_compare(char *ev, char *path, int leading)
{
	int	track;

	track = 0;
	while (ev[track + leading] == path[track]
		&& ev[track + leading] != '\0' && path[track] != '\0')
		track++;
	if (path[track] == '\0')
		return (track);
	return (-1);
}

int	ft_finder(char const *ev, int path, char c)
{
	int	track;

	track = 0;
	while (ev[path + track] != '\0' && ev[path + track] != c)
		track++;
	return (track);
}

char	*ft_null_return(char **output)
{
	free(output);
	write(2, "pipex: error: malloc allocation has failed\n", 43);
	exit(1);
	return (NULL);
}

char	*ft_catch_them_all(char *ev, int path, char const *str, char **output)
{
	int		track;
	char	*gotta;
	int		length;

	track = 0;
	while (str[track] != '\0' && str[track] != ' ')
		track++;
	length = ft_finder(ev, path, '\0');
	gotta = (char *)malloc(sizeof(char) * (length + track + 2));
	if (gotta == NULL)
		return (ft_null_return(output));
	length = 0;
	while (ev[path] != '\0' && ev[path] != ':')
		gotta[length++] = ev[path++];
	gotta[length++] = '/';
	track = 0;
	while (str[track] != '\0' && str[track] != ' ')
	{
		gotta[track + length] = str[track];
		track++;
	}
	gotta[track + length] = '\0';
	return (gotta);
}

int	ft_pathfinder(char const *str, char **output, char *ev[])
{
	int		length;
	int		path;
	char	*gotta;

	length = 0;
	while (ev[length] != NULL && ft_compare(ev[length], "PATH=", 0) == -1)
		length++;
	if (ev[length] == NULL)
		return (1);
	path = 5;
	while (ev[length][path] != '\0')
	{
		gotta = ft_catch_them_all(ev[length], path, str, output);
		if (access(gotta, X_OK) == 0)
		{
			output[0] = gotta;
			return (-1);
		}
		free(gotta);
		path += ft_finder(ev[length], path, ':') + 1;
	}
	return (1);
}
