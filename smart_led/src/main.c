#define LOG_LEVEL 4
#include <logging/log.h>
LOG_MODULE_REGISTER(smartled);

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/led_strip.h>
#include <drivers/uart.h>
#include <usb/usb_device.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS 100

/* Smart LED */
#define SMART_LED_NODE DT_ALIAS(smart_led)
#define RGB(_r, _g, _b) {.r = (_r), .g = (_g), .b = (_b)}

static const struct led_rgb colors[] = {
	RGB(0x0f, 0x00, 0x00), /* red */
	RGB(0x00, 0x0f, 0x00), /* green */
	RGB(0x00, 0x00, 0x0f), /* blue */
};

struct led_rgb pixel;

static const struct device *smart_led = DEVICE_DT_GET(SMART_LED_NODE);

void main(void)
{
	int ret;
	size_t color = 0;
	const struct device *dev;

	dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_shell_uart));
	if (!device_is_ready(dev) || usb_enable(NULL)) {
	}

	if (device_is_ready(smart_led)) {
		LOG_INF("Found smart LED device %s", smart_led->name);
	} else {
		LOG_ERR("Smart LED device %s is not ready", smart_led->name);
		return;
	}

	while (1) {

		memcpy(&pixel, &colors[color], sizeof(struct led_rgb));
		ret = led_strip_update_rgb(smart_led, &pixel, 1);

		if (ret) {
			LOG_ERR("couldn't update smart LED: %d", ret);
		}

		color++;
		if (color == ARRAY_SIZE(colors)) {
			color = 0;
		}

		k_msleep(SLEEP_TIME_MS);
	}
}
