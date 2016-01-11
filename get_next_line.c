/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 11:55:39 by droly             #+#    #+#             */
/*   Updated: 2016/01/11 17:44:10 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_put_in_str(int i, int i2, char **line, char *str)
{
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
		i++;
	i++;
	str = ft_strnew(i2);
	i2 = 0;
	while ((*line)[i] != '\0')
	{
		str[i2] = (*line)[i];
		i++;
		i2++;
	}
	str[i2] = '\0';
	return (str);
}

int				ft_str_is_null(int i, int fd, char **str, char **line)
{
	char		*tmp;
	char		*tmp2;
	int			ret;

	ret = i;
	i = 0;
	while (ft_strchr(*line, 10) == NULL && ret > 0)
	{
		tmp = ft_strnew(BUFF_SIZE);
		ret = read(fd, tmp, BUFF_SIZE);
		tmp[ret] = '\0';
		tmp2 = ft_strnew(ft_strlen(*line) + ft_strlen(tmp));
		tmp2 = ft_strcpy(tmp2, *line);
		*line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		i++;
	}
	if (ft_strchr(*line, 10) != NULL)
	{
		*str = ft_put_in_str(0, 0, line, *str);
		return (1);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str = NULL;
	int			ret;

	ret = 0;
	if (str == NULL)
	{
		*line = ft_strnew(BUFF_SIZE);
		ret = read(fd, *line, BUFF_SIZE);
		(*line)[ret] = '\0';
		ret = ft_str_is_null(ret, fd, &str, line);
		return (ret);
	}
	if (str != NULL)
	{
		*line = ft_strnew(BUFF_SIZE + ft_strlen(str));
		ret = read(fd, *line, BUFF_SIZE);
		*line = ft_strjoin(str, *line);
		(*line)[ret + ft_strlen(str)] = '\0';
		free(str);
		str = NULL;
		ret = ft_str_is_null(ret, fd, &str, line);
		return (ret);
	}
	return (0);
}
