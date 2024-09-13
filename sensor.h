#ifndef "sensor_h"
#define "sensor_h"

using namespace std;

class sensor
{  

Public:
		sensor();
		~sensor();
	void lireTemp(get_temp);
	void affTemp(displaytemp);
Private:


	sensor::sensor(int adrTemp);
	float Temp;


}

endif
