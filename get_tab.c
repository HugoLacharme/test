#include "corrector.h"

int (**get_tab_finder(void))(char **lines, int start, int end, errt err)
{
	int (**tab)(char **lines, int start, int end, errt err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR);

	tab[0] = &cant_correct;
	tab[1] = &find_semicolon;
}

int (**get_tab_corrector(void))(char **lines, int start, int end, errt err)
{
	int (**tab)(char **lines, int start, int end, errt err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR);

	tab[0] = &cant_correct;
	tab[1] = &semicolon;
}