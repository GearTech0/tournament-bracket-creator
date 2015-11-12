#include <stdio.h>
#include <time.h>

int checknum(int chosennums[8], int randnum)
{
    if(chosennums[randnum-1] == randnum)
    {
        return 0;
    }
    return 1;
}
int main()
{
    FILE *ofp;
    int ui, i=0, rostsize, iter = 0;
    srand(time(NULL));
    ofp = fopen("tournament.txt", "r");
    fscanf(ofp, "%d", &rostsize);
    int roster[rostsize];
    int names[rostsize][15];
    int chosennums[rostsize];

    for(i = 0; i <rostsize; i++)
    {
        fscanf(ofp,"%s", &names[i]);
    }

    int number = rand()%rostsize+1;
    int number2 = rand()%rostsize+1;

    for(i = 0; i < rostsize; i++)
    {
        chosennums[i] = rostsize+1;
    }
//    printf("PLAYER 1\tvs\tPLAYER 2\n\n");
    while(iter < rostsize/2)
    {
        while(!checknum(chosennums, number)) number = rand()%rostsize+1;
        chosennums[number-1] = number;
        while(!checknum(chosennums, number2)) number2 = rand()%rostsize+1;
        chosennums[number2-1] = number2;

        printf("%s\tvs\t%s\n\n", names[number-1], names[number2-1]);
        //scanf("%d", &ui);


        number = rand()%rostsize+1;
        iter+=1;
    }
    return 0;
    //ofp = fopen("tournament.txt", "r");
}
