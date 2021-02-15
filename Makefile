my-look: my-look.c
	gcc -o my-look my-look.c -Wall -Werror

my-rev: my-rev.c
	gcc -o my-rev my-rev.c -Wall -Werror

.PHONY: clean
clean:
	rm my-look
	rm my-rev  
