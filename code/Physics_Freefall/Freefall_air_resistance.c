#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "freefall.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Syntax error!\n");
        printf("Usage: %s <distance> <weight> <terminal Velocity> \n", argv[0]);
        return 3;
    }
    FILE *csv;
    struct freefall_data data;
    data.TerminalVelocity = atof(argv[3]);
    float weight = atof(argv[2]);
    data.GravitationalPull = 9.8;
    data.Fname[128];
    sprintf(data.Fname, "Fall_%sm.csv", argv[1]);
    data.distance = strtod(argv[1], NULL);
    if (data.distance < 0) {
        printf("Wrong distance! Distance should be a positive value. \n");
        return 2;
    }
    if (weight < 0) {
        printf("Weight should be positive value\n");
        return 5;
    }
    csv = fopen(data.Fname, "w");
    if (csv == NULL) {
        perror("Error opening file!");
        return 1;
    }

    double *distance_data = (double *)malloc(0);  // Initialize an empty dynamic array
    double *time_data = (double *)malloc(0);      // Initialize an empty dynamic array
    if (distance_data == NULL || time_data == NULL) {
        perror("Memory allocation error!");
        free(distance_data);
        free(time_data);
        fclose(csv);
        return 4;
    }

    double initdistance = data.distance;
    double duration = 0.0;

    while (data.distance > 0) {
        float air_resistance = (weight * data.GravitationalPull) / data.TerminalVelocity;
        data.initspeed += (data.GravitationalPull + air_resistance) * 0.001;
        data.distance -= data.initspeed * 0.001;
        duration += 0.001;

        // Increase the size of the dynamic arrays
        distance_data = (double *)realloc(distance_data, (data.DataCounter + 1) * sizeof(double));
        time_data = (double *)realloc(time_data, (data.DataCounter + 1) * sizeof(double));

        if (distance_data == NULL || time_data == NULL) {
            perror("Memory reallocation error!");
            free(distance_data);
            free(time_data);
            fclose(csv);
            return 6;
        }

        distance_data[data.DataCounter] = data.distance;
        time_data[data.DataCounter] = duration;
        data.DataCounter++;
    }

    printf("It took %f seconds for it to fall \n", duration);

    for (int i = 0; i < data.DataCounter; i++) {
        fprintf(csv, "%lf, %lf\n", time_data[i], distance_data[i]);
    }

    printf("Data written to %s\n", data.Fname);

    // Free allocated memory
    free(distance_data);
    free(time_data);

    fclose(csv);
    return 0;
}