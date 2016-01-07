/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 11:55:39 by droly             #+#    #+#             */
/*   Updated: 2016/01/07 17:57:34 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char *str;
	int ret;
	char *tmp;
	int i;

	i = 1;
	tmp = NULL;
	ret = 0;
	if (str == NULL)
	{
		ft_putchar('1');
		*line = ft_strnew(BUFF_SIZE);
		ft_putchar('2');
		ft_putchar('3');
		ret = read(fd, *line, BUFF_SIZE);
		ft_putchar('4');
		(*line)[BUFF_SIZE + 1] = '\0';
		ft_putchar('5');
		ft_putnbr(ft_strlen(*line));
		while (ft_strchr(*line, 10) == NULL && BUFF_SIZE * i == ft_strlen(*line))
		{
			ft_putchar('6');
			tmp = ft_strnew(BUFF_SIZE);
			ret = read(fd, tmp, BUFF_SIZE);
			ft_strjoin(*line, tmp);
			i++;
		}
	}
	if (str != NULL)
	{
		*line = ft_strnew(BUFF_SIZE + ft_strlen(str) - 1);
		ret = read(fd, *line, BUFF_SIZE);
		*line = ft_strjoin(str, *line);
		(*line)[BUFF_SIZE + ft_strlen(str)] = '\0';
		if (ft_strchr(*line, 10) == NULL && BUFF_SIZE + ft_strlen(str) ==
				ft_strlen(*line))
		{
			str = ft_strnew(ft_strlen(*line) - 1);
			str = ft_strcpy(str, *line);
			return (1);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	line = NULL;
	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		sleep(1);
		ft_putstr(line);
	}
}
