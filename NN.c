#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Input Matrix -> Flatten(n*1 vec) -> apply weight(n*n matrix) -> vec

void matrix_print(int row, int col, float *matrix){
	
	int i, j;
	for (i=0; i < row; i++){
		for(j=0; j < col; j++){
			printf("%f   ", matrix[i * col + j]);
		
		}
		printf("\n");
	}
    
    printf("\n");
	//return 0;
}

int print_vec(int vector[]){

	int i = 0;
	for (i=0; i<5; i++){
		printf("%d ", vector[i]);	
	}
}
/*
 *  1 2, ...j.Lm     1 2, ...k......Rm
 *  2                2
 *  i                3
 *  ...              ...
 *  Ln               Lm
 *
 */

float *matrix_product(int Lm, int Ln, float *L_matrix, int Rm, int Rn, float *R_matrix){
    if(Lm != Rn){
        printf("Error: Left Col and Right Row does not match.");
        return 0;
    }
    int i, j, k;
    float *answer;
	answer = malloc(sizeof(float) * Ln * Rm);

    for(i=0;i < Ln;i++){
        for(k=0;k<Rm;k++){
            float sum = 0;
            for(j=0; j<Lm; j++){
                sum = sum + L_matrix[i*Lm + j]*R_matrix[j*Rm + k];
            }
            answer[i*Rm+k] = sum;
        }
    }
    return answer;
}

float activate_function(float x)
{
    float exp_value;
    float return_value;
    exp_value = exp((double) -x);
    return_value = 1 / (1+exp_value);
    printf("%f\n", return_value);
    return return_value; 
}
float * activate(int col, float * input)
{
    float *ret;
    ret = malloc(sizeof(float) * col);
    int i;
    for(i=0;i<col;i++){
        ret[i] = activate_function(input[i]);
    }

    return ret;

}


/*
Construct a 3 Layer Full Connection Neural Network.
Input_Vector -> Hidden Layer1 -> Hidden Layer2 -> Binary Output
*/

void main(){

	printf("Hello Cicero\n");

	float input_vector[10]={0.,0.1,0.2,0.3,0.4,0.5,0.6,0.17,0.18,0.19};

	float *w1_matrix;
    float *w2_matrix;
    float *product_matrix;
    float *input_layer2;

	// Initializing W1 Matrix
	int w1_row = 3;
	int w1_col = 4;
	w1_matrix = malloc(sizeof(float) * w1_row * w1_col);
	int i, j;
	for (i=0;i<w1_row;i++) {
		for (j=0;j<w1_col;j++) {
			w1_matrix[i * w1_col + j] = (float)i * w1_col + (float)j;
		}
	}

    int w2_row = 10;
    int w2_col = 4;
    w2_matrix = malloc(sizeof(float) * w2_row * w2_col);
    int l,m;
    for (l=0;l<w2_row;l++){
        for (m=0;m<w2_col;m++){
            int r = rand() % 1000;
            w2_matrix[l*w2_col+m] = (double) r/1000;
        }

    }
	//matrix_print(w1_row, w1_col, w1_matrix);
	matrix_print(1, 10, input_vector);
    matrix_print(w2_row, w2_col, w2_matrix);
    //product_matrix = matrix_product(w1_col, w1_row, w1_matrix, w2_col, w2_row, w2_matrix);
    product_matrix = matrix_product(10, 1, input_vector, w2_col, w2_row, w2_matrix);
    matrix_print(1, w2_col, product_matrix);
    input_layer2 = activate(4, product_matrix);
    matrix_print(1, w2_col, input_layer2);
    free (w1_matrix);
	free (w2_matrix);
    free (product_matrix);
    //getchar();
}














