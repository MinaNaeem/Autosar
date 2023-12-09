#ifndef DIO_H
#define DIO_H


#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "types.h"
#include "Dio_Cfg.h"

#define NULL_PTR          ((void *)0)


#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */


typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;



typedef struct
{
	Dio_PortType Port_Num;
	Dio_ChannelType Ch_Num;

}Dio_ConfigChannel;

typedef struct
{
	Dio_ConfigChannel Channels[NUM_OF_CONFIGURED_CHANNELS];
} Dio_ConfigType;



Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);


extern const Dio_ConfigChannel *Dio_PortChannels;


#endif /* DIO_H */
