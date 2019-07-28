#include <QCoreApplication>
#include "header.h"

SENSOR_STATUS checkSensor(int temp){
    static qint8 sensorValue[100];
    static qint8 position = 0;
    static SENSOR_STATUS ret = SENSOR_NORMAL;
    static bool isEnough = false;
    qint8 minValue = 0;
    qint8 maxValue = 0;
    qint8 countMin = 0;
    qint8 countMax = 0;

    if(position < 100){
        sensorValue[position++] = temp;
    } else {
        position = 0;
        isEnough = true;
        sensorValue[position++] = temp;
    }

    minValue = sensorValue[0];
    maxValue = sensorValue[0];
    if(isEnough){
        qDebug("*------------------*");
        qDebug("check");
        for(int i = 0; i < 100; i++){
            if(sensorValue[i] < MIN_TEMP){
                countMin++;
            } else if(sensorValue[i] > MAX_TEMP){
                countMax++;
            }

            if(sensorValue[i] < minValue){
                minValue = sensorValue[i];
            } else if(sensorValue[i] > maxValue){
                maxValue = sensorValue[i];
            }
        }

        qDebug("minValue: %d", minValue);
        qDebug("maxValue: %d", maxValue);
        qDebug("countMin: %d", countMin);
        qDebug("countMax: %d", countMax);


        if (countMax > MAX_OUT_OF_BOUDARY){
            ret = SENSOR_BREAK;
        }
        if (countMin > MAX_OUT_OF_BOUDARY){
            ret = SENSOR_SHORT_CIRCUIT;
        }
        if((maxValue - minValue) > DIFF_MIN_MAX){
            ret = SENSOR_FLICKER;
        }
    }

    /*----------------------------*/
    /*For debug, remove when done*/
    if(ret != SENSOR_NORMAL){
        qDebug("Value Array");
        for(int i = 0; i < 100; i++){
            qDebug("position: %d value: %d", i, sensorValue[i]);
        }
    }
    /*----------------------------*/
    return ret;
}
