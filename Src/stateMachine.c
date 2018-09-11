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

#if 1
struct state_machine {
	MACHINE_STATE state;
	void (*do_something)(STATE_MACHINE* state);
};
#endif

#if 1		//____________Success code.
static void doing_init_state() {
	doing_action = DOOR_CLOSE;
	LED_ON(LED_RED);
	LED_OFF(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

static void doing_ready_state() {
//	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer1, sizeof(TxBuffer1), 10);
	LED_OFF(LED_RED);
	LED_ON(LED_GREEN);
	LED_OFF(LED_BLUE);
	LED_OFF(LED_ORANGE);
}

static void doing_running_state() {
//	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer2, sizeof(TxBuffer2), 10);
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

static void doing_what(STATE_MACHINE* state) {
	switch(state->state) {
		case INIT_STATE		:
			doing_init_state();
			if(doing_action == DOOR_OPEN) {
				state->state = READY_STATE;
			}
			break;

		case READY_STATE		:
			doing_ready_state();
			if(doing_action == SWITCH_OPEN) {
				state->state = RUNNING_STATE;
			}
			break;

		case RUNNING_STATE		:
			doing_running_state();
			if(doing_action == DOOR_CLOSE) {
				state->state = STOP_STATE;
			}
			break;

		case STOP_STATE		:
			doing_stop_state();
			state->state = INIT_STATE;
			break;

		default		:

			break;
	}
}

STATE_MACHINE machine_init = {INIT_STATE, doing_what};
STATE_MACHINE machine_ready = {READY_STATE, doing_what};
STATE_MACHINE machine_running = {RUNNING_STATE, doing_what};
STATE_MACHINE machine_stop = {STOP_STATE, doing_what};

#else		// FAIL CODE______________________________________________________
static void doing_init_state(STATE_MACHINE* state) {
//	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer1, sizeof(TxBuffer1), 10);
	LED_ON(LED4);	// ORANGE
	state->state = READY_STATE;
}

static void doing_ready_state(STATE_MACHINE* state) {

	LED_ON(LED6);	// BLUE
	state->state = RUNNING_STATE;
}

static void doing_running_state(STATE_MACHINE* state) {

	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer2, sizeof(TxBuffer2), 10);
	state->state = STOP_STATE;
}

static void doing_stop_state(STATE_MACHINE* state) {

	state->state = NONE_STATE;
}

STATE_MACHINE machine_init = {INIT_STATE, doing_init_state};
STATE_MACHINE machine_ready = {READY_STATE, doing_ready_state};
STATE_MACHINE machine_running = {RUNNING_STATE, doing_running_state};
STATE_MACHINE machine_stop = {STOP_STATE, doing_stop_state};
#endif  //______________________________________________________

static STATE_MACHINE* do_state_machine(STATE_MACHINE* state) {
	STATE_MACHINE* newState = NULL;
	switch(state->state) {
		case INIT_STATE		:
			newState = &machine_ready;
			break;

		case READY_STATE	:
			newState = &machine_running;
			break;

		case RUNNING_STATE	:
			newState = &machine_stop;
			break;

		case STOP_STATE		:
			newState = &machine_init;
			break;
		default		:

			break;
	}
	state->do_something(state);
	return newState;
}

STATE_MACHINE* init_state_machine(void) {
	return &machine_init;
}

void run_state_machine(STATE_MACHINE* state) {
	STATE_MACHINE* machine;
	do {
		machine = do_state_machine(state);
	}while(machine != NULL);

}
