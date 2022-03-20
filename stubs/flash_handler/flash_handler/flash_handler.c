#include <stdio.h>
#include "flash_handler.h"

Flash_Reprogramming Flash_Reprogramming_Status;


void Flash_Handler_Init(void)
{
	uint16_t i;

	Flash_Reprogramming_Status.FlsRprg_Frame_Count = 0;
	Flash_Reprogramming_Status.FlsRprg_Image_Size = 0;
	Flash_Reprogramming_Status.FlgRprg_DataIndex = 0;

	for (i = 0; i < 1024u; i++)
	{
		Flash_Reprogramming_Status.FlgRprg_Data[i] = 0;
	}
}

uint8_t Flash_Handler_Accumlate_Data(uint8_t* data, uint8_t size)
{
	uint8_t retval = 0;

	if (!(1024u > (Flash_Reprogramming_Status.FlgRprg_DataIndex + size)))
	{
		uint8_t i = 0;

		for (i = 0; i < size; i++)
		{
			Flash_Reprogramming_Status.FlgRprg_Data[Flash_Reprogramming_Status.FlgRprg_DataIndex + i] =
				data[i];
		}

		/*< update flash reprogramming current index */
		Flash_Reprogramming_Status.FlgRprg_DataIndex += size;
	}
	else
	{
		/*< flash reprogramming data array overflow occured */
	}

	return retval;
}

uint8_t Flash_Handler_Execute(void)
{

}


