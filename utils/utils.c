/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:21 by abaudin           #+#    #+#             */
/*   Updated: 2023/11/07 17:23:22 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void exit_most_arg(int n)
{
	if (n == 1)
		ft_putstr_fd("Error arguments",2);
	
	exit(0);
}

int open_files(char *files , int on_or_out)
{
	int ret = 0;

	if (on_or_out == 0)
		ret = open(files,O_RDONLY,0777);
	else if (on_or_out == 1)
		ret = open(files,O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (on_or_out == -1)
		exit(0);
	return(ret);
}

char *get_my_env(char *name,char **env)
{
	char **str_env;
	char *ret;
	int i;
	
	i = 0;
	while (env[i])
	{
		str_env = ft_split(env[i], '=');
		if (str_env && ft_strncmp(name, str_env[0], ft_strlen(str_env[0])) == 0)
		{
			if (str_env[1] == NULL)
				continue;
			ret = ft_strdup(str_env[1]);
			free_tab(str_env);
			return(ret);
		}
		i++;
	}
	free_tab(str_env);
	return(NULL);
}

char *getpath(char *cmd, char **env, int i)
{
	char	**path;
	char	**s_cmd;
	char	*exec;
	char	*str_env;
	char	*ret;

	if (access(cmd, F_OK | X_OK) == 0)
		return(cmd);
	str_env = get_my_env("PATH=", env);
	path = ft_split(str_env,':');
	free(str_env);
	s_cmd = ft_split(cmd,' ');
	while(path && path[++i])
	{
		ret = ft_strjoin(path[i],"/");
		exec = ft_strjoin(ret,s_cmd[0]);
		free(ret);
		if (access(exec, F_OK | X_OK) == 0)
			return(exec);
		free(exec);
	}
	free_tab(path);
	free_tab(s_cmd);
	return(NULL);
}