/**
  ******************************************************************************
  * @file    crc8.c
  * @author
  * @version V1.0.0
  * @date
  * @brief
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "crc8.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function ----------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**
  * @brief  crc8_byte
  * @param  byte and prev CRC
  * @retval CRC
  */
static uint8_t crc8_byte(uint8_t byte, uint8_t crc) {
   uint8_t i;
   /* */
   for ( i = 0; i < 8 ; i++) {
      if (crc & 0x80) {
         crc <<= 1;
         if (byte & 0x80) crc |= 0x01;
         else crc &= 0xFE;
         crc ^= 0x85;
      }
      else {
        crc <<= 1;
        if (byte & 0x80) crc |= 0x01;
        else crc &= 0xFE;
      }
      byte <<= 1;
   }
   return crc;
}

/**
  * @brief  crc8_buffer
  * @param  pointer to buff data and num bytes to calcul CRC
  * @retval CRC value for buff
  */
uint8_t crc8_buffer(uint8_t *pBuff, uint16_t len) {
   uint16_t i;
   uint8_t *pbuff = pBuff;
   uint8_t crcBuff = 0x00;
   /* */
   for(i = 0; i < len; i++) {
       crcBuff = crc8_byte(*pbuff, crcBuff);
       pbuff++;
   }
   /* */
   return (crcBuff);
}







/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
