#include <stdio.h>

int main(){

    float studentAndNote[10][3];
    float studentSmallNote[10][1] = {10,10,10,10,10,10,10,10,10,10};
    int studentSmallNoteTest[10][1];
    int totalSmallNoteP1;
    int totalSmallNoteP2;
    int totalSmallNoteP3;
    int i, j;

    totalSmallNoteP1 = 0;
    totalSmallNoteP2 = 0;
    totalSmallNoteP3 = 0;

    for(i=0;i < 2;i++){
        for(j=0;j < 3;j++){
            printf("Please, insert the note %d for the student %d: ", j+1, i+1);
            scanf("%f", &studentAndNote[i][j]);

            if(studentAndNote[i][j] <= studentSmallNote[i][0]){
                studentSmallNote[i][0] = studentAndNote[i][j];
                studentSmallNoteTest[i][0] = j;
            }
        }
        printf("\n");
    }

    printf("\n------------------------------\n");
    printf("-- Calculating, please wait.");
    printf("\n------------------------------\n\n");

    for(i=0;i < 2;i++){
        printf("The student %d, have small note: %2.f", i+1, studentSmallNote[i][0]);
        printf(" | On test: %d", studentSmallNoteTest[i][0]+1);
        printf("\n------------------------------\n\n");

        if(studentSmallNoteTest[i][0] == 0){
            totalSmallNoteP1++;
        }else if(studentSmallNoteTest[i][0] == 1){
            totalSmallNoteP2++;
        }else if(studentSmallNoteTest[i][0] == 2){
            totalSmallNoteP3++;
        }
    }

    printf("\nThe total of student, have small note in P1 is: %d", totalSmallNoteP1);
    printf("\nThe total of student, have small note in P2 is: %d", totalSmallNoteP2);
    printf("\nThe total of student, have small note in P3 is: %d", totalSmallNoteP3);

    printf("\nFinished!!!\n\n");
}
