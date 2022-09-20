#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  allocateArray(int numberOfArays);
void deAloc(int**arryToDealloc,int totalnumberOfArr,int bytesToUse);
void realocateMArrays(int numberofAlocations,int numberOfBytes);

int main() {
    allocateArray(50);
    return 0;
}

void allocateArray(int numberOfArays){
    clock_t startDeallo, endDeallo;
    clock_t startAllow3m, endAllow3m;
    int bytes = (1024*1024);
    startAllow3m=clock();

    int totalNumberOfArraysToAllo =3*numberOfArays;
int** allocatedArrays=malloc(totalNumberOfArraysToAllo*bytes );
for(int i =0; i<totalNumberOfArraysToAllo; i++){
 allocatedArrays[i] = malloc(i*bytes);


}
endAllow3m=clock();
double time_takenFor3m=((double )endAllow3m-startAllow3m)/CLOCKS_PER_SEC;
printf("Allocating 3m Arrays of size 1 MB took %f seconds to execute \n", time_takenFor3m);



    deAloc(allocatedArrays, totalNumberOfArraysToAllo,bytes);


}

void realocateMArrays(int numberofAlocations,int numberOfBytes){
    clock_t startAllowM, endAllowM;
    startAllowM=clock();
        int** SecondallocatedArrays=malloc(numberofAlocations*numberOfBytes);
    for(int i =0; i<numberofAlocations; i++){

        SecondallocatedArrays[i]= malloc(i*(1.4*numberOfBytes));

    }
    for( int i = 0; i < numberofAlocations; ++i ){
        printf( "%d\n", SecondallocatedArrays[i] );
    }
    endAllowM=clock();
    double time_takenForAlloM=((double)endAllowM-startAllowM)/CLOCKS_PER_SEC;
    printf("Allocating 3m Arrays of size 1.4 MB took %f seconds to execute \n", time_takenForAlloM);

}


void deAloc(int**arryToDealloc,int totalnumberOfArr,int bytesToUse){
    clock_t startDeallo, endDeallo;
    startDeallo=clock();
    for( int i = 0; i < totalnumberOfArr; ++i )
    {
        if (i%2==0){
            free(arryToDealloc[i]);
            arryToDealloc[i]=NULL;
        }
    }
        for( int i = 0; i < totalnumberOfArr; ++i ){
        printf( "%d\n", arryToDealloc[i] );
    }
    endDeallo=clock();
    double time_takenForDeallo=((double)endDeallo-startDeallo)/CLOCKS_PER_SEC;
    printf("deallocating even # of arrays of size 1MB took %f seconds to execute \n", time_takenForDeallo);

    realocateMArrays(totalnumberOfArr,bytesToUse);

}


