#include "Dio.h"


const Dio_ConfigType Dio_Configuration = {
                                          DioConf_LED1_PORT_NUM,DioConf_LED1_CHANNEL_NUM,
                                          DioConf_SW1_PORT_NUM,DioConf_SW1_CHANNEL_NUM
				         };

const Dio_ConfigChannel *Dio_PortChannels = Dio_Configuration.Channels;
