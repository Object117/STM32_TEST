/*
 * stateMachine.h
 *
 *  Created on: 2018. 9. 6.
 *      Author: leejh
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#if 1

typedef struct action {
	void (*inner_door_open)(void);
	void (*inner_door_close)(void);
	void (*extdoor_open)(void);
	void (*extdoor_close)(void);
	void (*baby_in)(void);
	void (*baby_none)(void);
} USER_ACTION;


void STANDBY_inner_door_open(void);
void STANDBY_inner_door_close(void);
void STANDBY_extdoor_open(void);
void STANDBY_extdoor_close(void);
void STANDBY_baby_in(void);
void STANDBY_baby_none(void);

void READY_inner_door_open(void);
void READY_inner_door_close(void);
void READY_extdoor_open(void);
void READY_extdoor_close(void);
void READY_baby_in(void);
void READY_baby_none(void);

void ENTER_inner_door_open(void);
void ENTER_inner_door_close(void);
void ENTER_extdoor_open(void);
void ENTER_extdoor_close(void);
void ENTER_baby_in(void);
void ENTER_baby_none(void);

void PROTECTION_inner_door_open(void);
void PROTECTION_inner_door_close(void);
void PROTECTION_extdoor_open(void);
void PROTECTION_extdoor_close(void);
void PROTECTION_baby_in(void);
void PROTECTION_baby_none(void);

void CONFIRM_inner_door_open(void);
void CONFIRM_inner_door_close(void);
void CONFIRM_extdoor_open(void);
void CONFIRM_extdoor_close(void);
void CONFIRM_baby_in(void);
void CONFIRM_baby_none(void);

void EXIT_inner_door_open(void);
void EXIT_inner_door_close(void);
void EXIT_extdoor_open(void);
void EXIT_extdoor_close(void);
void EXIT_baby_in(void);
void EXIT_baby_none(void);


#endif
//--------



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

#endif /* STATEMACHINE_H_ */
