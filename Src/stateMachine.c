/*
 * stateMachine.c
 *
 *  Created on: 2018. 9. 6.
 *      Author: leejh
 */
#include"stateMachine.h"
#include"usart.h"
#include "device_led.h"
#include "device_relay.h"

uint8_t TxBuffer1[] = "in doing_ready_state/n";
uint8_t TxBuffer2[] = "in doing_running_state/n";

/*
 * STANDBY State		(NORMAL)
 * --> Inner Door 'CLOSE'
 * --> Ext Door 'CLOSE'
 * --> Baby 'NONE'
 * __________________________________________
 */

void STANDBY_inner_door_open(void) {
	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer1, sizeof(TxBuffer1), 10);		// TESTING

	LED_ON(LED_RED);
	LED_OFF(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

void STANDBY_inner_door_close(void) {

}

void STANDBY_extdoor_open(void) {

}

void STANDBY_extdoor_close(void) {

}

void STANDBY_baby_in(void) {

}

void STANDBY_baby_none(void) {

}

/*
 * READY State		(NORMAL)
 * --> Inner Door 'CLOSE'
 * --> Ext Door 'OPEN'
 * --> Baby 'NONE'
 * __________________________________________
 */
void READY_inner_door_open(void) {
	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer2, sizeof(TxBuffer2), 10);		// TESTING

	LED_OFF(LED_RED);
	LED_ON(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

void READY_inner_door_close(void) {

}

void READY_extdoor_open(void) {

}

void READY_extdoor_close(void) {

}

void READY_baby_in(void) {

}

void READY_baby_none(void) {

}

/*
 * ENTERed Baby in box State		(NORMAL)
 * --> Inner Door 'CLOSE'
 * --> Ext Door 'OPEN'
 * --> Baby 'IN'
 * __________________________________________
 */
void ENTER_inner_door_open(void) {
	LED_OFF(LED_RED);
	LED_OFF(LED_GREEN);
	LED_ON(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

void ENTER_inner_door_close(void) {

}

void ENTER_extdoor_open(void) {

}

void ENTER_extdoor_close(void) {

}

void ENTER_baby_in(void) {

}

void ENTER_baby_none(void) {

}

/*
 * PROTECTION in box State		(NORMAL)
 * --> Inner Door 'CLOSE'
 * --> Ext Door 'CLOSE'
 * --> Baby 'IN'
 * __________________________________________
 */
void PROTECTION_inner_door_open(void) {

}

void PROTECTION_inner_door_close(void) {

}

void PROTECTION_extdoor_open(void) {

}

void PROTECTION_extdoor_close(void) {

}

void PROTECTION_baby_in(void) {

}

void PROTECTION_baby_none(void) {

}

/*
 * CONFIRMation in box State		(NORMAL)
 * --> Inner Door 'OPEN'
 * --> Ext Door 'CLOSE'
 * --> Baby 'IN'
 * __________________________________________
 */
void CONFIRM_inner_door_open(void) {

}

void CONFIRM_inner_door_close(void) {

}

void CONFIRM_extdoor_open(void) {

}

void CONFIRM_extdoor_close(void) {

}

void CONFIRM_baby_in(void) {

}

void CONFIRM_baby_none(void) {

}

/*
 * EXIT baby in box State		(NORMAL)
 * --> Inner Door 'OPEN'
 * --> Ext Door 'CLOSE'
 * --> Baby 'NONE'
 * __________________________________________
 */
void EXIT_inner_door_open(void) {

}

void EXIT_inner_door_close(void) {

}

void EXIT_extdoor_open(void) {

}

void EXIT_extdoor_close(void) {

}

void EXIT_baby_in(void) {

}

void EXIT_baby_none(void) {

}


#if 0
//-----------------------------------------
static void standby_inner_door_close() {

	LED_ON(LED_RED);
	LED_OFF(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

static void doing_ready_state() {

	LED_OFF(LED_RED);
	LED_ON(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

static void doing_running_state() {

	LED_OFF(LED_RED);
	LED_OFF(LED_GREEN);
	LED_ON(LED_BLUE);
	LED_OFF(LED_ORANGE);
	excuteRelayTest_Interrupt();
}

static void doing_stop_state() {
	LED_OFF(LED_RED);
	LED_OFF(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_ON(LED_ORANGE);
	excuteRelayTest_Interrupt();
}
#endif


