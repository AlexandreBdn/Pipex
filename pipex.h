/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:02:16 by abaudin           #+#    #+#             */
/*   Updated: 2023/11/06 16:02:17 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

char	**ft_split(char const *str, char charset);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*get_my_env(char *name, char **env);
char	*getpath(char *cmd, char **env, int i);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char *c, int fd);
void	exit_most_arg(int n);
void	free_tab(char **tab);
int		open_files(char *files, int on_or_out);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif