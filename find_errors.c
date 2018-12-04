#include "corrector.h"

int cant_correct(char **lines, int start, int end, errt err)
{
	return (0);
}

int find_errors(char **lines, int start, int end, errt err)
{
	int res;
	int (**tab)(char **lines, int start, int end, errt err);

	tab = get_tab_finder();
	for (int i = 0; i < NB_FNCTCOR; i++) {
		if ((res = ))
	}
}