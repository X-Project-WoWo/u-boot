/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian@popies.net>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * Configuation settings for the AT91SAM9261EK board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK	32768		/* slow clock xtal */
#define CONFIG_SYS_AT91_MAIN_CLOCK	18432000	/* 18.432 MHz crystal */

#ifdef CONFIG_AT91SAM9G10
#define CONFIG_AT91SAM9G10EK		/* It's an Atmel AT91SAM9G10 EK*/
#else
#define CONFIG_AT91SAM9261EK		/* It's an Atmel AT91SAM9261 EK*/
#endif

#include <asm/hardware.h>

#define CONFIG_ATMEL_LEGACY

/*
 * Hardware drivers
 */

/* LCD */
#define LCD_BPP				LCD_COLOR8
#define CONFIG_LCD_LOGO
#undef LCD_TEST_PATTERN
#define CONFIG_LCD_INFO
#define CONFIG_LCD_INFO_BELOW_LOGO
#define CONFIG_ATMEL_LCD
#ifdef CONFIG_AT91SAM9261EK
#define CONFIG_ATMEL_LCD_BGR555
#endif

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE

/* SDRAM */
#define CONFIG_SYS_SDRAM_BASE		0x20000000
#define CONFIG_SYS_SDRAM_SIZE		0x04000000
#define CONFIG_SYS_INIT_SP_ADDR \
	(ATMEL_BASE_SRAM + 16 * 1024 - GENERATED_GBL_DATA_SIZE)

/* NAND flash */
#ifdef CONFIG_CMD_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE		1
#define CONFIG_SYS_NAND_BASE			0x40000000
#define CONFIG_SYS_NAND_DBW_8
/* our ALE is AD22 */
#define CONFIG_SYS_NAND_MASK_ALE		(1 << 22)
/* our CLE is AD21 */
#define CONFIG_SYS_NAND_MASK_CLE		(1 << 21)
#define CONFIG_SYS_NAND_ENABLE_PIN		AT91_PIN_PC14
#define CONFIG_SYS_NAND_READY_PIN		AT91_PIN_PC15

#endif

/* Ethernet */
#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BASE		0x30000000
#define DM9000_IO			CONFIG_DM9000_BASE
#define DM9000_DATA			(CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT
#define CONFIG_DM9000_NO_SROM
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_RESET_PHY_R

/* USB */
#define CONFIG_USB_ATMEL
#define CONFIG_USB_ATMEL_CLK_SEL_PLLB
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_CPU_INIT
#define CONFIG_SYS_USB_OHCI_REGS_BASE		0x00500000	/* AT91SAM9261_UHP_BASE */
#ifdef CONFIG_AT91SAM9G10EK
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"at91sam9g10"
#else
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"at91sam9261"
#endif
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2

#ifdef CONFIG_SYS_USE_DATAFLASH_CS0

/* bootstrap + u-boot + env + linux in dataflash on CS0 */

#elif CONFIG_SYS_USE_DATAFLASH_CS3

/* bootstrap + u-boot + env + linux in dataflash on CS3 */

#else /* CONFIG_SYS_USE_NANDFLASH */

/* bootstrap + u-boot + env + linux in nandflash */
#endif

#endif
