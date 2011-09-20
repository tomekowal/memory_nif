-module(memory).
-export([get_memory/1]).
-on_load(init/0).

init() ->
    ok = erlang:load_nif("./memory_nif", 0).
get_memory(_X) ->
    exit(nif_library_not_loaded).
