#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // --- file variable to access file ---
    FILE * file = fopen("file.in", "r");

    // --- create cases variable to store number of test cases and read it from the file --- 
    int cases;
    fscanf(file, "%d", &cases);
    printf("----------------------\n");
    printf("TOTAL TEST CASE: %d\n", cases);

    int num_file; // num_file variable declaration to store the number of files for each test case ---

    // --- loop through the file based on the value of cases variable ---
    for (int i = 0; i < cases; i++){
        // --- get the number of files by reaing the next line from the file 
        fscanf(file, "%d", &num_file);
        // --- variable declaration to temporarily store the file name and file id ---
        char file_name[40];
        int file_id;
        // --- array variable declaration to store all the file names and file id ---
        char arr_file_name[num_file][40];
        int arr_file_id[num_file];
        // --- loop through the file using the num_file variable and get the file name and id and store in the array ---
        for (int j = 0; j < num_file; j++){
            

            fscanf(file, "%s %d", file_name, &file_id);
            
            strcpy(arr_file_name[j], file_name);
            arr_file_id[j] = file_id; 

        }

        // --- to check for duplicate names, if found check the one with the smaller id and use it to replace the one with the larger id ---
        for (int k = 0; k < num_file; k++){
            for (int l = 0; l < num_file; l++){
                if (strcmp(arr_file_name[k], arr_file_name[l]) != 0){
                    continue;
                } else {
                    if (arr_file_id[k] > arr_file_id[l]){
                        arr_file_id[k] = arr_file_id[l];
                    }
                }
            }
        }
        printf("\n--------------\n");
        int len = (sizeof(arr_file_id)/sizeof(arr_file_id[0]));
    
        // --- to delete duplicate id stored ---
        for (int r = 0; r < len; r++){
            for (int s = r + 1;  s < (len); s++){
                if (arr_file_id[r] == arr_file_id[s]){
                    for (int t = s; t < len-1; t++){
                            arr_file_id[t] = arr_file_id[t + 1];
                    }
                    len--;
                    s--;
                    
                }
            }
            
        }

        //--- to sort id in increasing order ---
        for (int a = 0; a < len; a++){
            for (int b = a + 1; b < len; b++){
                if (arr_file_id[a] > arr_file_id[b]){
                    int temp = arr_file_id[a];
                    arr_file_id[a] = arr_file_id[b];
                    arr_file_id[b] = temp;

                }
            }
        }

        // --- to print all id in the array (which are those that won't get deleted)  ---
        for (int v = 0; v < len; v++){
            printf("%d\t", arr_file_id[v]);
        }
        
    }
    
    return 0;
}