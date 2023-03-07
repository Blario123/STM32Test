#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

float Kp = 1.5;
float Ki = 5.0;
float Kd = 0.5;

int main(int argc, char *argv[]) {
    FILE* file = fopen("output.txt", "w+");
    if(!file) {
        perror("Error opening file.");
        return -1;
    }
    int num;
    printf("Enter demand value: ");
    scanf("%d", &num);
    float Pv = 0.0;
    float error;
    double eT = 0.0;
    for(double i = 0.0; i < 100.0; i += 0.2) {
        float _eT = eT;
        eT = num - Pv;
        printf("eT = %f\n", eT);
        float pOut = Kp * eT;
        float iOut = 0.0;
        for(int j = 0; j < i; j++) {
            iOut += eT;
        }
        float dOut = Kd * (eT - _eT);
        printf("i = %f\tpOut = %f\tiOut = %f\tdOut = %f\n", i, pOut, iOut, dOut);
        error = pOut + (Ki * iOut) + dOut;
        Pv += (0.2 * (error/abs(error))) * error;
        fprintf(file, "Error:%f,Pv:%f\n", eT, Pv);
    }
    fclose(file);
    return 0;
}
