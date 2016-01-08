/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 11:55:39 by droly             #+#    #+#             */
/*   Updated: 2016/01/08 16:10:49 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char *str;
	int ret;
	char *tmp;
	int i;
	char *tmp2;
	int i2;

	i2 = 0;
	tmp2 = NULL;
	i = 1;
	tmp = NULL;
	ret = 0;
	if (str == NULL)
	{
//		ft_putchar('1');
		*line = ft_strnew(BUFF_SIZE);
//		ft_putchar('2');
//		ft_putchar('3');
		ret = read(fd, *line, BUFF_SIZE);
//		ft_putchar('4');
		(*line)[BUFF_SIZE + 1] = '\0';
//		ft_putchar('5');
//		ft_putchar(' ');
//		ft_putnbr(ft_strlen(*line));
//		ft_putchar(' ');
		while (ft_strchr(*line, 10) == NULL && BUFF_SIZE * i == ft_strlen(*line))
		{
//			ft_putchar('6');
			tmp = ft_strnew(BUFF_SIZE);
			ret = read(fd, tmp, BUFF_SIZE);
			tmp[BUFF_SIZE + 1] = '\0';
			tmp2 = ft_strnew(BUFF_SIZE + ft_strlen(tmp) - 1);
			tmp2 = ft_strcpy(tmp2, *line);
			*line = ft_strnew(ft_strlen(tmp2) + ft_strlen(tmp) - 2);
			*line = ft_strjoin(tmp2, tmp);
//			ft_putchar(' ');
//			ft_putnbr(ft_strlen(*line));
//			ft_putchar(' ');
			i++;
		}
		if (ft_strchr(*line, 10) != NULL)
		{
			i = 0;
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			i++;
			while ((*line)[i] != '\0')
			{
				i++;
				i2++;
			}
			i = 0;
			while ((*line)[i] != '\0')
			{
				i++;
			}
			i++;
			str = ft_strnew(i2 - 1);
			i2 = 0;
			while ((*line)[i] != '\0')
			{
				str[i2] = (*line)[i];
				i++;
				i2++;
			}
			str[i2] = '\0';
			return (1);
		}
		if (BUFF_SIZE * i != ft_strlen(*line))
		{
			return (0);
		}
	}
	if (str != NULL)
	{
		*line = ft_strnew(BUFF_SIZE + ft_strlen(str) - 1);
		ret = read(fd, *line, BUFF_SIZE);
		*line = ft_strjoin(str, *line);
		(*line)[BUFF_SIZE + ft_strlen(str)] = '\0';
		while (ft_strchr(*line, 10) == NULL && BUFF_SIZE + ft_strlen(str) ==
				ft_strlen(*line))
		{
//			ft_putchar('6');
			tmp = ft_strnew(BUFF_SIZE);
			ret = read(fd, tmp, BUFF_SIZE);
			tmp[BUFF_SIZE + 1] = '\0';
			tmp2 = ft_strnew(ft_strlen(*line) + ft_strlen(tmp) - 2);
			tmp2 = ft_strcpy(tmp2, *line);
			*line = ft_strnew(ft_strlen(tmp2) + ft_strlen(tmp) - 2);
			*line = ft_strjoin(tmp2, tmp);
//			ft_putchar(' ');
//			ft_putnbr(ft_strlen(*line));
//			ft_putchar(' ');
			i++;
		}
		if (ft_strchr(*line, 10) != NULL)
		{
			i = 0;
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			i++;
			while ((*line)[i] != '\0')
			{
				i++;
				i2++;
			}
			i = 0;
			while ((*line)[i] != '\0')
			{
				i++;
			}
			i++;
			str = ft_strnew(i2 - 1);
			i2 = 0;
			while ((*line)[i] != '\0')
			{
				str[i2] = (*line)[i];
				i++;
				i2++;
			}
			str[i2] = '\0';
			return (1);
		}
		if (BUFF_SIZE + ft_strlen(str) != ft_strlen(*line))
		{
			return (0);
		}
	}
	return (0);
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
//		sleep(1);
		ft_putendl(line);
	}
}
