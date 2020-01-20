/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:54:59 by jochang           #+#    #+#             */
/*   Updated: 2019/09/23 21:55:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_line	*init_line(int i, int prog_size)
{
	t_line	*line;

	line = ft_memalloc(sizeof(t_line));
	line->line_number = i;
	line->prior_data = prog_size;
	line->cmd = 16;
	return (line);
}

static int		mem_manage(t_token *token, char *cmd, t_line *line,
	t_table *table)
{
	if (token->state == NONE)
		free(token->content);
	if (*cmd == 0)
		free(line);
	else if (!populate_table(table, line))
	{
		free(line->label);
		free(line);
		return (0);
	}
	free(cmd);
	return (1);
}

int				get_bytecode(t_table *table, int fd)
{
	char	*cmd;
	t_token	token;
	t_line	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &cmd))
	{
		line = init_line(++i, table->prog_size);
		sanitize(&cmd);
		while ((token = lexer(cmd)).state != NONE)
		{
			if (!parser(line, &token))
			{
				free(token.content);
				return (0);
			}
			if (token.state != LABEL)
				free(token.content);
		}
		if (!mem_manage(&token, cmd, line, table))
			return (0);
	}
	return (1);
}
