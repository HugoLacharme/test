#include "corrector.h"

int cant_correct(errt *err)
{
	printf("can't correct error %s:%d:%d in function %s\n",err->file.name, err->ligne
	,err->cur, err->function);

	return (0);
}

int find_errors(errt *err)
{
	int res;
	int (**fc)(errt *err);
	fc = get_tab_finder();
	while (err != NULL) {
		err->fct_err = 0;
		for (int i = 0; i < NB_FNCTCOR - 1; i++) {
			if ((res = (*fc[i])(err)) > 0)
				err->fct_err = res;
		}
		err = err ->next;
	}
	free(fc);
}