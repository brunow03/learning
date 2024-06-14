CC = gcc
OUTPUT_FILE = output.txt
MAIN = ./main
SRC = main.c ./src/*.c

all: time clean compile run

time:
	@echo "==========================================================================================================" | tee -a $(OUTPUT_FILE)
	@echo "==========================================================================================================" | tee -a $(OUTPUT_FILE)
	@echo "==========================================================================================================" | tee -a $(OUTPUT_FILE)
	@echo "==========================================================================================================" | tee -a $(OUTPUT_FILE)
	@stat -c %y Makefile | tee -a $(OUTPUT_FILE)

clean:
	@echo "Cleaning..."
	rm $(MAIN) || true
# @find . -type f ! \( -name "*.c" -o -name "*.h" -o -name "*.txt" -o -name "Makefile" \) -exec rm -f {} +

compile:
	@echo "Compiling..."
	$(CC) -o $(MAIN) $(SRC)
# -fsanitize=address

run:
	@echo "Running..."
	$(MAIN) | tee -a $(OUTPUT_FILE) $(IGNORE)


# @./main

# main:	./ordenação/*.c ./random/*.c



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


