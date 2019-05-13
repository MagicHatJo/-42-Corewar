/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:48:30 by jtashako          #+#    #+#             */
/*   Updated: 2019/03/11 22:48:49 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	new_cor(char *fn, t_header s, t_byte file)
{
	char	*cor;
	int		fd;

	cor = ft_strnew(ft_strlen(fn) + 2);
	cor = ft_strccpy(cor, fn, '.');
	cor = ft_strcat(cor, ".cor");
	fd = open(cor, O_CREAT | O_RDWR | O_TRUNC, 0777);
	free(cor);
	write(fd, &s, HEADER_SIZE);
	write(fd, file.code, file.count);
	close(fd);
}

static void	assembler(char *file)
{
	int			fd;
	t_header	h;
	t_byte		b;

	fd = open(file, O_RDONLY);
	if (fd == -1 || (read(fd, &fd, 0)) == -1)
		err_invfile(file);
	ft_memset(&h, 0, HEADER_SIZE);
	b = t_byte_init();
	if (get_header(&h, fd, file) && get_bytecode(&b, fd, file))
	{
		h.prog_size = END32(b.count);
		new_cor(file, h, b);
		t_byte_free(&b);
	}
	close(fd);
}

int			main(int ac, char **av)
{
	int		i;

	err_nofile("asm", ac);
	i = 0;
	while (++i < ac)
	{
		if (valid_extension(av[i], "s"))
			assembler(av[i]);
		else if (valid_extension(av[i], "cor"))
			ft_printf("Disassembler not implemented\n");
		else
			err_invfile(av[1]);
	}
	return (0);
}
