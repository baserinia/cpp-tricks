// Copyright (C) 2016 Amir Baserinia

// When testing and debugging your code, you might need to print variables.
// The LOG macro provides a very simple technique to do so. You simple call
// it with a variable name. It prints the file name, line number, variable 
// name, and variable value to stderr.

// If you run the sample code, you will get something like this:
//	file "macro.cpp", line 15: var = 0
//	file "macro.cpp", line 16: &var = 0x7fffc30d1d6c

#include <iostream>

#ifndef LOG
  #define LOG(X) { \
    std::cerr << "file \"" << __FILE__ << "\", line " << __LINE__ << ": "; \
    std::cerr << #X" = " << (X) << std::endl; \
  }
#endif

int main()
{
	int var;
	LOG(var);
	LOG(&var);
	return 0;
}

