/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:27:27 by abaudin           #+#    #+#             */
/*   Updated: 2023/11/06 14:27:28 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exec(char *cmd, char **env,int input, int output)
{
	char **s_cmd;
	char *path;

	s_cmd = ft_split(cmd, ' ');
	path = getpath(s_cmd[0], env, 0);
	dup2(input,0);
	dup2(output,1);
	if (path == NULL)
	{
		ft_putstr_fd("command not found :",2);
		free(path);
		free_tab(s_cmd);
		exit(0);
	}
	if (execve(path,s_cmd,env) == - 1)
	{
		ft_putstr_fd("command not found :",2);
		free(path);
		free_tab(s_cmd);
	}
	exit(0);
}

void    pipex(char **cmd, char **env, int file1, int file2)
{
    __pid_t    pid;
    int        pipefd[2];

    if (pipe(pipefd) == -1)
        perror("pipe");
    pid = fork();
    if (pid == 0)
        exec(cmd[2], env, file1, pipefd[1]);
    close(pipefd[1]);
    wait(NULL);
    pid = fork();
    if (pid == 0)
        exec(cmd[3], env, pipefd[0], file2);
    close(pipefd[0]);
    wait(NULL);
}

int	main(int argc, char **str, char **env)
{
	int i;

	i = 0;
	if (argc != 5)
		exit_most_arg(1);
	else if (argc == 5)
	{
		while (str && (str[2][i] == ' ' || str[3][i] == ' '))
		{
			i++;
			if (str && (str[2][i] == '\0' || str[3][i] == '\0'))
			{
				ft_putstr_fd("Error Arguments \n",2);
				return(1);
			}
		}
		if (ft_strlen(str[2]) == 0 || ft_strlen(str[3]) == 0)
			ft_putstr_fd("Error Arguments \n",2);
		else
			pipex(str, env, open_files(str[1],0), open_files(str[4],1));
	}
		return 0;
}