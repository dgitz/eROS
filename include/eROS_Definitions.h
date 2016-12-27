//DO NOT EDIT THIS FILE.  IT IS MAINTAINED THROUGH EROS.

#ifndef __EROS_DEFINITIONS_INCLUDED__   
#define __EROS_DEFINITIONS_INCLUDED__

//TAG: Start Message Definitions  ALL TEXT UNTIL TAG: End IS AUTO GENERATED
#define CONFIGURE_SHIELD_ID 0XAB33
#define SET_DIO_PORT_DEFAULTVALUE_ID 0XAB32
#define HEARTBEAT_ID 0XAB31
#define ARM_STATUS_ID 0XAB30
#define TUNE_CONTROLGROUP_ID 0XAB29
#define SETUP_CONTROLGROUP_ID 0XAB28
#define ARM_COMMAND_ID 0XAB27
#define ARMCONTROL_ID 0XAB26
#define FIRMWAREVERSION_ID 0XAB25
#define GET_ANA_PORT_ID 0XAB20
#define GET_DIO_PORT_ID 0XAB19
#define SET_DIO_PORT_ID 0XAB18
#define MODE_ID 0XAB17
#define CONFIGURE_DIO_PORT_ID 0XAB16
#define TESTMESSAGECOMMAND_ID 0XAB15
#define TESTMESSAGECOUNTER_ID 0XAB14
#define DEVICE_ID 0XAB13
#define DIAGNOSTIC_ID 0XAB12
#define RESOURCE_ID 0XAB11
#define REMOTECONTROL_ID 0XAB10
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

//Field 4: Diagnostic Type
#define NOERROR 0
#define ELECTRICAL 1
#define SOFTWARE 2
#define COMMUNICATIONS 3
#define SENSORS 4
#define ACTUATORS 5
#define DATA_STORAGE 6
#define REMOTE_CONTROL 7
#define GENERAL_ERROR 9

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

//Armed States
#define ARMEDSTATUS_UNDEFINED 0
#define ARMEDSTATUS_ARMED 1
#define ARMEDSTATUS_DISARMED_CANNOTARM 2
#define ARMEDSTATUS_DISARMED 3
#define ARMEDSTATUS_DISARMING 4
#define ARMEDSTATUS_ARMING 5

//Armed Commands
#define ARMEDCOMMAND_UNDEFINED 0
#define ARMEDCOMMAND_ARM 1
#define ARMEDCOMMAND_DISARM 2

//Board Types
#define BOARDTYPE_UNDEFINED 0
#define BOARDTYPE_ARDUINOUNO 1
#define BOARDTYPE_ARDUINOMEGA 2

#define SHIELDTYPE_UNDEFINED 0
#define SHIELDTYPE_SERVOSHIELD 1
#define SHIELDTYPE_LCDSHIELD 2
#endif
