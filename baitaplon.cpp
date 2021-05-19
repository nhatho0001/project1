#include"my_liprary.h"
int main()
{
	time_t now = time(0);
#pragma warning(suppress : 4996)
	tm* ht = localtime(&now);
	cout <<  ht->tm_mday << "/" << ht->tm_mon + 1 << "/" << ht->tm_year + 1900 << endl;
	return 0; 
}