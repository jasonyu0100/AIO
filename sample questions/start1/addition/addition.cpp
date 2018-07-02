#include <cstdio>


FILE* inputFile;
FILE* outputFile;
int first, second, total;

int main() {
	inputFile = fopen("addin.txt","r");
	outputFile  = fopen("addout.txt","w");
	fscanf(inputFile,"%d %d",&first,&second);
	total = first + second;
	fprintf(outputFile, "%d", total);
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}