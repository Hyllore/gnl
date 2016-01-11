/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:44:52 by droly             #+#    #+#             */
/*   Updated: 2016/01/11 17:45:21 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		free(line);
	}
	while (1)
		;
}
