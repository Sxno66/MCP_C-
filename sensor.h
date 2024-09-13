#ifndef "sensor_h"
#define "sensor_h"

using namespace std;

class sensor
{  

Public:
		sensor();
		sensor(int adrTemp);
		~sensor();
	void lireTemp();
	void affTemp();
Private:

	float Temp;


}

endif
