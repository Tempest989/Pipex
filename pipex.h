/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:16:04 by druth             #+#    #+#             */
/*   Updated: 2022/05/11 17:16:05 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>

char	**ft_split(char const *s, char *ev[]);
int		ft_pathfinder(char const *str, char **output, char *ev[]);
int		ft_freeloader(char **output, int count, int flag);
int		ft_finder(char const *ev, int path, char c);
char	*ft_quick(char *gotta, char **fodder);
int		ft_compare(char *ev, char *path, int leading);
int		ft_error_return(char *str, int check);
int		ft_gurt(char const *s, int track, int count, int length);
char	*ft_assign(char const *s, int *track, int check);
char	*ft_assign_loop(char const *s, int *track, char *output, int check);
int		ft_count_assist(const char *s, int track, int flag);

#endif
