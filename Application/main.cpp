#include "Moteur.h"
#include "UI.h"

int main()
{
	Moteur m;
	UI u(&m);
	
	u.Start();
	
	return 0;
}
