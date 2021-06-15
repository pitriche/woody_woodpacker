/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:24:41 by pitriche          #+#    #+#             */
/*   Updated: 2021/06/15 23:44:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	/* open, close */
#include <stdio.h>	/* printf */
#include <stdlib.h>	/* exit */
#include <unistd.h>	/* read */

static void	print_end(const char *error_message)
{
	printf("%s\n", error_message);
	exit(0);
}

/* ########################################################################## */

int	main(int ac, char **av)
{
	int				fd;
	unsigned char	buffer[0x40];

	if (ac != 2)
		print_end("Usage: ./woody_woodpacker 'program_name'");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_end("Couldn't open file");
	read(fd, buffer, 0x40);
	for (unsigned i = 0; i < 0x40; ++i)
		printf("%x ", buffer[i]);
	close(fd);
	return (0);
}