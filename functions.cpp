#include"functions.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
bool ModifyContent(const char* fileName, int offset, const char* buf)
{
	int fd =-1;
	fd=open(fileName, O_WRONLY);
	if (fd != -1) {
		int res=lseek(fd, offset, SEEK_SET);
		if (res != -1) {
			int nr = write(fd, buf, sizeof(buf));
			close(fd);
			if (nr != -1) return true;
			else return false;
		}
		else {
			close(fd);
			return false;
		}
	}
	else return false;
}

bool ChangeDirectory()
{

	return false;
}
