/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Jose Luis Fernando Saragi
 *   Nama File           : soal1.c
 *   Deskripsi           : membuat sebuah dynamic array yang dibatasi dengan -1 lalu melakukan sorting dan mencari mediannya.
 * 
 */




 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

void sorted(int* array, int arraysize){
    int temp =0;
    for(int i = 0; i < arraysize; i++){
        for(int j = 0;  j<arraysize-1-i; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void medianNya(int* array, int arraysize, double* median, int*medianint){
    if(arraysize == 2){
        *medianint = (array[0] + array[1])/2.0;
    }
    else if(arraysize % 2 == 0){
        *medianint = (array[(arraysize-1)/2] + array[arraysize/2]) / 2.0;
    }
    else{
        *median = (array[arraysize/2]);
    }
}
void printsort(int* array, int arraysize){
    printf("SORTED ");
    for(int i = 0; i< arraysize; i++){
        printf("%d ", array[i]);
    }
}
  
int main() {
    int* array = NULL;
    int arraysize = 0;
    int temp = 0;
    double median = 0;
    int medianint = 0;

    scanf("%d", &temp);

    while(temp != -1){

        arraysize++;

        if(arraysize == 1){
            array = (int*) malloc(arraysize * sizeof(int));
        }
        else{
            array = (int*) realloc(array, arraysize * sizeof(int));
        }

        array[arraysize - 1] = temp;

        scanf("%d", &temp);
    }

    // for(int i = 0; i<arraysize; i++){
    //     printf("%d\n", array[i]);
    // }

    sorted(array, arraysize);

    medianNya(array, arraysize, &median, &medianint);

    printf("COUNT %d ", arraysize);

    printsort(array, arraysize);

    if(arraysize % 2 !=0){
        printf("MEDIAN %.2f", median);
    }
    else{
        printf("MEDIAN %d", medianint);
    }

    // printf("\n");
    // for(int i = 0; i<arraysize; i++){
    //     printf("%d\n", array[i]);
    // }

    free(array);
    return 0;
}
 
