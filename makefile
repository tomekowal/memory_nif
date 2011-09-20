all: memory_nif.so

memory_nif.so: memory_nif.c memory.c
	gcc -Wall -I/usr/local/lib/erlang/erts-5.8.4/include/ -fPIC -shared -o $@ $^
