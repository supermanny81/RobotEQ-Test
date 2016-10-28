// This sketch tests communication between the robotEQ controller and uC by querying the voltage and amperage avaialble.  
// The RobotEQ controllers TX, RX must be connect to the Mega's Serial1 RX, TX (respectively)
//
// https://www.roboteq.com/index.php/component/virtuemart/324/fbl2360-detail?Itemid=971
// @see https://www.roboteq.com/index.php/docman/motor-controllers-documents-and-files/documentation/user-manual/272-roboteq-controllers-user-manual-v17/file
//    page 144 for connection details
//    page 209 for command reference
// 

#include "RobotEQ.h"
#include "Logging.h"

#define LOGLEVEL LOG_LEVEL_DEBUG
#define CHANNEL_1 1
#define CHANNEL_2 2

RobotEQ controller(&Serial1);

void setup() {
  Log.Init(LOGLEVEL, 115200L);
  Log.Info("Initalized RobtoEQ test..."CR);
}

void loop() {
    int voltage;
    int amps;

    if (controller.isConnected()) {
        Log.Info("Voltage=%i (v*10), Amperage=%i (amps * 10)"CR, controller.queryBatteryVoltage(), controller.queryBatteryAmps());
        
        // Uncomment these lines and change the  
        //controller.commandMotorPower(CHANNEL_1, 1000);
        //controller.commandMotorPower(CHANNEL_2, 1000);
    }
}
