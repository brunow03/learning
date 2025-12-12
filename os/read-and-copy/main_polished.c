#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    // Acquire input file name
    // Write prompt to screen
    const char *prompt_source = "Enter source file: \n";
    ssize_t n_write = write(1, prompt_source, strlen(prompt_source));
    if (n_write == -1)
    {
        perror("ERROR WRITING IN TERMINAL");
    }

    // Accept input
    const int FILE_NAME_SIZE = 50;
    char source_file[FILE_NAME_SIZE];

    ssize_t n_read = read(0, source_file, FILE_NAME_SIZE);
    if (n_read == -1)
    {
        perror("ERROR READING INPUT");
    }

    if (n_read > 0) {
        // Replace newline with null terminator
        if (source_file[n_read - 1] == '\n') 
        {
            source_file[n_read - 1] = '\0';
        } 
        else 
        {
            source_file[n_read] = '\0';
        }
    }
    // printf("%s", source_file);

    // Acquire output file name
    // Write prompt to screen
    const char *prompt_destination = "Enter destination file: \n";
    n_write = write(1, prompt_destination, strlen(prompt_destination));
    if (n_write == -1)
    {
        perror("ERROR WRITING IN TERMINAL");
    }

    // Accept input
    char destination_file[FILE_NAME_SIZE];
    n_read = read(0, destination_file, FILE_NAME_SIZE);
    if (n_read == -1)
    {
        perror("ERROR READING INPUT");
    }
    if (n_read > 0) {
        // Replace newline with null terminator
        if (destination_file[n_read - 1] == '\n') 
        {
            destination_file[n_read - 1] = '\0';
        } 
        else 
        {
            destination_file[n_read] = '\0';
        }
    }

    // Open input file
    int fd_source = open(source_file, O_RDONLY);

    // If file doesn't exist, abort
    if (fd_source == -1)
    {
        perror("OPEN ERROR");
        return 1;
    }

    // Create output file
    int fd_destination = open(destination_file, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    // if file exists, abort
    if (fd_destination == -1)
    {
        perror("CREATE FILE ERROR");
        return 1;
    }
    
    // Loop
    // Read from input file
    ssize_t bytes_read;
    const int TEXT_SIZE = 1024;
    char text[TEXT_SIZE];
    while ((bytes_read = read(fd_source, text, TEXT_SIZE)) > 0) //Until read fails
    {
        //Write to output file
        ssize_t bytes_written = write(fd_destination, text, bytes_read);
        if (bytes_written == -1)
        {
            perror("ERROR WRITING TO FILE");
            return 1;
        }
    }
    
    if (bytes_read == -1)
    {
        perror("ERROR READING SOURCE FILE");
        return 1;
    }

    // Close output file
    close(fd_source);
    close(fd_destination);

    // Write completion message to screen
    const char *complete_msg = "FILE COPYING COMPLETED!\n";
    write(1, complete_msg, strlen(complete_msg));
    // Terminate normally
    return 0;
}
