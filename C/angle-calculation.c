#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(){

    int i, j, k;
    double v1[3];
    double v2[3];
    double value;
    double angle;
    double scalarProduct;
    double moduleVector1, moduleVector2;
    double finalCalc;

    printf("-------------------------------------------------------------\n");
    printf("Insert the values for the vectors (v1 and v2):\n");
    printf("-------------------------------------------------------------\n");

    printf("Insert the value to vector v1 for x: ");
    scanf("%lf", &value);
    v1[0] = value;

    printf("Insert the value to vector v1 for y: ");
    scanf("%lf", &value);
    v1[1] = value;

    printf("Insert the value to vector v1 for z: ");
    scanf("%lf", &value);
    v1[2] = value;

    printf("\n-------------------------------------------------------------\n\n");

    printf("Insert the value to vector v2 for x2: ");
    scanf("%lf", &value);
    v2[0] = value;

    printf("Insert the value to vector v2 for y2: ");
    scanf("%lf", &value);
    v2[1] = value;

    printf("Insert the value to vector v2 for z2: ");
    scanf("%lf", &value);
    v2[2] = value;

    scalarProduct = (v1[0]*v2[0])+(v1[1]*v2[1])+(v1[2]*v2[2]);

    if(scalarProduct < 0){
        scalarProduct = scalarProduct*(-1);
    }

    moduleVector1 = ((powf(v1[0], 2))+(powf(v1[1], 2))+(powf(v1[2], 2)));
    moduleVector1 = sqrt(moduleVector1);

    moduleVector2 = ((powf(v2[0], 2))+(powf(v2[1], 2))+(powf(v2[2], 2)));
    moduleVector2 = sqrt(moduleVector2);

    finalCalc = (scalarProduct)/(moduleVector1*moduleVector2);

    angle = acos(finalCalc) * 180.0 / PI;

    printf("\nFinished! The angle is: %f \n", angle);

}
