#include <iostream>
#include<Windows.h>
using namespace std;

int main() {
	HKEY hKey;
	PWCHAR str =(PWCHAR)"Service Started";
	LONG Reg = RegCreateKeyEx(
		HKEY_CURRENT_USER,
		L"Software\\Test\\Product\\NewOne1",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS | KEY_WOW64_64KEY,
		NULL,
		&hKey,
		NULL);
	if (Reg != ERROR_SUCCESS) {
		cout << "Registry creation failed & Error No - " << GetLastError() << endl;
	}
	else
	cout << "Registry creation Success" << endl;

	Reg = RegSetValueEx(
		hKey,
		L"Windows Service Created2",
		NULL,
		REG_SZ,
		(LPBYTE)str,
		((((DWORD)lstrlen(str) + 1)) * 2)
	);
	if (Reg != ERROR_SUCCESS) {
		cout << "Registry Value creation failed & Error No - " << GetLastError() << endl;
	}
	else
		cout << "Registry Value creation Success" << endl;
	
	RegCloseKey(hKey);
	return 0;
}
