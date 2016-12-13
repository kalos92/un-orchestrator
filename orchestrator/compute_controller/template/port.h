#include <string>
#include <cstring>
using namespace std;

class Port{
private:
	string portsRange;
	string technology;

public:
	Port();
	void setPortsRange(string portsRange);
	void setTechnology(string technology);
	string getPortsRange();
	string getTechnology();
	void  splitPortsRangeInInt(int& begin, int& end);  //it splits portsRange in integers,so i can add in a map each port with the appropriate technology through a loop

};
