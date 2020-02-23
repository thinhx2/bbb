/**
 * User space driver API for chipsailing's fingerprint device.
 * ATTENTION: Do NOT edit this file unless the corresponding driver changed.
 *
 * Copyright (C) 2016 chipsailing Corporation. <http://www.chipsailingcorp.com>
 * Copyright (C) 2016 XXX <mailto:xxx@chipsailingcorp.com>
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General 
 * Public License for more details.
**/

#ifndef __CF_CTRL_API_H__
#define __CF_CTRL_API_H__

/* Device node. */
#define CF_CTL_DEV_NAME "/dev/cs_spi"

/* Max driver version buffer length. */
#define CF_DRV_VERSION_LEN 32

typedef enum {
    CF_KEY_NONE = 0,
    CF_KEY_HOME,
    CF_KEY_MENU,
    CF_KEY_BACK,
	CF_KEY_F18,//press_down or lift_up
	CF_KEY_F19,//single tap
	CF_KEY_F20,//double tap
	CF_KEY_F21,//long press
	CF_KEY_ENTER,
	CF_KEY_UP,
	CF_KEY_LEFT,
	CF_KEY_RIGHT,
	CF_KEY_DOWN,
	CF_KEY_WAKEUP,
} cf_key_type_t;

typedef struct {
    cf_key_type_t key;
    int value; /* for key type, 0 means up, 1 means down. */
} cf_key_event_t;

/* Magic code for IOCTL-subsystem, 'k' means 'chipsailing'. */
#define CF_IOC_MAGIC 'k'

/* Androind system-wide key event, for navigation purpose. */
#define CF_IOC_REPORT_KEY_EVENT _IOW(CF_IOC_MAGIC, 0x07, cf_key_event_t *)

/* HW reset the fingerprint module. */
#define CF_IOC_RESET_DEVICE     _IOW(CF_IOC_MAGIC, 0x08,unsigned char)

/* Low-level IRQ control. */
#define CF_IOC_ENABLE_IRQ       _IO(CF_IOC_MAGIC, 0x11)
#define CF_IOC_DISABLE_IRQ      _IO(CF_IOC_MAGIC, 0x12)

/* Allocate/Release driver resource (GPIO/SPI etc.). */
#define CF_IOC_INIT_GPIO        _IO(CF_IOC_MAGIC, 0x13)
#define CF_IOC_REQUEST_IRQ      _IO(CF_IOC_MAGIC, 0x14)
#define CF_IOC_DEINIT_GPIO      _IO(CF_IOC_MAGIC, 0x15)
 

/* Sync 'cf_driver_config_t', the driver configuration. */
#define CF_IOC_SYNC_CONFIG      _IOWR(CF_IOC_MAGIC, 0x0a, void *)

/* Query the driver version string. */
#define CF_IOC_GET_VERSION      _IOR(CF_IOC_MAGIC, 0x20, const char *)

/* SPI bus clock control, for power-saving purpose. */
#define CF_IOC_ENABLE_SPI_CLK   _IO(CF_IOC_MAGIC, 0x30)
#define CF_IOC_DISABLE_SPI_CLK  _IO(CF_IOC_MAGIC, 0x40)

/* Fingerprint module power control. */
#define CF_IOC_ENABLE_POWER     _IO(CF_IOC_MAGIC, 0x50)
#define CF_IOC_DISABLE_POWER    _IO(CF_IOC_MAGIC, 0x60)

#endif /* __CF_CTRL_API_H__ */
