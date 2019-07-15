#include "FileInput.h"
#include "AccountHandler.h"

// File 업로드(입력)
void FileIO::input(AccountHandler &handle, ifstream &infile) {
	while (!infile.eof()) {

		infile >> f_index;

		if (f_index == 1) {

			infile >> id;
			infile >> name;
			infile >> balance;
			infile >> ratio;

			handle.FileMakeNormalAccount(f_index, id, balance, name, ratio);
		}

		else if (f_index == 2) {
			infile >> id;
			infile >> name;
			infile >> balance;
			infile >> specialratio;
			infile >> ratio;


			handle.FileMakeHighCreditAccount(f_index, id, balance, name, ratio, specialratio);
		}
	}
}
