#include <stdio.h>
#define ROW 45
#define COLUMN 75

int euclids(int u, int v);

int main(int argc, char const *argv[])
{
	int a[ROW][COLUMN];
	int i, j;

	for(i = 0; i < ROW; i++){
		for (j = 0; j < COLUMN; j++){
			if(euclids(i,j) == 1){
				a[i][j] = 1;
			}
			else{
				a[i][j] = 0;
			}
		}
	}
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COLUMN; j++){
			if (a[i][j] == 1)
			{
				printf("1 ");
			}
			else
				printf("0 ");
		}
		printf("\n");
	}


	printf("\n");
	return 0;
}

int euclids(int u, int v){
	int t;
	if (u == 0 || v == 0){
		return 0;
	}
	while(u > 0){
		if (u < v)
		{
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;

}