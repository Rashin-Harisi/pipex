/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:49:15 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 20:49:53 by rabdolho         ###   ########.fr       */
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
void    exec_cmd(int i, char **argv, char **envp, int offset);
void    exit_error(char *str, int *fds, int *pipe_fd);
void    file_opening(int *fds, int argc, char **argv);
void    open_pipe(int *pipe_fd, int *fds);
void    parent_pipe_management(int *fds, int *pipe_fd, int argc, int i);
void    multipipex(int argc, char *argv[],char **envp);
char    *ft_strjoin_char(char *s1, char c);
void    get_first_command(int fd_read,char *limiter, int fd_write);
void    pipe_management_append(int i, int argc, int *fds, int *pipe_fd);
void    parent_pipe_management_append(int *fds, int *pipe_fd, int argc, int i);
void    file_opening_append(int *fds, char **argv, int argc);
void    append(int argc, char *argv[],char **envp);

#endif

