#include <platform.h>

uint8_t SI_Rx_Frame[QUEUE_STATIC_BUFFER_SIZE];

void SI_Rx_Callback(uint8_t* rx_bytes, uint8_t size)
{

}

void SI_Rx_Handler(void)
{
	uint8_t byte;

	/*< in frame_state lower nibble is used to store the frame reception state, upper nibble is reserved for frame reception timeout  */
	static uint8_t frame_state = 0;
	static uint8_t frame_index = 0;

	while (Comm_Rx_Byte(&byte))
	{
		if (((SI_STX != byte) && (SI_ETX != byte) && (SI_DTX != byte)) || (0X01 & frame_state))
		{
			SI_Rx_Frame[frame_index] = byte;
			frame_index++;

			if (0X01 & frame_state)
			{
				frame_state &= 0XF0;
			}
		}
		else if (SI_DTX == byte)
		{
			frame_state |= 0X01;
		}
		else if (SI_ETX == byte)
		{
			SI_Rx_Callback(&SI_Rx_Frame[0], frame_index);

			frame_index = 0;
		}
		else
		{
			/*< do nothing */
		}
	}
}
