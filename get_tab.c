#include "corrector.h"

int (**get_tab_finder(void))(errt *err)
{
	int (**tab)(errt *err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR - 1);

	tab[0] = &find_semicolon;
	tab[1] = &find_acol_close,
	tab[2] = &find_acol_open;

	return (tab);
}

int (**get_tab_corrector(void))(errt *err)
{
	int (**tab)(errt *err);

	tab = malloc(sizeof(*tab) * NB_FNCTCOR);

	tab[0] = &cant_correct;
	tab[1] = &semicolon;
	tab[2] = &acol_close;
	tab[3] = &acol_open;

	return (tab);
}