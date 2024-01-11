#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_LENGTH 1024

int main(int argc, char* argv[]) {
    if(argc < 2){
        printf("Syntax error!\n");
        return 3;
    }
    FILE *csv;
    float GravitationalPull = 9.8;
    char Fname[128];
    sprintf(Fname, "Fall_%sm.csv", argv[1]);
    double distance = strtod(argv[1], NULL);
    if(distance < 0){
        printf("Wrong distance! Distance should be positive value. \n");
        return 2;
    }
    csv = fopen(Fname, "w");
    if(csv == NULL) {
        perror("Error opening file!");
        return 1;
    }
    int DataCounter = 0;
    double initspeed = 0.0;
    double initdistance = distance;
    double duration = 0.0;
    double distance_data[MAX_LENGTH];
    double time_data[MAX_LENGTH];
    while(distance > 0){
        initspeed += GravitationalPull * 0.001;
        distance -= initspeed * 0.001;
        duration += 0.001;
        usleep(1000);
        distance_data[DataCounter] = distance;
        time_data[DataCounter] = duration;
        DataCounter++;
    }
    printf("It took %f seconds for it to fall \n", duration);
    for (int i = 0; i < DataCounter; i++) {
        fprintf(csv, "%lf, %lf\n", distance_data[i], time_data[i]);
    }
    printf("Data written to %s\n", Fname);
    fclose(csv);
    return 0;
}
