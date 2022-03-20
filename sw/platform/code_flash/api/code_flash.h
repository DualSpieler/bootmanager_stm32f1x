#ifndef __CODE_FLASH_H__
#define __CODE_FLASH_H__


#define CODE_FLASH_BM_PARTITION_START     (0X0U)
#define CODE_FLASH_BM_PARITION_COUNT      (0X7U)

#define CODE_FLASH_FBL_PARTITION_START    (0X7U)
#define CODE_FLASH_FBL_PARITION_COUNT     (0X10U)

#define CODE_FLASH_APP_PARTITION_START    (0X17U)
#define CODE_FLASH_APP_PARITION_COUNT     (0X68U)

#define CODE_FLASH_APP_START_ADD          (0X08005C00U)
#define CODE_FLASH_APP_END_ADD            (0X0801FBFFU)

#define CODE_FLASH_REC_DATA              ((uint8_t)0x00)
#define CODE_FLASH_REC_EX_LINEAR         ((uint8_t)0x04)
#define CODE_FLASH_REC_EX_SEG            ((uint8_t)0x02)
#define CODE_FLASH_REC_START_LINEAR      ((uint8_t)0x05)
#define CODE_FLASH_REC_END               ((uint8_t)0x01)

<<<<<<< HEAD
typedef enum Code_Flash_States_Tag
{
	CODE_FLASH_IDLE,
	CODE_FLASH_ERASE,
	CODE_FLASH_REPROGRAMMING,
}Code_Flash_States_T;


=======
>>>>>>> 6f03ce798ea094da02810eb13d6e62869730cc36
typedef struct Code_Flash_Info_Tag
{
	uint32_t Current_Address;
	uint16_t Packet_Count;
}Code_Flash_Info_T;

extern uint8_t Code_Flash_Program(uint8_t* data, uint8_t size);

extern void Code_Flash_Reflash_Req(void);

extern uint8_t Code_Flash_Rx_Record(uint8_t *byte, uint8_t size);

#endif // __CODE_FLASH_H__
