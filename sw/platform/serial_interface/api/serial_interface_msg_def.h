#ifndef __SERIAL_INTERFACE_MSG_DEF_H__
#define __SERIAL_INTERFACE_MSG_DEF_H__

#include <stdint.h>

/**
 * Serial interface message declaration
 **/
#define SI_MESSAGE_DECLARATION \
		SI_MESSAGE(MsgAlive, 1U , "alive message") \
		SI_MESSAGE(MsgAck, 1U, "acknowledge message") \
		SI_MESSAGE(MsgNack, 1U, "not acknowledge message") \
		SI_MESSAGE(MsgInvalidId, 1U, "invalid id received") \
		SI_MESSAGE(MsgReflashInfo, 2U, "reflash information (no of records)") \
		SI_MESSAGE(MsgReprogramming, 2U, "reflash information (no of records)") \
		SI_MESSAGE(MsgJumpToApp, 2U, "jump to application") \

 /**********************************************************************************************************************************
  *                                                   Type definitions
  *********************************************************************************************************************************/

#undef SI_MESSAGE
#define SI_MESSAGE(MsgId, MsgSize, MsgDescription) MsgId,

typedef enum SI_Message_Id_Tag
{
	SI_RxMsgId_Start = -1,
	SI_MESSAGE_DECLARATION
	SI_TxMsgId_End,
}SI_Message_Id;

#endif // __SERIAL_INTERFACE_MSG_DEF_H__
