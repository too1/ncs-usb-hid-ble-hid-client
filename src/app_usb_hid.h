#ifndef __APP_USB_HID_H
#define __APP_USB_HID_H

#include <zephyr/kernel.h>

struct app_usb_hid_report {
	uint8_t data;
};

int app_usb_hid_init(void);

int app_usb_hid_send_report(struct app_usb_hid_report *report);

#endif
