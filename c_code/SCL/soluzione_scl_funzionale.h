#pragma once

#include "scl.h"

TipoSCL sclstring_create(const char *s);
TipoSCL sclstring_remove(TipoSCL scl_p, char val);
TipoSCL sclstring_add_underscore(TipoSCL scl_p);
TipoSCL sclstring_remove_duplicates(TipoSCL scl_p);
TipoSCL alterna_con_step(TipoSCL scl1, TipoSCL scl2, int step);
TipoSCL alterna_reverse(TipoSCL scl_1, const char *array);
TipoSCL aggiungi_caratteri(const TipoSCL scl, const char *str);
