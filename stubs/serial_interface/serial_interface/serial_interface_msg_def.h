#ifndef __SERIAL_INTERFACE_MSG_DEF_H__
#define __SERIAL_INTERFACE_MSG_DEF_H__

#include <stdint.h>

#define SI_RX_MESSAGE_DECLARATION \
		SI_RX_MESSAGE(MsgAlive, 1U , "alive message") \
		SI_RX_MESSAGE(MsgAck, 1U, "acknowledge message") \
		SI_RX_MESSAGE(MsgNack, 1U, "not acknowledge message") \

#define SI_TX_MESSAGE_DECLARATION \
		SI_TX_MESSAGE(MsgAck, 1U, "acknowledge message") \
		SI_TX_MESSAGE(MsgNack , 1U, "not acknowledge message") \
		SI_TX_MESSAGE(MsgInvalidId, 1U, "invalid id received") \

#undef SI_RX_MESSAGE
#define SI_RX_MESSAGE(MsgId, MsgSize, MsgDescription) SI_RX_##MsgId,

#undef SI_TX_MESSAGE
#define SI_TX_MESSAGE(MsgId, MsgSize, MsgDescription) SI_TX_##MsgId,

typedef enum SI_Message_Id_Tag
{
	SI_RxMsgId_Start = -1,
	SI_RX_MESSAGE_DECLARATION
	SI_RxMsgId_End,

	SI_TxMsgId_Start,
	SI_TX_MESSAGE_DECLARATION
	SI_TxMsgId_End
}SI_Message_Id;

#endif // __SERIAL_INTERFACE_MSG_DEF_H__
