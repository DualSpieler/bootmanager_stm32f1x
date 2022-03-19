/*
 * code_flash.c
 *
 *  Created on: 18-Mar-2022
 *      Author: cibic
 */

#include <platform.h>

Code_Flash_States_T Code_Flash_State;

Code_Flash_Info_T Code_Flash_Info;

static void Code_Flash_Erase_Parition(uint8_t parition, uint8_t partition_count);

void Code_Flash_Reflash_Req(void)
{
	/*< erase the application flash region */
	Code_Flash_Erase_Parition(CODE_FLASH_APP_PARTITION_START, CODE_FLASH_APP_PARITION_COUNT);
}

static void Code_Flash_Erase_Parition(uint8_t parition, uint8_t partition_count)
{
	uint8_t i;

	for (i = 0; i < partition_count; i++)
	{
		Flash_Erase_Parition(parition+i);
	}
}

uint8_t Code_Flash_Program(uint8_t* data, uint8_t size)
{
#if 0
	/**
	 * NOTE: the start address for the flash write should always be an even address
	 */

	Flash_Write_Stream(Code_Flash_Info.Current_Address, data, size);

	Code_Flash_Info.Current_Address += size;
#endif
}

uint8_t Code_Flash_Rx_Record(uint8_t *byte, uint8_t size)
{
	uint8_t retval = True;

	uint32_t address = 0;

	switch (byte[3])
	{
		case CODE_FLASH_REC_DATA:
		{
			address = (((uint32_t)byte[1] << 8) | byte[2]);
			Flash_Write_Stream((address | Code_Flash_Info.Current_Address), &byte[4], size-4);
			break;
		}
		case CODE_FLASH_REC_EX_LINEAR:
		{
			Code_Flash_Info.Current_Address = 0;
			Code_Flash_Info.Current_Address = Code_Flash_Info.Current_Address | (((uint16_t)byte[5] | ((uint16_t)byte[4] << 8)) << 16);
			break;
		}
		case CODE_FLASH_REC_END:
		{
			break;
		}
		default:
		{
			break;
		}
	}

	return retval;
}




