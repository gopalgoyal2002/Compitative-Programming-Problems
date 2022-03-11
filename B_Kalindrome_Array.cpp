#include<cstdio>
int _,n,i,l,r,a[200001];
int check(int x){
	int l=1,r=n,f=1;
	while(l<=r&&f){
		f=0;
		if(a[l]==x)l++,f=1;
		if(a[r]==x)r--,f=1;
		if(a[l]==a[r])l++,r--,f=1;
	}
	return l>r;
}
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		l=1;r=n;
		while(l<=r&&a[l]==a[r])l++,r--;
		if(l>r){puts("YES");continue;}
		if(check(a[l])||check(a[r])){puts("YES");continue;}
		puts("NO");
	}
}