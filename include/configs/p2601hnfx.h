/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2013 Luka Perkov <luka@openwrt.org>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"P-2601HN-Fx"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"ZyXEL P-2601HN-Fx"
#define CONFIG_SYS_DRAM_PROBE

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */
#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */
#define CONFIG_LTQ_SUPPORT_NOR_FLASH	/* Have a parallel NOR flash */

/* Switch devices */
#define CONFIG_SWITCH_MULTI
#define CONFIG_SWITCH_RTL8306

/* Environment */
#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#elif defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(128 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1
#define CONFIG_CONSOLE_DEV		"ttyLTQ1"

/* Compression */
#define CONFIG_LZMA

/* Auto boot */
#define CONFIG_BOOTDELAY		2

/* Commands */
#define CONFIG_CMD_PING

/* Pull in default board configs for Lantiq XWAY Danube */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

/* Environment configuration */
#define CONFIG_BOOTCOMMAND			\
	"run addeth; bootm ${kernel_addr}"

#define CONFIG_ENV_UPDATE_UBOOT_NOR					\
	"update-uboot-nor=run load-uboot-norspl-lzo write-uboot-nor\0"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_UPDATE_UBOOT_NOR	\
	"kernel_addr=0xB0040000\0"

/* temporary */
#define CONFIG_ETHADDR		00:11:22:33:44:55
#define CONFIG_SERVERIP		192.168.1.103
#define CONFIG_IPADDR		192.168.1.50

#endif /* __CONFIG_H */
