/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:29:08 by druth             #+#    #+#             */
/*   Updated: 2022/05/11 19:29:09 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_length(char const *s, int track, int length, int check)
{
	while (s[track] != '\0')
	{
		if (s[track] != ' ')
		{
			length++;
			while (s[track] != ' ' && s[track] != '\0')
			{
				if (s[track] == 39 || s[track] == '"' || s[track] == '`')
				{
					check = ft_finder(s, track + 1, s[track]);
					if (s[track + check + 1] == s[track])
						track += check + 1;
				}
				track++;
			}
		}
		else
		{
			while (s[track] == ' ' && s[track] != '\0')
				track++;
		}
	}
	return (length + 1);
}

int	ft_freeloader(char **output, int count, int flag)
{
	if (flag == 0)
	{
		count = 0;
		while (output[count] != NULL)
			count++;
		count--;
	}
	while (count >= 0)
	{
		free(output[count]);
		count--;
	}
	free(output);
	return (-1);
}

char	*ft_assign(char const *s, int *track, int check)
{
	char	*output;

	output = (char *)malloc(sizeof(char) * check);
	if (output == NULL)
		return (NULL);
	output[check - 1] = '\0';
	return (ft_assign_loop(s, track, output, check));
}

static int	ft_count(char const *s, char **output, int track, char *ev[])
{
	int	count;
	int	check;

	count = 0;
	while (s[track] != '\0')
	{
		track = ft_count_assist(s, track, 1);
		if (s[track] != ' ' && s[track] != '\0')
		{
			check = ft_gurt(s, track, count, 0);
			if (check == -1)
				check = ft_pathfinder(s, output, ev);
			if (check > 0)
			{
				output[count] = ft_assign(s, &track, check);
				if (output[count] == NULL)
					return (ft_freeloader(output, count, 1));
			}
			else
				track = ft_count_assist(s, track, 0);
		}
		count++;
	}
	return (0);
}

char	**ft_split(char const *s, char *ev[])
{
	char	**output;
	int		track;
	int		sum;

	if (s == NULL)
		return (NULL);
	sum = ft_length(s, 0, 0, 0);
	output = (char **)malloc(sizeof(char *) * sum);
	if (output == NULL)
	{
		write(2, "pipex: error: malloc allocation has failed\n", 43);
		exit(1);
	}
	output[sum - 1] = NULL;
	track = 0;
	if (ft_count(s, output, track, ev) == -1)
	{
		write(2, "pipex: error: malloc allocation has failed\n", 43);
		exit(1);
	}
	return (output);
}
