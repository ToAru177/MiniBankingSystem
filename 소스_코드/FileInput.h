#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_

#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"

#define NAME_LEN 20

class FileIO {

private:
	int f_index;
	int id;
	int balance;
	char name[NAME_LEN];
	double ratio;
	double specialratio;

public:
	// File 업로드(입력)
	void input(AccountHandler &handle, ifstream &infile);
	
};

#endif // !_FILEINPUT_H
