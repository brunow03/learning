#include "../include/randarray.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>
#include <limits.h>

/*

// Write callback function to capture the response data
static size_t 
write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total_size = size * nmemb;
    strcat((char *)userdata, (char *)ptr);
    return total_size;
}

// Function to get a quantum random number
static unsigned int 
quantum_rand() {
    CURL *curl;
    CURLcode res;
    char buffer[1024] = {0}; // Buffer to store the response

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Set the URL of the ANU QRNG API to fetch 4 uint8 values
        curl_easy_setopt(curl, CURLOPT_URL, "https://qrng.anu.edu.au/API/jsonI.php?length=4&type=uint8");

        // Set the write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // Set the buffer to store the response
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 0; // Return 0 in case of an error
        }

        // Clean up CURL
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    // Extract the random numbers from the response
    unsigned int rand_number = 0;
    sscanf(buffer, "{\"type\":\"uint8\",\"length\":4,\"data\":[%u,%u,%u,%u],\"success\":true}", 
           &rand_number, &rand_number, &rand_number, &rand_number); // Read 4 uint8 values

    return rand_number;
}
*/

void 
randomArray(int v[], int n, int p, int q){

	for (int i = 0; i < n; ++i)
		v[i] = rand() % p - q;
}

int 
randInt(int n, int m){
	return rand() % n - m;
}

void 
bin_rand_array(int v[], int n){
	for (int i = 0; i < n; ++i)
		v[i] = rand() % 2;
}

void 
DNA_rand_array(char v[], int n){
	char a, c, g, t;
	a = 'A'; c = 'C'; g = 'G'; t = 'T';
	int base;

	for (int i = 0; i < n; ++i)
	{
		base = rand() % 4;
		switch (base) {
			case 0:
				v[i] = a;
				break;
			case 1:
				v[i] = c;
				break;
			case 2:
				v[i] = g;
				break;
			case 3:
				v[i] = t;
				break;
		}
	}
}

double randDouble(){
    return (double) rand() / (double) RAND_MAX + 1.0;
}