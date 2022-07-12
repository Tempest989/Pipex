/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:23 by druth             #+#    #+#             */
/*   Updated: 2022/05/11 17:05:25 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_assign_loop_assist(char const *s, char *output,
		int *track, int *length)
{
	if (s[*track] != ' ' && s[*track] != '\0')
	{
		output[*length] = s[*track];
		*track += 1;
		*length += 1;
	}
}

char	*ft_assign_loop(char const *s, int *track, char *output, int check)
{
	int	length;

	length = 0;
	while (s[*track] != ' ' && s[*track] != '\0')
	{
		if (s[*track] == 39 || s[*track] == '"' || s[*track] == '`')
		{
			check = ft_finder(s, *track + 1, s[*track]);
			if (s[*track + check + 1] == s[*track])
			{
				check = *track;
				*track += 1;
				while (s[*track] != s[check] && s[*track] != '\0')
				{
					output[length++] = s[*track];
					*track += 1;
				}
				if (s[*track] == s[check])
					*track += 1;
			}
		}
		ft_assign_loop_assist(s, output, track, &length);
	}
	return (output);
}

int	ft_gurt(char const *s, int track, int count, int length)
{
	int	check;
	int	flag;

	flag = 0;
	while (s[track + length] != ' ' && s[track + length] != '\0')
	{
		if (count == 0 && flag == 0 && s[track + length] == '/')
			flag = 1;
		if (s[track + length] == 39
			|| s[track + length] == '"' || s[track + length] == '`')
		{
			check = ft_finder(s, track + length + 1, s[track + length]);
			if (s[track + check + 1] == s[track + length])
			{
				length = check;
				break ;
			}
		}
		length++;
	}
	if (flag == 0 && count == 0)
		return (-1);
	return (length + 1);
}

int	ft_count_assist(const char *s, int track, int flag)
{
	if (flag == 1)
	{
		while (s[track] == ' ' && s[track] != '\0')
			track++;
	}
	else
	{
		while (s[track] != ' ' && s[track] != '\0')
			track++;
	}
	return (track);
}
