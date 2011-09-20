#include "erl_nif.h" 

extern int get_memory(int pid);  
static ERL_NIF_TERM get_memory_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])  
{  
  int pid; 
  int ret;  
  if (!enif_get_int(env, argv[0], &pid)) {  
    return enif_make_badarg(env);  
  }  
  ret = get_memory(pid);  
  return enif_make_int(env, ret);  
} 

static ErlNifFunc nif_funcs[] = {  
  {"get_memory", 1, get_memory_nif}, 
}; 

ERL_NIF_INIT(memory, nif_funcs, NULL, NULL, NULL, NULL)
