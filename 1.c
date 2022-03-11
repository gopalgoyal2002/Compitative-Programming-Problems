#include <stdio.h>
#include <string.h>
int main() {
      int n;
    printf("Enter an size of Array then elements: ");
    scanf("%d", &n);
    // max is max size of string  
    int max=1000;
    char *names[n];
    char *judge1[n];
    char *judge2[n];
    char *judge3[n];


    for(int i=0;i<n;i++)
    {
        printf(" Enter a name: ");
        scanf("%s", &names[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf(" Enter a name: ");
        scanf("%s", &judge1[i]);
    }for(int i=0;i<n;i++)
    {
        printf(" Enter a name: ");
        scanf("%s", &judge2[i]);
    }for(int i=0;i<n;i++)
    {
        printf(" Enter a name: ");
        scanf("%s", &judge3[i]);
    }
    float marks[n];
    for(int i=0;i<n;i++){
        marks[i]=0.0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(names[j]==judge1[i]){
                float x=i+1;
                

                marks[j]+=1.0/(x);
            }
        }
    }
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(names[j]==judge1[i]){
                
                float x=i+1;
                

                marks[j]+=1.0/(x);
            }
        }
    }   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(names[j]==judge2[i]){
                 float x=i+1;
                

                marks[j]+=1.0/(x);
            }
        }
    }
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(names[j]==judge3[i]){
                 float x=i+1;
                

                marks[j]+=1.0/(x);
            }
        }
    }
    for(int i=0;i<n;i++){
          printf("%.6f", marks[i]);
          printf("\n");
    }
    
    return 0;
}