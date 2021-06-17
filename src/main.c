/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:24:41 by pitriche          #+#    #+#             */
/*   Updated: 2021/06/17 14:44:55 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	/* open, close */
#include <stdio.h>	/* printf */
#include <stdlib.h>	/* exit */
#include <unistd.h>	/* read */

#include "woody.h"

static void	print_end(const char *error_message)
{
	printf("%s\n", error_message);
	exit(0);
}

static int	assert_header(elf64_header header)
{
	if (header.instruction_set != 0x3e)
		print_end("File architecture not suported. x86_64 only");


	if (*(uint32 *)(header.magic_number) != 0x464c457f)
		print_end("Unsupported binary type. ELF64 only");
	if (header.class_bit != 2)
		print_end("Unsupported binary type. 64 bits only");
	if (header.endianess != 1)
		print_end("Unsupported binary type. little endian only");
	if (header.type == 3)
		print_end("Unsupported file type. static ELF64 executable file only, us"
			"e gcc -static");
	if (header.type != 2)
		print_end("Unsupported file type. ELF64 executable file only");


	if (header.version != 1 || header.elf_version != 1)
		print_end("Deprecated ELF version");
	if (header.header_size != 0x40)
		print_end("Corrupted ELF64 header: incorrect size");

	if (header.program_header_size != 0x38)
		print_end("Corrupted ELF64 program header: incorrect size");
	if (header.section_header_size != 0x40)
		print_end("Corrupted ELF64 section header: incorrect size");
		
}

static void	print_header(elf64_header header)
{
	printf("%x - %c%c%c\n", header.magic_number[0], header.magic_number[1],
		header.magic_number[2], header.magic_number[3]);
	printf("class :       %d\n", header.class_bit);
	printf("endian :      %d\n", header.endianess);
	printf("elf version : %d\n\n", header.elf_version);

	printf("type :        %d\n", header.type);
	printf("ISE :         %#x\n", header.instruction_set);
	printf("version :     %d\n\n", header.version);

	printf("prog header entry : %p\n", (void *)header.program_header);
	printf("sec header entry :  %p\n", (void *)header.section_header);
	printf("sec names offset :  %#x\n\n", header.section_names);

	printf("flags :       %#x\n", header.flags);
	printf("header size : %#x\n\n", header.header_size);

	printf("program header size :    %#x\n", header.program_header_size);
	printf("program header entries : %d\n", header.program_header_entries);
	printf("section header size :    %#x\n", header.section_header_size);
	printf("section header entries : %d\n", header.section_header_entries);
}

static void	print_program_header(elf64_program_header header)
{
	printf("segment type : %d\n", header.segment_type);
	printf("flags :        %#x\n\n", header.flags);
	
	
	printf("address :    %#x\n", header.segment_addr);
	printf("size :       %ld\n", header.segment_size);
	printf("image size : %ld\n\n", header.file_img_size);

	printf("align : %ld\n", header.align);
	// printf("prog header entry : %p\n", (void *)header.program_header);
	// printf("sec header entry :  %p\n", (void *)header.section_header);
	// printf("sec names offset :  %#x\n\n", header.section_names);

	// printf("flags :       %#x\n", header.flags);
	// printf("header size : %#x\n\n", header.header_size);

	// printf("program header size :    %#x\n", header.program_header_size);
	// printf("program header entries : %d\n", header.program_header_entries);
	// printf("section header size :    %#x\n", header.section_header_size);
	// printf("section header entries : %d\n", header.section_header_entries);
}

/* ########################################################################## */

int	main(int ac, char **av)
{
	int						fd;
	elf64_header			header;
	elf64_program_header	*prog_header;

	if (ac != 2)
		print_end("Usage: ./woody_woodpacker 'program_name'");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_end("Couldn't open file");
	(void)!read(fd, &header, 0x40);

	assert_header(header);
	print_header(header);

	lseek(fd, header.program_header, SEEK_SET);
	prog_header = malloc(header.program_header_entries *
		sizeof(elf64_program_header));
	for (unsigned i = 0; i < header.program_header_entries; ++i)
	{
		(void)!read(fd, prog_header + i, 0x38);
		print_program_header(prog_header[i]);
		printf("\n ###################################################################### \n");
	}
	close(fd);
	return (0);
}