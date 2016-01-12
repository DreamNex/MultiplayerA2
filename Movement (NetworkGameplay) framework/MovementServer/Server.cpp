#include "ServerApp.h"
#include <Windows.h>

int main()
{
	ServerApp app;
	while (true)
	{
		Sleep(10);
		app.Loop();
	}
	return 0;
}