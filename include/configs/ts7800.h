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

#ifndef _CONFIG_TS7800_H
#define _CONFIG_TS7800_H

/*
 * User Interface Configuration
 */

#define CONFIG_IDENT_STRING	" TS-7800"
#define	CONFIG_SYS_PROMPT	"TS-7800> "
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_BOOTDELAY	3

/*
 * Flash Driver
 */

#define CONFIG_SYS_NO_FLASH

/*
 * Commands Configuration
 */

#include <config_cmd_default.h>
#define CONFIG_CMD_PING
#define CONFIG_CMD_MII

/*
 * Serial Port Configuration
 */

#define CONFIG_CONS_INDEX	1
#define CONFIG_BAUDRATE		115200

/*
 * Environment Configuration
 */

#define CONFIG_ENV_IS_NOWHERE	1
#define CONFIG_ENV_SIZE		0x2000

/*
 * Limits
 */

#define	CONFIG_SYS_CBSIZE	1024	/* Console I/O Buff Size */
#define	CONFIG_SYS_PBSIZE		/* Print Buffer Size */ \
	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16	/* Max args to U-Boot commands */

/*
 * System Components
 */

#define CONFIG_MARVELL		1
#define CONFIG_ARM926EJS	1	/* Basic Architecture */
#define CONFIG_FEROCEON		1	/* CPU Core subversion */
#define CONFIG_ORION5X		1	/* SOC Family Name */
#define CONFIG_88F5182		1	/* SOC Name */
#define CONFIG_MACH_TS78XX	1	/* Machine type */
#define CONFIG_SYS_HZ		1000

/*
 * Board Initialization
 */

#define CONFIG_ARCH_MISC_INIT	/* call arch_misc_init() */
#define CONFIG_ARCH_CPU_INIT	/* call arch_cpu_init() */
#define CONFIG_SKIP_LOWLEVEL_INIT /* U-Boot starts with RAM initialized */

/* MPP configuration need not be changed from power-on */
#define ORION5X_MPP0_7		0x00000000
#define ORION5X_MPP8_15		0x00000000
#define ORION5X_MPP16_23	0x00000000
#define ORION5X_GPIO_OUT_ENABLE	0xffffffff

/*
 * Memory Layout
 */

#define CONFIG_SYS_TEXT_BASE	0x00008000 /* Boards loads U-Boot at 32 kB */
#define CONFIG_SYS_INIT_SP_ADDR	0x00100000 /* Initial stack at 1 MB */
#define CONFIG_SYS_MALLOC_LEN	0x00020000 /* Reserve 128 kB for malloc() */

#define CONFIG_SYS_SDRAM_BASE	0x00000000 /* RAM starts at address 0 */
#define CONFIG_NR_DRAM_BANKS	1 /* Board has one 128 MB RAM bank */

#define CONFIG_SYS_LOAD_ADDR	0x00800000 /* Load kernels at 8 MB */

/* Memtest skips the first 4k (vectors) and the last 2MB (U-Boot) */
#define CONFIG_SYS_MEMTEST_START	0x00001000
#define CONFIG_SYS_MEMTEST_END		0x07e00000

/*
 * UART Driver
 */

#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		CONFIG_SYS_TCLK
#define CONFIG_SYS_NS16550_COM1		ORION5X_UART0_BASE
#define CONFIG_SYS_NS16550_COM2		ORION5X_UART1_BASE
#define CONFIG_SYS_BAUDRATE_TABLE \
	{ 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600 }

/*
 * Network Driver
 */

#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE
#define CONFIG_MVGBE_PORTS	{1}
#define CONFIG_PRESERVE_LOCAL_MAC
#define CONFIG_PHY_BASE_ADR	0
#define CONFIG_NETCONSOLE
#define CONFIG_NET_MULTI
#define CONFIG_MII
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
#define CONFIG_ENV_OVERWRITE
#endif

/*
 * Linux
 */

#define CONFIG_CMDLINE_TAG	1	/* enable passing of ATAGs */
#define CONFIG_INITRD_TAG	1	/* enable INITRD tag */
#define CONFIG_SETUP_MEMORY_TAGS 1	/* enable memory tag */

#endif /* _CONFIG_TS7800_H */
