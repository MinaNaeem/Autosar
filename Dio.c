#include "Dio.h"

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
		switch(Dio_PortChannels[ChannelId].Port_Num)
		{
            case 0:    Port_Ptr = &GPIO_PORTA_DATA_R;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_R;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_R;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_R;
		               break;
            case 4:    Port_Ptr = &GPIO_PORTE_DATA_R;
		               break;
            case 5:    Port_Ptr = &GPIO_PORTF_DATA_R;
		               break;
		}
		if(Level == STD_HIGH)
		{
		    SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}

}


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;


		switch(Dio_PortChannels[ChannelId].Port_Num)
		{
            case 0:    Port_Ptr = &GPIO_PORTA_DATA_R;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_R;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_R;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_R;
		               break;
		    case 4:    Port_Ptr = &GPIO_PORTE_DATA_R;
		               break;
		    case 5:    Port_Ptr = &GPIO_PORTF_DATA_R;
		               break;
		}
		if(BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num))
		{
			output = STD_HIGH;
		}
		else
		{
			output = STD_LOW;
		}

        return output;
}



