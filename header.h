#ifndef HEADER
#define HEADER

#define MIN_TEMP            20
#define MAX_TEMP            100
#define DIFF_MIN_MAX        5
#define MAX_OUT_OF_BOUDARY  20
typedef enum {
    SENSOR_NORMAL = 0,		//Sensor is normal
    SENSOR_BREAK,			//Sensor is break or open circuit
    SENSOR_SHORT_CIRCUIT,	//Sensor is short circuit
    SENSOR_FLICKER,			//Sensor is flicker
} SENSOR_STATUS;

SENSOR_STATUS checkSensor(int temp);

#endif // HEADER
