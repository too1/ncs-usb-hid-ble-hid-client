/*
 * Copyright (c) 2016-2018 Intel Corporation.
 * Copyright (c) 2018-2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include "app_usb_hid.h"
#include "app_ble_hid_client.h"

#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(main);

void app_ble_hid_client_callback(struct app_ble_hid_client_event *event)
{
	switch(event->type) {
		case APP_BLE_HID_CLIENT_EVT_CONNECTED:
			break;
			
		case APP_BLE_HID_CLIENT_EVT_DISCONNECTED:
			break;

		case APP_BLE_HID_CLIENT_EVT_SERVICE_DISC_COMPLETE:
			break;

		case APP_BLE_HID_CLIENT_EVT_PASSKEY_DISPLAY:
			break;

		case APP_BLE_HID_CLIENT_EVT_DATA_RECEIVED:
			break;

		default:
			LOG_ERR("Unknown BLE HID client event received");
			break;
	}
}

void main(void)
{
	int ret;

	ret = app_usb_hid_init();
	if (ret < 0) {
		LOG_ERR("APP USB HID init failed");
		return;
	}

	struct app_ble_hid_client_config config = {.callback = app_ble_hid_client_callback};
	ret = app_ble_hid_client_init(&config);
	if (ret < 0) {
		LOG_ERR("APP BLE HID client init failed");
		return;
	}

	LOG_INF("USB BLE HID application started");

	while (1) {
		k_msleep(1000);
	}
}