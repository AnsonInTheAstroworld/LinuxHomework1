#include "LinuxHomework1.h"

using namespace std;

int main()
{
	ModifyContent("/home/astro/test.txt", 0, "hello");
	/*while (1) {
		cout << "Target directory:";
		char* name = new char[100]; cin >> name;
		ChangeDirectory(name);
	}*/
	/*while (1) {
		cout << "Target directory:";
		char* name=new char[100]; cin >> name;
		CheckIsFileOrDir(name);
	}*/
	return 0;
}
