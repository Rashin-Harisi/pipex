/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:49:15 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 20:07:45 by rabdolho         ###   ########.fr       */
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

char	**find_paths(char **envp);
char	*check_access_pathname(char **paths, char *cmd);
void	free_array(char **s);
void	pipe_management(int i, int argc, int *fds, int *pipe_fd);
void	exec_cmd(int i, char **argv, char **envp, int offset);
void	exit_error(char *str, int *fds, int *pipe_fd);
void	file_opening(int *fds, int argc, char **argv, char **envp);
void	open_pipe(int *pipe_fd, int *fds);
void	parent_pipe_management(int *fds, int *pipe_fd, int argc, int i);
int		multipipex(int argc, char *argv[], char **envp);
char	*ft_strjoin_char(char *s1, char c);
void	get_first_command(int fd_read, char *limiter, int fd_write);
void	pipe_management_append(int i, int argc, int *fds, int *pipe_fd);
void	parent_pipe_management_append(int *fds, int *pipe_fd, int argc, int i);
void	file_opening_append(int *fds, char **argv, int argc);
int		append(int argc, char *argv[], char **envp);
void	command_error(char *cmd);
int		wait_all(int last_pid);
char	*get_path(char *cmd, char **envp);
void	trim_cmds(char **cmds);
char	**cmds_split(char *cmd, char c);
void	skip_word(int *i, char *cmd, char c);
int		count_cmds(char *cmd, char c);
int		get_cmd_len(char *cmd, char c);
char	*copy_cmd(char *cmd, char c);
#endif
