#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void overwrite(const char *folder_path, size_t size_in_bytes) {
    struct dirent *entry;
    char file_path[1024]; // To store the full file path
    FILE *file;

    // Seed the random number generator
    srand(time(NULL));

    // Open the folder
    DIR *folder = opendir(folder_path);
    if (!folder) {
        perror("Unable to open folder");
        return;
    }

    // Buffer to hold random data
    unsigned char *random_data = malloc(size_in_bytes);
    if (!random_data) {
        perror("Failed to allocate memory for random data");
        closedir(folder);
        return;
    }

    // Iterate through files in the folder
    while ((entry = readdir(folder)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build the full path to the file
        snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, entry->d_name);

        // Open the file in write mode
        file = fopen(file_path, "w");
        if (!file) {
            perror("Error opening file");
            continue;
        }

        // Generate random data
        for (size_t i = 0; i < size_in_bytes; i++) {
            random_data[i] = rand() % 256; // Random byte (0-255)
        }

        // Write random data to the file
        fwrite(random_data, 1, size_in_bytes, file);

        // Close the file
        fclose(file);

        printf("Overwritten with random data: %s\n", file_path);
    }

    // Clean up
    free(random_data);
    closedir(folder);
}