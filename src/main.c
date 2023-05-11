/*
 * Copyright (c) 2016-2018 Intel Corporation.
 * Copyright (c) 2018-2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include "app_usb_hid.h"

#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(main);

void main(void)
{
	int ret;

	ret = app_usb_hid_init();
	if(ret < 0) {
		return;
	}

	LOG_INF("USB BLE HID application started");

	while (1) {
		k_msleep(1000);
	}
}