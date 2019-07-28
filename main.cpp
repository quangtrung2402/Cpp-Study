#include <QCoreApplication>
#include "header.h"

int tmp = 0;

int main(){
    while (1){
        int a = qrand();
        if((a > 40) && (a < 48)){

        } else {
            continue;
        }

        SENSOR_STATUS statusSensor = checkSensor(a);

        if(statusSensor != SENSOR_NORMAL){
            qDebug("statusSensor: #%d", statusSensor);
            break;
        }
        if(tmp++ > 1000){
            qDebug("statusSensor: #%d", statusSensor);
            break;
        }
    }
    return 0;
}
