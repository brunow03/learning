.PHONY: clean all compile run 

CC = gcc

all: clean compile run 

clean:
	@echo "Cleaning..."
	@find . -type f ! \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) -exec rm -f {} +


compile:
	@echo "Compiling..."
	@$(CC) -o main *.c *.h ../linkedLists/linked_list.c
# -fsanitize=address

run:
	@echo "Running..."
	@./main


# THIS FOR FUN!!
# ==============================================================================
