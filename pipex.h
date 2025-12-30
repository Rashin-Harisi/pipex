/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:49:15 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 17:57:19 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H


# include "./libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char    **find_paths(char **envp);
char    *check_access_pathname(char **paths, char *cmd);
void	free_array(char **s);
void    pipe_management(int i, int argc, int *fds, int *pipe_fd);
void    exec_cmd(int i, char **argv, char **envp);
void    exit_error(char *str, int *fds, int *pipe_fd);
void    file_opening(int *fds, int argc, char **argv);
void    open_pipe(int *pipe_fd, int *fds);
void    parent_pipe_management(int *fds, int *pipe_fd, int argc, int i);
void    multipipex(int argc, char *argv[],char **envp);
#endif

