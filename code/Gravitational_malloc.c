#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Syntax error!\n");
        return 3;
    }
    FILE *csv;
    float GravitationalPull = 9.8;
    char Fname[128];
    sprintf(Fname, "Fall_%sm.csv", argv[1]);
    double distance = strtod(argv[1], NULL);
    if (distance < 0) {
        printf("Wrong distance! Distance should be a positive value. \n");
        return 2;
    }
    csv = fopen(Fname, "w");
    if (csv == NULL) {
        perror("Error opening file!");
        return 1;
    }

    double *distance_data = (double *)malloc(0);  // Initialize an empty dynamic array
    double *time_data = (double *)malloc(0);      // Initialize an empty dynamic array
    if (distance_data == NULL || time_data == NULL) {
        perror("Memory allocation error!");
        fclose(csv);
        return 4;
    }

    int DataCounter = 0;
    double initspeed = 0.0;
    double initdistance = distance;
    double duration = 0.0;

    while (distance > 0) {
        initspeed += GravitationalPull * 0.001;
        distance -= initspeed * 0.001;
        duration += 0.001;
        usleep(1000);

        // Increase the size of the dynamic arrays
        distance_data = (double *)realloc(distance_data, (DataCounter + 1) * sizeof(double));
        time_data = (double *)realloc(time_data, (DataCounter + 1) * sizeof(double));

        if (distance_data == NULL || time_data == NULL) {
            perror("Memory reallocation error!");
            free(distance_data);
            free(time_data);
            fclose(csv);
            return 5;
        }

        distance_data[DataCounter] = distance;
        time_data[DataCounter] = duration;
        DataCounter++;
    }

    printf("It took %f seconds for it to fall \n", duration);

    for (int i = 0; i < DataCounter; i++) {
        fprintf(csv, "%lf, %lf\n", time_data[i], distance_data[i]);
    }

    printf("Data written to %s\n", Fname);

    // Free allocated memory
    free(distance_data);
    free(time_data);

    fclose(csv);
    return 0;
}
