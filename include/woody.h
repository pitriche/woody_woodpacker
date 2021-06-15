/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:22:34 by user42            #+#    #+#             */
/*   Updated: 2021/06/15 23:44:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H

typedef struct	s_elf64_header
{
	/* 0x00 */
	unsigned char	magic_number[4];
	unsigned char	class_bit;	/* 1 for 32 bits, 2 for 64 bits */
	unsigned char	endianess;	/* 1 for little endian, 2 for big endian */
	unsigned char	elf_version;
	unsigned char	target_abi;
	/* 0x08 */
	unsigned char	target_abi_version;
	unsigned char	pad[7];
	/* 0x10 */
	unsigned short	type;				/* 2 for executable file */
	unsigned short	instruction_set;	/* 0x3E for x86-64 */
	unsigned int	version;
	/* 0x18 */
	
	/* 0x20 */
}				elf64_header;


#endif