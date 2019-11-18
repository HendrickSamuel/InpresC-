#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "class.h"

using namespace std;

int main() {

	myclass m;
	
	cout << m.getx() << endl;
	m.setx(10);
	cout << m.getx() << endl;

	exit(0);

}
