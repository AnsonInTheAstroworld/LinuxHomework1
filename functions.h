#pragma once
bool ModifyContent(const char* fileName, int offset, const char* buf);

bool ChangeDirectory(const char* pathname);

bool ChangeDirectory(int fd);

bool CheckIsFileOrDir(const char* name);