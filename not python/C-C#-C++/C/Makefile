CC = gcc
OUTPUT_FILE = output.txt

all: clean compile run

clean:
	@echo "Cleaning..."
	@find . -type f ! \( -name "*.c" -o -name "*.h" -o -name "*.txt" -o -name "Makefile" \) -exec rm -f {} +
	
compile:
	@echo "Compiling..."
	@$(CC) -o main ./linkedLists/linked_list.c main.c ./ordenação/*.c ./random/*.c
# -fsanitize=address

run:
	@echo "Running..."
	@./main | tee -a output.txt


# ==============================================================================
# THIS FOR FUN!!

# @echo "Running...": This line will print "Running..." in the terminal.
# @./main: This line executes your main program.
# | tee output.txt: This part is crucial. The tee command reads from standard input and 
# writes to standard output and files simultaneously. 
# Here, it takes the output of ./main and writes it both to the terminal (standard output) and to output.txt.


# @make all > $(OUTPUT_FILE) 2>&1
# @make all > output.txt 2>&1
# @./main > output.txt
# @chmod +x ./rundoubleclick.sh


