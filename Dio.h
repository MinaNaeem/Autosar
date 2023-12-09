#ifndef DIO_H
#define DIO_H


#include "tm4c123gh6pm.h"
#include "Dio_Cfg.h"
#include "bitwise_operation.h"
#include "types.h"

#define NULL_PTR          ((void *)0)

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */



typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;


typedef struct
{
	Dio_PortType Port_Num;
	Dio_ChannelType Ch_Num;

}Dio_ConfigChannel;

typedef struct Dio_ConfigType
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;



Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);


extern const Dio_ConfigType Dio_Configuration;

#endif /* DIO_H */
