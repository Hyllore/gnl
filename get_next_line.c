/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 11:55:39 by droly             #+#    #+#             */
/*   Updated: 2016/01/03 16:21:37 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	length_file(int fd)
{
	int		size;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	size = 0;
	ret = 1;
	while (ret > 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		size += ret;
	}
	return (ret == -1 ? 0 : size);
}

static char	**get_file(int fd, int size)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**str;

	i = 0;
	ret = 1;
	str[1] = NULL;
//	ft_putnbr(size);
	str[0] = malloc(sizeof(char*) * (size));
	while (ret > 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		j = 0;
//		ft_putchar('8');
		while (buf[j] != '\0')
		{
			str[0][i] = buf[j];
			i++;
			j++;
		}
	}
	ft_putnbr(i);
	str[0][i] = '\0';
//	ft_putstr(str[0]);
	return (ret == -1 ? NULL : str);
}

int				get_next_line(int const fd, char **line)
{
	static int	i;
	int			ret;
//	ft_putnbr(i);
	while (line[0][i] != '\n' || line[0][i] != '\0')
	{
		ft_putchar(line[0][i]);
		i++;
	}
	i++;
	ft_putchar('\n');
	return (i);
}

int main(int argc, char **argv)
{
	int fd;
	char *file;
	int fd2;
	char **str;
	int size;

	file = argv[1];
	if (argc != 2)
		return(0);
	fd = open(file , O_RDONLY);
	fd2 = open(file, O_RDONLY);
	size = length_file(fd);
	str = get_file(fd2, size);
	while (fd)
		get_next_line(fd, str);
}
