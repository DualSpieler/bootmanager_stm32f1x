#ifndef __FLASH_HANDLER_H__
#define __FLASH_HANDLER_H__
#include <stdint.h>

typedef struct Flash_Reprogramming_Tag
{
	uint8_t  FlgRprg_Data[1024];        /*< image is flashed parition by partition in flash memory */
	uint32_t FlsRprg_Image_Size;        /*< image size in bytes */
	uint16_t FlsRprg_Frame_Count;       /*< number of frames to be received during reflashing */
	uint8_t  FlgRprg_DataIndex;         /*< stores the current index of the FlgRprg_Data array */
}Flash_Reprogramming;

#endif //__FLASH_HANDLER_H__
