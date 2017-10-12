#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Input Matrix -> Flatten(n*1 vec) -> apply weight(n*n matrix) -> vec
<<<<<<< HEAD
typedef struct{
    int row, col; 
    float *matrix;

} Matrix;

void matrix_print(Matrix input_matrix)
{
	int i, j;
	for (i=0; i < input_matrix.row; i++){
		for(j=0; j < input_matrix.col; j++){
			printf("%.3f   ", input_matrix.matrix[i * input_matrix.col + j]);
		}
		printf("\n");
	}
    printf("\n");
}


=======

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
>>>>>>> b40d1cc3f2e7a907b9c263485d2671b4357f1a75
/*
 *  1 2, ...j.Lm     1 2, ...k......Rm
 *  2                2
 *  i                3
 *  ...              ...
 *  Ln               Lm
 *
 */

<<<<<<< HEAD
//float *matrix_product(int Lm, int Ln, float *L_matrix, int Rm, int Rn, float *R_matrix){
Matrix matrix_product(Matrix L, Matrix R)
{
//Lm = L.col, Ln = L.row
//Rm = R.col, Rn = R.row

    if(L.col != R.row){
        printf("Error: Left Col and Right Row does not match.");
        // Add error handling later.
    }
    int i, j, k;
    Matrix product;
    product.row = L.row;
    product.col = R.col;
	product.matrix = malloc(sizeof(float) * L.row * R.col);

    for(i=0; i < L.row ; i++){
        for(k=0; k < R.col ; k++){
            float inner_product = 0;
            for(j=0; j < L.col; j++){
                inner_product = inner_product + L.matrix[i*L.col+j] * R.matrix[j*R.col+k];
            }
            product.matrix[i*R.col+k] = inner_product;
        }
    }
    return product;
=======
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
>>>>>>> b40d1cc3f2e7a907b9c263485d2671b4357f1a75
}

float activate_function(float x)
{
    float exp_value;
    float return_value;
    exp_value = exp((double) -x);
    return_value = 1 / (1+exp_value);
<<<<<<< HEAD
    return return_value; 
}
Matrix activate(Matrix input)
{
    Matrix ret;
    ret.col = input.col;
    ret.row = 1;
    ret.matrix = malloc(sizeof(float) * input.col);
    int i;
    for(i=0;i<input.col;i++){
        ret.matrix[i] = activate_function(input.matrix[i]);
        printf("%.3f\n", ret.matrix[i]);
=======
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
>>>>>>> b40d1cc3f2e7a907b9c263485d2671b4357f1a75
    }

    return ret;

}


/*
Construct a 3 Layer Full Connection Neural Network.
Input_Vector -> Hidden Layer1 -> Hidden Layer2 -> Binary Output
*/

void main(){

<<<<<<< HEAD
	printf("Function Start\n");
    float input_layer[10] = {0.1,0.2,0.3,0.4,0.5,0.6,0.17,0.18,0.19};  
    Matrix Input_vec = {1, 10, input_layer};

	Matrix W1;
    W1.row = 10;
    W1.col = 6;
    W1.matrix = malloc(sizeof(float) * W1.row * W1.col);
	int i, j;
	for (i=0;i<W1.row;i++) {
		for (j=0;j<W1.col;j++) {
			W1.matrix[i * W1.col + j] = ((float)i * W1.col + (float)j)/100;
		}
	}
    
    Matrix W2;
    W2.row = 6;
    W2.col = 10;
    W2.matrix = malloc(sizeof(float) * W2.row * W2.col);
    int l, m;
    for (l=0;l<W2.row;l++){
        for (m=0;m<W2.col;m++){
            int r = rand() % 1000;
            W2.matrix[l*W2.col+m] = (double) r/1000;
        }
    }

    Matrix product_matrix;
    Matrix input_layer2;

	//matrix_print(w1_row, w1_col, w1_matrix);
	matrix_print(W1);
    matrix_print(W2);

    product_matrix = matrix_product(Input_vec, W1);
    printf("Product matrix\n");
    matrix_print(product_matrix);

    input_layer2 = activate(product_matrix);
    printf("Activated matrix\n");
    matrix_print(input_layer2);
    









    free (W1.matrix);
	free (W2.matrix);
    free (product_matrix.matrix);
    //free (product_matrix);

=======
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
>>>>>>> b40d1cc3f2e7a907b9c263485d2671b4357f1a75
    //getchar();
}














<<<<<<< HEAD

=======
>>>>>>> b40d1cc3f2e7a907b9c263485d2671b4357f1a75
