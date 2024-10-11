#include <stdio.h>

#define MAX_MATRIX_ROW 10
#define MAX_MATRIX_COLUMN 10
typedef struct {
	int matrix[MAX_MATRIX_ROW][MAX_MATRIX_COLUMN];
	int r;// The row of martix
	int c;// The column of martix
}_matrix;

void ValueMatrix(_matrix* matrix);
void PrintfMatrix(_matrix* matrix);
void PrintfRowMatrix(int(*a)[MAX_MATRIX_COLUMN], int x, int y);
void PinrtfColumnMatrix(_matrix martix, int x, int y);
_matrix maltipliction(_matrix* matrix_A, _matrix* matrix_B);

int main(int argc, char* argv[]){

	_matrix matrix_A;
	_matrix matrix_B;
	_matrix matrix_C;

	ValueMatrix(&matrix_A);
	PrintfMatrix(&matrix_A);

	PinrtfColumnMatrix(matrix_A, 2, 3);

return 0;
}


//@function: calculate matrix_A  x  matrix_B
//@para: matrix_A  The point of _matrix
//		matrix_B  The poinr of _matrix
//@author:  zx
//@return   matrix
_matrix maltipliction(_matrix *matrix_A,_matrix *matrix_B){

	_matrix matrix_C = {0};

	if (matrix_A->c == matrix_B->r) {
		matrix_C.r = matrix_A->r;
		matrix_C.c = matrix_B->c;
		for (int a = 0; a < matrix_A->r; a++) {
			for (int b = 0; b < matrix_B->c; b++) {
				for (int c = 0; c < matrix_A->c; c++) {
					 
					matrix_C.matrix[a][b] += matrix_A->matrix[a][c] * \
						matrix_B->matrix[c][b];
				}
			}
		}
		
	}

	else {
		printf("enter matrix error\n");
	}
	return matrix_C;
}

//@function: ValueMatrix
//@describtion:
//@para: The point of matrix
//@author: zx
//@return: 
void ValueMatrix(_matrix *matrix) {

	int temp;

	printf("please enter row of Matrix\n");
	scanf_s("%d", &(matrix->r));

	printf("please enter column of Matrix\n");
	scanf_s("%d", &(matrix->c));

	printf("please enter element of Matrix\n");
	for (int a = 0; a < matrix->r; a++) {
		for (int b = 0; b < matrix->c; b++) {
			scanf_s("%d", &temp);
			matrix->matrix[a][b] = temp;
		}
	}
}
//@function:	PrintfMatrix
//@para: The point of matrix
//@author: zx
//@return:
void PrintfMatrix(_matrix* matrix) {
	printf("\nr of matrix is %d\n",matrix->r);
	printf("c of matrix is %d\n", matrix->c);
	printf("matrix is :\n");
	for (int a = 0; a < matrix->r;a++) {	
		printf("\n");
			for (int b = 0; b < matrix->c; b++) {
				printf("%d ", matrix->matrix[a][b]);
		}
	}
	printf("\n");
}

//@function:	 PrintfRowMatrix
//@describtion:  遍历数组的某行
//@para:		 a数组指针
//				 x 行数
//				 y 有效列数
//@author: 
//@return:
void PrintfRowMatrix(int (*a)[MAX_MATRIX_COLUMN], int x,int y) {

	for (int i = x-1; i < x; ++i)
		for (int j = 0; j < y; ++j)
		{
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
}

//@function:	 PrintfColumnMatrix
//@describtion:  遍历数组的某列
//@para:		 martix 结构体变量
//				 x 输出行数
//				 y 输出某列
//@author: 
//@return:
void PinrtfColumnMatrix(_matrix martix, int x,int y) {
	int(* p)[10] = martix.matrix;
	if (martix.c >= y) {
		for (int i = 0; i < x; i++) {
			//printf("a[%d][%d] = %d \n", i + 1, y, *(* (martix.matrix +i) ));
			printf("a[%d][%d] = %d \n", i + 1, y, *(*(p +i)));
		}
	}
	else {
		printf("PinrtfColumnMatrix error\n");
	}
}