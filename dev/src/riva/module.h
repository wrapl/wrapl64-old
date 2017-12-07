#ifndef MODULE_H
#define MODULE_H

typedef struct module_t module_t;

typedef struct module_provider_t module_provider_t;
typedef struct module_import_t module_import_t;

typedef void *(*module_find_fn)(const char *Path, unsigned int PathLength);
typedef int (*module_load_fn)(module_provider_t *Module, void *Data);
typedef module_import_t *(*module_import_fn)(module_provider_t *Module, const char *Name, unsigned int NameLength);

void module_add_loader(const char *Name, int Priority, module_load_fn, module_import_fn);

module_t *module_load(const char *Path, unsigned int PathLength);
module_import_t *module_import(module_t *Module, const char *Name, unsigned int NameLength);
const char *module_import_type(module_import_t *Import);
void *module_import_get_addr(module_import_t *Import, int Index);
int module_import_get_int(module_import_t *Import, int Index);

#endif
