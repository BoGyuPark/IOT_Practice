#include <windows.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	OPENFILENAME file;
	BOOL bret;
	char FileName[1000] = "";

	memset(&file, 0, sizeof(file));
	file.lStructSize = sizeof(file);
	file.lpstrFile = FileName;
	file.nMaxFile = 1000;
	file.lpstrFilter = "Text File(*.txt)\0*.txt;*.text\0C Files\0*.c;*.cpp\0";
	bret = GetOpenFileName(&file);
	if (bret == FALSE) {
		printf("No File Selected");
		return 1;
	}

	printf("File Name: %s\n", FileName);

	return 0;
}