/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:22:34 by user42            #+#    #+#             */
/*   Updated: 2021/06/16 16:50:13 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H

typedef	unsigned long	uint64;
typedef	unsigned int	uint32;
typedef	unsigned short	uint16;
typedef	unsigned char	uint8;

/* ########################################################################## */

typedef struct	s_elf64_header
{
	/* 0x00 */
	uint8	magic_number[4];
	uint8	class_bit;			/* 1 for 32 bits, 2 for 64 bits */
	uint8	endianess;			/* 1 for little endian, 2 for big endian */
	uint8	elf_version;		/* should be 1 */
	/* 0x08 */
	uint8	target_abi_version;
	uint8	pad[7];
	/* 0x10 */
	uint16	type;				/* 2 for static executable file */
	uint16	instruction_set;	/* 0x3E for x86-64 */
	uint32	version;			/* should be 1 */
	/* 0x18 */
	uint64	memory_entry;		/* entry point */
	/* 0x20 */
	uint64	program_header;		/* program header offset */
	/* 0x28 */
	uint64	section_header;		/* section header offset */
	/* 0x30 */
	uint32	flags;				/* mostly useless */
	uint16	header_size;		/* this header's size, 64 bytes for ELF64 */
	uint16	program_header_size;	/* header size (for each entry) */
	/* 0x38 */
	uint16	program_header_entries;
	uint16	section_header_size;	/* header size (for each entry) */
	uint16	section_header_entries;
	uint16	section_names;		/* section names offset within section header */
}				elf64_header;

typedef struct	s_elf64_program_header
{
	/* 0x00 */
	uint32	segment_type;
	uint32	flags;
	/* 0x08 */
	uint64	file_img;		/* file image offset */
	/* 0x10 */
	uint64	segment_addr;	/* Virtual address of the segment in memory */
	/* 0x18 */
	uint64	segment_virtual_addr;	/* useless */
	/* 0x20 */
	uint64	file_img_size;
	/* 0x28 */
	uint64	segment_size;
	/* 0x30 */
	uint64	align;			/* 0 or 1 for no align */
}				elf64_program_header;

#endif
