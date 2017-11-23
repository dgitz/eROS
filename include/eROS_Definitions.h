//DO NOT EDIT THIS FILE.  IT IS MAINTAINED THROUGH EROS.

#ifndef __EROS_DEFINITIONS_INCLUDED__   
#define __EROS_DEFINITIONS_INCLUDED__

//TAG: Start Message Definitions  ALL TEXT UNTIL TAG: End IS AUTO GENERATED
#define IMU_ID 0XAB41
#define ID_ID 0XAB40
#define TUNECONTROLGROUP_ID 0XAB39
#define ESTOP_ID 0XAB38
#define POWER_ID 0XAB37
#define CONFIGURE_ANA_PORT_ID 0XAB36
#define PPS_ID 0XAB35
#define FINDTARGET_ID 0XAB34
#define SET_DIO_PORT_DEFAULTVALUE_ID 0XAB32
#define HEARTBEAT_ID 0XAB31
#define ARM_STATUS_ID 0XAB30
#define ARMCONTROL_ID 0XAB26
#define FIRMWAREVERSION_ID 0XAB25
#define GET_ANA_PORT1_ID 0XAB20
#define GET_DIO_PORT1_ID 0XAB19
#define SET_DIO_PORT_ID 0XAB18
#define MODE_ID 0XAB17
#define CONFIGURE_DIO_PORT_ID 0XAB16
#define TESTMESSAGECOMMAND_ID 0XAB15
#define TESTMESSAGECOUNTER_ID 0XAB14
#define DEVICE_ID 0XAB13
#define DIAGNOSTIC_ID 0XAB12
#define RESOURCE_ID 0XAB11
#define REMOTECONTROL_ID 0XAB10
#define COMMAND_ID 0XAB02
#define USERMESSAGE_ID 0XAB01
//TAG: End Message Definitions

//Diagnostic Definitions
#define LEVEL1 1
#define LEVEL2 2
#define LEVEL3 3
#define LEVEL4 4

//Field 1: System
#define ROVER 1
#define GROUND_STATION 5
#define REMOTE_CONTROL 7

//Field 2: Subsystem
#define ENTIRE_SYSTEM 0
#define ROBOT_CONTROLLER 1

//Field 3: Component
#define ENTIRE_SUBSYSTEM 0
#define CONTROLLER_NODE 1
#define DIAGNOSTIC_NODE 2
#define NAVIGATION_NODE 3
#define MAPPING_NODE 7
#define EVOLUTION_NODE 8
#define TARGETING_NODE 9
#define TIMING_NODE 10
#define VISION_NODE 11
#define GPIO_NODE 12
#define COMMUNICATION_NODE 13
#define DYNAMICS_NODE 14
#define POWER_NODE 15
#define POSE_NODE 16

//Field 4: Diagnostic Type
#define NOERROR 0
#define ELECTRICAL 1
#define SOFTWARE 2
#define COMMUNICATIONS 3
#define SENSORS 4
#define ACTUATORS 5
#define DATA_STORAGE 6
#define REMOTE_CONTROL 7
#define TARGET_ACQUISITION 8
#define POWER 9
#define POSE 10
#define TIMING 11
#define GENERAL_ERROR 255

//Field 5: Level
#define DEBUG 0  //This Level is solely for development/debugging only.
#define INFO 1 //This Level is purely for informational use only.
#define NOTICE 2  //This Level is a higher form of information and does not imply that anything is wrong.
#define WARN 3  //This Level implies that a program is not running as expected, but may continue to operate in a diminished capacity.
#define ERROR 4 //This Level implies that a program will not initialize or some other kind of crash.
#define FATAL 5  //This Level implies that a program has failed so bad it can cause injury to itself or others.

//Field 6: Diagnostic_Message
//#define NOERROR 0  Already defined above, just leaving here for completeness.
#define INITIALIZING 1
#define INITIALIZING_ERROR 2
#define DROPPING_PACKETS 4
#define MISSING_HEARTBEATS 5
#define DEVICE_NOT_AVAILABLE 6
#define ROVER_ARMED 7
#define ROVER_DISARMED 8
#define TEMPERATURE_HIGH 9
#define TEMPERATURE_LOW 10
#define DIAGNOSTIC_PASSED 11
#define DIAGNOSTIC_FAILED 12
#define RESOURCE_LEAK 13
#define HIGH_RESOURCE_USAGE 14
#define UNKNOWN_STATE 15

//Armed States
#define ARMEDSTATUS_UNDEFINED 0
#define ARMEDSTATUS_ARMED 1
#define ARMEDSTATUS_DISARMED_CANNOTARM 2
#define ARMEDSTATUS_DISARMED 3
#define ARMEDSTATUS_DISARMING 4
#define ARMEDSTATUS_ARMING 5

//Board Types
#define BOARDTYPE_UNDEFINED 0
#define BOARDTYPE_ARDUINOUNO 1
#define BOARDTYPE_ARDUINOMEGA 2

//Shield Types
#define SHIELDTYPE_UNDEFINED 0
#define SHIELDTYPE_SERVOSHIELD 1
#define SHIELDTYPE_LCDSHIELD 2
#define SHIELDTYPE_RELAYSHIELD 3
#define SHIELDTYPE_TERMINALSHIELD 4
#define SHIELDTYPE_NONE 255

//Hat Types
#define HATTYPE_UNDEFINED 0
#define HATTYPE_TERMINALSHIELD 1
#define HATTYPE_SERVOHAT 2

//Rover Commands
#define ROVERCOMMAND_UNDEFINED 0
#define ROVERCOMMAND_BOOT 1
#define ROVERCOMMAND_NONE 2
#define ROVERCOMMAND_RUNDIAGNOSTIC 3
#define ROVERCOMMAND_SEARCHFOR_RECHARGE_FACILITY 4
#define ROVERCOMMAND_STOPSEARCHFOR_RECHARGE_FACILITY 5
#define ROVERCOMMAND_ACQUIRE_TARGET 6
#define ROVERCOMMAND_ARM 7
#define ROVERCOMMAND_DISARM 8
#define ROVERCOMMAND_CONFIGURE 9
#define ROVERCOMMAND_RUN 10

//Node/Rover States
#define NODESTATE_UNDEFINED 0
#define NODESTATE_BOOTING 1
#define NODESTATE_RUNNING 2
#define NODESTATE_SEARCHING_FOR_RECHARGE_FACILITY 3
#define NODESTATE_ACQUIRING_TARGET 4

//Power States
#define POWERSTATE_UNDEFINED 0
#define POWERSTATE_NORMAL 1
#define POWERSTATE_STANDBY 2
#define POWERSTATE_CHANGINGACTIVEBATTERY 3
#define POWERSTATE_REQUIRERECHARGE 4
#define POWERSTATE_EMERGENCY 5

//EStop States
#define ESTOP_UNDEFINED 0
#define ESTOP_DISACTIVATED 1
#define ESTOP_ACTIVATED 2

//Signal States
#define SIGNALSTATE_UNDEFINED 0
#define SIGNALSTATE_INVALID 1
#define SIGNALSTATE_INITIALIZING 2
#define SIGNALSTATE_UPDATED 3
#define SIGNALSTATE_HOLD 4
#define SIGNALSTATE_CALIBRATING 5

#endif
