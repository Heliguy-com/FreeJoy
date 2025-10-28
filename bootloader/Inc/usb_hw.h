/**
  ******************************************************************************
  * @file    usb_hw.h
  * @author  MCD Application Team
  * @version V4.1.0
  * @date    26-May-2017
  * @brief   Hardware Configuration & Setup
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HW_H
#define __USB_HW_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "usb_type.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported variables ------------------------------------------------------------*/

extern volatile bool flash_started;
extern volatile bool flash_finished;
#define FLASHSIZE_BASE                                ((uint32_t)0x1FFFF7E0)


/* Exported define -----------------------------------------------------------*/

static inline uint32_t BootloaderFlashSizeKilobytes(void)
{
    return *(volatile uint16_t*)FLASHSIZE_BASE;
}

static inline uint32_t BootloaderFlashPageSize(void)
{
    return (BootloaderFlashSizeKilobytes() > 128U) ? 2048U : 1024U;
}

static inline uint32_t BootloaderMaxPageCount(void)
{
    return (BootloaderFlashSizeKilobytes() * 1024U) / BootloaderFlashPageSize();
}

static inline uint32_t BootloaderFirmwareStartPage(void)
{
    return (BootloaderFlashPageSize() == 2048U) ? 4U : 8U;
}

static inline uint32_t BootloaderFirmwareCopyAddress(void)
{
    return FLASH_BASE + BootloaderFlashPageSize() * BootloaderFirmwareStartPage();
}

#define FLASH_PAGE_SIZE				BootloaderFlashPageSize()
#define MAX_PAGE					BootloaderMaxPageCount()
#define FIRMWARE_START_PAGE				BootloaderFirmwareStartPage()
#define FIRMWARE_COPY_ADDR				BootloaderFirmwareCopyAddress()

/* Exported functions ------------------------------------------------------- */



void Get_SerialNum(void);
void USB_HW_Init(void);
void USB_Shutdown(void);

#endif  /*__USB_HW_H*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
