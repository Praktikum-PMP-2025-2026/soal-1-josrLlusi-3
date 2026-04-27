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

void sorted(int* array, int* arraysize){
    for(int i = 0; i < *arraysize; i++){
        for(int j = 0; j < *arraysize; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void medianNya(int* array, int* arraysize, int* median){
    if(*arraysize % 2 == 0){
        *median = (array[*arraysize/2] + array[*arraysize/2 +1])/2;
    }
    if(*arraysize % 2 == 1){
        *median = (array[*arraysize/2]);
    }
}
  
int main() {
    int* array = NULL;
    int arraysize = 0;
    int temp;
    int median = 0;

    scanf("%d", &temp);

    while(temp != -1){
        arraysize++;

        if(arraysize == 1){
            array = (int*) malloc(arraysize * sizeof(int));
        }
        else{
            array = (int*) realloc(array, arraysize * sizeof(int));
        }

        array[arraysize-1] = temp;

        scanf("%d", &temp);
    }

    printf("COUNT %d", arraysize);
    sorted(array, &arraysize);
    printf("SORTED ");
    for(int i = 0; i< arraysize; i++){
        printf("%d ", array[i]);
    }
    medianNya(array, &arraysize, &median);
    printf("MEDIAN %d", median);

    // for(int i = 0; i<arraysize; i++){
    //     printf("%d\n", array[i]);
    // }

    free(array);
    return 0;
}
 
