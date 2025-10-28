/**
  ******************************************************************************
  * @file           : common_defines.h
  * @brief          : This file contains the common defines for the app.                  
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_DEFINES_H__
#define __COMMON_DEFINES_H__

#define FLASHSIZE_BASE                                ((uint32_t)0x1FFFF7E0)

//#define DEBUG

#define FIRMWARE_VERSION					0x1713			// v1.7.1b2
#define USED_PINS_NUM							30					// constant for BluePill and BlackPill boards
#define MAX_AXIS_NUM							8						// max 8
#define MAX_BUTTONS_NUM						128					// power of 2, max 128
#define MAX_POVS_NUM							4						// max 4
#define MAX_ENCODERS_NUM					16					// max 64
#define MAX_SHIFT_REG_NUM					4						// max 4
#define MAX_LEDS_NUM							24

#define AXIS_MIN_VALUE						(-32767)
#define AXIS_MAX_VALUE						(32767)
#define AXIS_CENTER_VALUE					(AXIS_MIN_VALUE + (AXIS_MAX_VALUE-AXIS_MIN_VALUE)/2)
#define AXIS_FULLSCALE						(AXIS_MAX_VALUE - AXIS_MIN_VALUE + 1)

#define FREEJOY_FLASH_SIZE_KB				(*(volatile uint16_t *)FLASHSIZE_BASE)
#define FREEJOY_FLASH_PAGE_SIZE			((FREEJOY_FLASH_SIZE_KB > 128U) ? 2048U : 1024U)
#define CONFIG_ADDR						(FLASH_BASE + (FREEJOY_FLASH_SIZE_KB * 1024U) - FREEJOY_FLASH_PAGE_SIZE)


enum
{
	REPORT_ID_JOY = 1,
	REPORT_ID_PARAM,
	REPORT_ID_CONFIG_IN,
	REPORT_ID_CONFIG_OUT,
	REPORT_ID_FIRMWARE,
};


#endif 	/* __COMMON_DEFINES_H__ */
