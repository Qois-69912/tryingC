CC = gcc

$(project): $(project).c
ifeq ($(debug),)
	$(CC) $(project).c -o $(project)
else
	$(CC) -g $(project).c -o $(project)
	gdb $(project)
endif

clean:
	find . -type f -executable -delete
