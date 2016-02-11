/****************************************************************
 * File             : AllParameter.h
 * State            : OK
 * Description      : All parameters processed operating
 * Author           : TOLA
 *
 * Created on 25 July 2014, 17:25
 *
 ***************************************************************/

#ifndef ALLPARAMETERS_H
#define	ALLPARAMETERS_H

#define OK               1
#define ERROR            0

#define VREF             3.3             // Value for convert A\D; depending on the  value of External VREF+ or Vdd which choose as Vr+

#define VDIV             3.3             // Value divided of voltage
#define MAX_WATER_LEVEL  35              // Distance from the bottom to the sensor (unity in CM)

#define FOSC             8.0             // Frequency of the secondary ocsilator (unity in MHz)
#define BAUDRATE         115200.0        // UART baud rate value
#define FPWM             1000.0          // PWM Frequency (unity in Hz)
#define DUTYCYCLEINI     0.5             // Initial duty cycle (50% duty cycle)

#define IDENT_CAP1       "CV1AM"         // Sensor1 in sluice1
#define IDENT_CAP2       "CV1AV"         // Sensor1 in sluice1

#define SLIP_END             0xC0
#define END_USER_PAYLOAD     0x0A
#define SEPARATOR            0x3B

#define ENABLE_BIT 0x8000
#define IRDA_ENABLE_BIT 0x1000
#define WAKE_ENABLE 0x0080
#define LOOPBACK_MODE 0x0000
#define ENABLE_AUTO_MODE 0x8000
#define UART2_BRGH 0x0004
#define PARITY_DATA_SELECT 0x0000
#define STOP_BIT_SELECT 0x0000




/**************************** Unity *******************************/
#define UNITY_CM         "cm"            // Unity in centimeter
#define UNITY_MM         "mm"            // Unity in millimeter
#define UNITY_VOLT       "volt"          // Unity in Voltage

/************************ Destination Address *********************/
#define DEST_GROUP_ADDR         0x10            // Send Message to destination address 0x10/0x1234
#define DEST_DEVICE_ADDR        0x1234

//#define DEST_GROUP_ADDR       0xFF            // Send Message to all receiver address
//#define DEST_DEVICE_ADDR      0xFFFF

/************************ Source Address *************************/
// Normally Source Address Fields are automatically added by the firmware itselt(WiMOD Studio)

#define SOURCE_GROUP_ADDR       0x20
#define SOURCE_DEVICE_ADDR      0x2345

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* ALLVARIABLES_H */

