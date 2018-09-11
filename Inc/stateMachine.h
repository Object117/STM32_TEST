/*
 * stateMachine.h
 *
 *  Created on: 2018. 9. 6.
 *      Author: leejh
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

typedef struct state_machine STATE_MACHINE;

typedef enum {
	INIT_STATE = 0	,
	READY_STATE	,
	RUNNING_STATE	,
	STOP_STATE	,
	NONE_STATE
} MACHINE_STATE;

typedef enum {
	DOOR_CLOSE = 0	,
	DOOR_OPEN	,
	SWITCH_CLOSE	,
	SWITCH_OPEN		,
	PIR_NO_DETECT	,
	PIR_DETECTING
} ACTION;

ACTION doing_action;

STATE_MACHINE* init_state_machine(void);
void run_state_machine(STATE_MACHINE* state);

#endif /* STATEMACHINE_H_ */
