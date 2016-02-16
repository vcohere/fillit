/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:14:28 by vcohere           #+#    #+#             */
/*   Updated: 2016/02/16 19:57:39 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		handle_error(char *s1, char *s2, char *s3)
{
	if (s1)
		ft_putstr(s1);
	if (s2)
		ft_putstr(s2);
	if (s3)
		ft_putendl(s3);
	exit(-1);
}

int			check_file(char *name)
{
	int		fd;
	int		four;
	int		total;
	char	*line;

	total = 0;
	four = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		return (1);
	while (get_next_line(fd, &line))
	{
		if ((four + 1) % 5 == 0 && line[0] != '\0')
			return (1);
		else if (ft_strlen(line) != 4 && (four + 1) % 5 != 0)
			return (1);
		else if ((four + 1) % 5 == 0 && total % 4 != 0)
			return (1);
		ft_putnbr(total);
		ft_putendl("");
		total += ft_strlenc(line, '#');
		four++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		handle_error("usage: ", argv[0], " file.fillit");
	if (check_file(argv[1]))
		handle_error("error", NULL, "");
	return (0);
}
