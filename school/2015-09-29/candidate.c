#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

    int candidate[30][3];
    int candidateTotalVote[3] = {0,0,0};
    int totalVoteNull = 0;
    int totalVoteWhite = 0;
    int i,j;
    int people;
    int totalVote;
    int maxVote;
    int candidateMaxVote;
    float porcentVoteNull;
    float porcentVoteWhite;

    printf("Please, insert the total people to vote (max 30 peoples): ");
    scanf("%d", &people);

    if(people > 30){
        printf("-----MAX PEOPLE EXCEDED----- \n");
        exit(0);
    }

    printf("\n---------------------------------\n");
    printf("Here, you can vote, using: \n ");
    printf("* 1 = Vote in actual candidate; \n ");
    printf("* 0 = Not vote in candidate actual; \n ");
    printf("* 5 = Vote null \n ");
    printf("* 6 = Vote white \n ");
    printf("\n---------------------------------\n");

    for(i=1; i <= people; i++){
        for(j=0; j <= 3; j++) {
            printf("Please, do you want vote in candidate %d? \n", j + 1);
            scanf("%d", &candidate[people][j]);

            if(candidate[people][j] == 1){
                candidateTotalVote[j] = candidateTotalVote[j] + 1;
                totalVote = totalVote+1;
            }

            if (candidate[people][j] == 5) {
                totalVoteNull = totalVoteNull + 1;
            }

            if (candidate[people][j] == 6) {
               totalVoteWhite = totalVoteWhite + 1;
            }

            if((j == 3) && (people != i)){
                printf("\n--------Next people--------\n");
            }
        }
    }

    printf("\n---------------------------------\n");

    printf("Candidates: \n");
    for(j=0; j <= 3; j++) {
        printf("* Candidate %d; Total Vote: %d \n", (j+1), candidateTotalVote[j]);
    }

    for(i=0; i <= 3; i++){
        if (candidateTotalVote[i] > maxVote){
            maxVote = candidateTotalVote[i];
            candidateMaxVote = (i+1);
        }
    }

    porcentVoteWhite = (totalVoteWhite > 0) ? (totalVote/totalVoteWhite)*100 : 0;
    porcentVoteNull = (totalVoteNull > 0) ? (totalVote/totalVoteNull)*100 : 0;

    if(candidateMaxVote != 0){
        printf("\nCandidate with the most votes: %d; Total votes: %d", candidateMaxVote, maxVote);
    }

    printf("\nTotal of votes white: %d; Porcent: %.2f \n", totalVoteWhite, porcentVoteWhite);
    printf("\nTotal of votes null: %d; Porcent: %.2f \n", totalVoteNull, porcentVoteNull);


}
