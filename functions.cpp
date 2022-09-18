#include"functions.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<iostream>
#include<string.h>
using namespace std;

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

bool ChangeDirectory(const char* pathname)
{
	// 成功返回0，失败返回-1
	if (!chdir(pathname)) {
		cout << "当前目录：" << getcwd(NULL, 0) << endl;
		return true;
	}
	else {
		return false;
	}
}

bool ChangeDirectory(int fd)
{
	// 成功返回0，失败返回-1
	if (!fchdir(fd)) {
		cout << "当前目录：" << getcwd(NULL, 0) << endl;
		return true;
	}
	else {
		return false;
	}
}

bool CheckIsFileOrDir(const char* name)
{
	struct stat st;

	// 成功返回0，失败返回-1
	if (!stat(name, &st)) {
		if (S_ISDIR(st.st_mode)) {
			DIR* dir;
			struct dirent* file;

			if (!(dir = opendir(name))) return false;

			while ((file = readdir(dir)) != NULL) {
				if (strncmp(file->d_name, ".", 1) == 0)
					continue;
				if(!stat(file->d_name, &st))
					if (!S_ISDIR(st.st_mode))
						cout << file->d_name << endl;
			}

			return true;
		}
		else {
			if (st.st_mode & S_IROTH)
			{
				cout << "该文件只读" << endl;
			}
			if (st.st_mode & S_IWOTH)
			{
				cout << "该文件只写" << endl;
			}
			if (st.st_mode & S_IXOTH)
			{
				cout << "该文件读写" << endl;
			}
			return true;
		}
	}
	else {
		return false;
	}
}
