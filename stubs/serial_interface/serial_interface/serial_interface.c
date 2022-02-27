#include <stdio.h>
#include <stdint.h>
#include "serial_interface_msg_def.h"
#include "serial_interface.h"

/**********************************************************************************************************************************
 *                                      Serial interface Rx message callback function declaration
 *********************************************************************************************************************************/

#undef SI_RX_MESSAGE
#define SI_RX_MESSAGE(MsgId, MsgSize, MsgDescription) static void MsgId##_SI_RX_Callback(uint8_t*, uint8_t);

SI_RX_MESSAGE_DECLARATION

/**********************************************************************************************************************************
 *                                      Serial interface Tx message callback function declaration
 *********************************************************************************************************************************/

#undef SI_TX_MESSAGE
#define SI_TX_MESSAGE(MsgId, MsgSize, MsgDescription) static void MsgId##_SI_TX_Callback(uint8_t*, uint8_t);

	SI_TX_MESSAGE_DECLARATION

/**********************************************************************************************************************************
 *                                            Serial interface Rx/Tx message definition
 *********************************************************************************************************************************/

#undef SI_RX_MESSAGE
#define SI_RX_MESSAGE(MsgId, MsgSize, MsgDescription) { SI_RX_##MsgId, MsgSize, MsgId##_SI_RX_Callback },


#undef SI_TX_MESSAGE
#define SI_TX_MESSAGE(MsgId, MsgSize, MsgDescription) { SI_TX_##MsgId, MsgSize, MsgId##_SI_TX_Callback },

SI_Message SI_Msg[] = {
		SI_RX_MESSAGE_DECLARATION \
		SI_TX_MESSAGE_DECLARATION
};

/**
 * @brief : this function calculates 8bit checksum, last byte of the passed array is considered as the checksum to be validated against
 **/
extern uint8_t SI_Rx_Validate_Checksum(uint8_t* rx_bytes, uint8_t size);

/**
 * @brief : this function calls the callback of the passed message id
 **/
extern uint8_t SI_Rx_Callback(uint8_t* rx_bytes, uint8_t size);

/**
 * @brief : this function returns the index of the passed message id
 **/
extern uint8_t SI_Get_MessageIndex(uint8_t MsgId, uint8_t* index);


/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Get_MessageIndex(uint8_t MsgId, uint8_t* index)
{
	uint8_t i;
	uint8_t retval = 0;

	for (i = 0; i < SI_RxMsgId_End; i++)
	{
		if (MsgId == SI_Msg[i].SI_MsgId)
		{
			*index = i;

			retval = 1;
		}
	}

	return retval;
}

/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Rx_Callback(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t retval = 1;
	uint8_t index = 0;

	if (SI_Get_MessageIndex(rx_bytes[0], &index))
	{
		/*< send only data byte to the callback function */
		size--;
		SI_Msg[index].SI_CallBack(&rx_bytes[1], size);
	}
	else
	{
		/*< invalid id */
		retval = 0;
	}

	return retval;
}

/**
 * note: refer serial_interface.h for info
 **/
void SI_Rx_Handler(void)
{
	uint8_t bytes[] = {
		0x02, 0xFE
	};

	uint8_t size = ((sizeof(bytes) / sizeof(bytes[0])));

	uint8_t index;

	if (SI_Rx_Validate_Checksum(&bytes[0], size))
	{
		/*< exclude the checksum byte */
		size--;

		if (!SI_Rx_Callback(&bytes[0], size))
		{
			/*< message id not found */
			if (SI_Get_MessageIndex(SI_TX_MsgInvalidId, &index))
			{
				SI_Msg[index].SI_CallBack((void*)0, 0);
			}
		}
	}
	else
	{
		/*< invalid checksum send nack */
		if (SI_Get_MessageIndex(SI_TX_MsgNack, &index))
		{
			SI_Msg[index].SI_CallBack((void*)0, 0);
		}
	}
}

/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Rx_Validate_Checksum(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t retval = 0;
	uint16_t sum = 0; // if all bytes are 0xff the maximum value would be 65025
	uint8_t i;

	for (i = 0; i < (size-1); i++)
	{
		sum += rx_bytes[i];
	}

	sum = ~sum;
	sum += 1;

	if ((sum & 0XFF) == rx_bytes[size - 1])
	{
		retval = 1;
	}

	return retval;
}

/**********************************************************************************************************************************
 *                                            Serial interface callback function definition
 *********************************************************************************************************************************/

static void MsgAck_SI_RX_Callback(uint8_t *rx_bytes,uint8_t size)
{
	printf("si rx ack callback");
}

static void MsgAlive_SI_RX_Callback(uint8_t *rx_bytes,uint8_t size)
{
	printf("si rx alive callback");
}

static void MsgNack_SI_RX_Callback(uint8_t *rx_bytes,uint8_t size)
{
	printf("si rx nack callback");
}

static void MsgAck_SI_TX_Callback(uint8_t* rx_bytes, uint8_t size)
{
	printf("si tx ack callback");
}

static void MsgNack_SI_TX_Callback(uint8_t* rx_bytes, uint8_t size)
{
	printf("si tx nack callback");
}

static void MsgInvalidId_SI_TX_Callback(uint8_t* rx_bytes, uint8_t size)
{
	printf("si tx invalid id");
}
