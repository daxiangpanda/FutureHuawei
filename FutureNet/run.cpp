#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{	
	cerr << argv[1] << endl;
	if (argc == 2)
	{
		char op[1000];
		sprintf(op, "./bin/future_net %stopo.csv %sdemand.csv %sresult.csv 2> log.txt", argv[1], argv[1], argv[1]);
		system(op);	
	}
	return 0;
}
