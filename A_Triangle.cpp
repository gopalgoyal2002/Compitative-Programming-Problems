#include <stdio.h>
#include <stdlib.h>
int point[6];
int pow2(int n) {
	return n*n;
}
void Isright(char s[]) {
	int a,b,c;
	a=pow2(point[0]-point[2])+pow2(point[1]-point[3]);
	b=pow2(point[0]-point[4])+pow2(point[1]-point[5]);
	c=pow2(point[2]-point[4])+pow2(point[3]-point[5]);
	if ((a&&b&&c)==0) return;
	if (a+b==c||a+c==b||b+c==a) {
		printf("%s",s);
		exit(0);
	}
}
int main() {
	int i;
	for (i=0;i<6;i++) scanf("%d",&point[i]);
	Isright("RIGHT\n");
	for (i=0;i<6;i++) {
	point[i]--;
		Isright("ALMOST\n");
	point[i]+=2;
		Isright("ALMOST\n");
		point[i]--;
	}
	printf("NEITHER\n");
	return 0;
}