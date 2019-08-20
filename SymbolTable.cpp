#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	//R0-R15
	string p[16] = { "R0","R1", "R2", "R3",
					 "R4", "R5", "R6", "R7", 
					 "R8", "R9","R10","R11",
		             "R12","R13","R14","R15" };
	for (count= 0; count < 16; count++){
		ramcs.insert(pair<string,int>(p[count], count));
	}
	ramcs.insert(pair<string, int>("SP", 0));
	ramcs.insert(pair<string, int>("LCL", 1));
	ramcs.insert(pair<string, int>("ARG", 2));
	ramcs.insert(pair<string, int>("THIS", 3));
	ramcs.insert(pair<string, int>("THAT", 4));
	ramcs.insert(pair<string, int>("SCREEN", 16384));//¼üÅÌ
	ramcs.insert(pair<string, int>("KBD", 24576));//ÆÁÄ»


}


SymbolTable::~SymbolTable()
{
}

void SymbolTable::addEntry(char *c, int addr) {
	ramcs.insert(pair<string, int>(c, addr));
}

bool SymbolTable::contains(char *ads) {
	map<string, int>::iterator iter;
	iter = ramcs.find(ads);
	if (iter != ramcs.end()) return true;
	return false;
}

int SymbolTable::GetAddress(char *ads) {
	return ramcs[ads];
}