#include "corrector.h"

int (**get_tab_finder(void))(errt *err)
{
	int (**tab)(errt *err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR - 1);

	tab[0] = &find_semicolon;

	return (tab);
}

int (**get_tab_corrector(void))(errt *err)
{
	int (**tab)(errt *err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR);

	tab[0] = &cant_correct;
	tab[1] = &semicolon;

	return (tab);
}