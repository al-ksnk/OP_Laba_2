#include "Functions.h"

string* file_search(int* Num) {
	_finddata_t data;
	intptr_t hendle = _findfirst("C:\\OP_laba_2\\Laba2\\*.csv", &data);
	int N = 0;
	do {
		N++;
	} while (_findnext(hendle, &data) == 0);
	
	string* str = new string[N];
	*Num = N;

	hendle = _findfirst("C:\\OP_laba_2\\Laba2\\*.csv", &data);
	int i = 0;
	do {
		str[i] = (string)data.name;
		i++;
	} while (_findnext(hendle, &data) == 0);

	_findclose(hendle);
	
	return str;
}

void delete_mass(string* str) {
	delete [] str;
}