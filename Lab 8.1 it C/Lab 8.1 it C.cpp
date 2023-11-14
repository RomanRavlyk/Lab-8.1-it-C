#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int FindChar(char* str)
{
	if (strlen(str) < 3)
		return 0;
	int k = 0;
	for (int i = 1; i < strlen(str); i++) {
		if (str[i - 1] == ',')
			k++;
		if (k == 3) {
			return i - 1;
		}
	}
	return -1;

}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && str[i + 1] != 0)
	{
		if (str[i] == ',')
		{
			strcat(t, "**");
			t += 2;
			i += 1;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Char until third coma: " << FindChar(str) << endl;
	char* dest = new char[151];
	cout << "Modified string (param) : " << str << endl;
	dest = Change(str);
	cout << "Modified string (result): " << dest << endl;
	return 0;
}