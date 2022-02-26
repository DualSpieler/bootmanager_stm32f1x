#ifndef __SERIAL_INTERFACE_H__
#define __SERIAL_INTERFACE_H__

#define SI_STX		0X01U
#define SI_ETX		0X02U
#define SI_DTX		0X03U


extern void SI_Rx_Handler(void);

#endif //__SERIAL_INTERFACE_H__
