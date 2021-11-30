#define LIBRARY_LOG_NAME "read_button"
#define LIBRARY_LOG_LEVEL LOG_INFO
#include "logging_stack.h"

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "event_groups.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define BTN_PRESSED (0)
#define BTN_NOT_PRESSED (1)

#define READ_BTN_PIN_LEVEL() GPIO_PinRead(BOARD_SW1_GPIO_PORT, BOARD_SW1_GPIO_PIN)
#define LED_OFF()            GPIO_PinWrite(BOARD_LED_BLUE_GPIO_PORT, BOARD_LED_BLUE_GPIO_PIN, 1)
#define LED_TOGGLE()         GPIO_PortToggle(BOARD_LED_BLUE_GPIO_PORT, 1u << BOARD_LED_BLUE_GPIO_PIN);
//Button pressed event bit(flag)
#define BTN_PRESSED_Pos                         0U
#define BTN_PRESSED_Msk                         (1UL << BTN_PRESSED_Pos)


#define BOARD_USER_BUTTON_GPIO GPIO5
#define BOARD_USER_BUTTON_GPIO_PIN (0U)
#define BOARD_USER_BUTTON_IRQ         GPIO5_Combined_0_15_IRQn
#define BOARD_USER_BUTTON_IRQ_HANDLER GPIO5_Combined_0_15_IRQHandler
#define BOARD_USER_BUTTON_NAME        "SW8"

#define BOARD_SW_GPIO        BOARD_USER_BUTTON_GPIO
#define BOARD_SW_GPIO_PIN    BOARD_USER_BUTTON_GPIO_PIN
#define BOARD_SW_IRQ         BOARD_USER_BUTTON_IRQ
#define BOARD_SW_IRQ_HANDLER BOARD_USER_BUTTON_IRQ_HANDLER
#define BOARD_SW_NAME        BOARD_USER_BUTTON_NAME

static gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
};

/*!
 * @brief Task responsible for reading a button state (0 or 1).
 * 		  The task sets an event flag in case the button is pressed.
 */
void btn_read_task(void *pvParameters)
{
	TickType_t last_wake_time;
	uint8_t curr_state /*,prev_state*/ = BTN_NOT_PRESSED; //State for the button
	//Set toggle interval to 1000ms
	const TickType_t sample_interval = 2000 / portTICK_PERIOD_MS;

	// Initialize the last_wake_time variable with the current time
	last_wake_time = xTaskGetTickCount();

        GPIO_PinInit(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, &sw_config);

	for( ;; )
	{
		// Wait for the next cycle.
		vTaskDelayUntil( &last_wake_time, sample_interval );
		// Get the level on button pin
		curr_state = GPIO_PinRead(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN);
		// if ((curr_state == BTN_PRESSED) && (prev_state == BTN_NOT_PRESSED)) {
		// 	xEventGroupSetBits(xFlagsEventGroup, BTN_PRESSED_Msk);
		// }
		// prev_state = curr_state;
                LogInfo(("Button state=%d", curr_state));
	}
}

