#ifndef __APP_BLE_HID_CLIENT_H
#define __APP_BLE_HID_CLIENT_H

#include <zephyr/kernel.h>

// An enum containing the different types of events that can be sent from the app_ble_hid_client module
enum app_ble_hid_client_evt_type {APP_BLE_HID_CLIENT_EVT_CONNECTED, 
								  APP_BLE_HID_CLIENT_EVT_DISCONNECTED, 
								  APP_BLE_HID_CLIENT_EVT_SERVICE_DISC_COMPLETE, 
								  APP_BLE_HID_CLIENT_EVT_PASSKEY_DISPLAY, 
								  APP_BLE_HID_CLIENT_EVT_DATA_RECEIVED};

// Event struct containing event data to be forwarded through the application
struct app_ble_hid_client_event {
	enum app_ble_hid_client_evt_type type;
	int passkey;
};

typedef void (*app_ble_hid_client_callback_func)(struct app_ble_hid_client_event *event);

// Configuration struct for initializing the app_ble_hid module
struct app_ble_hid_client_config {
	app_ble_hid_client_callback_func callback;
};

int app_ble_hid_client_init(struct app_ble_hid_client_config *config);

#endif
