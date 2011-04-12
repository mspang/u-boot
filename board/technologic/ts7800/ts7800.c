/*
 * Copyright (C) 2010-2011 Michael Spang <mspang@csclub.uwaterloo.ca>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	/* Technologic's MBR uses machine type 526, however the mainline
	   machine type is 1652. Set the machid environment variable
	   to 0x20e to boot Technologic kernels. */
	gd->bd->bi_arch_number = MACH_TYPE_TS78XX;
	gd->bd->bi_boot_params = 0x100;

	return 0;
}
