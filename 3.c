#include <stdio.h>    
     
int main()    
{    
     int n;
    printf("Enter an size of Array then elements: ");
    scanf("%d", &n);  
    int arr[n];
    for(int i=0;i<n;i++){
       int x;
       scanf("%d", &x);
       arr[i]=x; 
    }
        
        
    //Searches for duplicate element  
    int dup[n];
    int x=0;
    for(int i = 0; i < n; i++) {    
        for(int j = i + 1; j < n; j++) {    
            if(arr[i] == arr[j])    
            {
               dup[x]=arr[i];    
               x++;
            }
        }    
    }    
    
    printf("Duplicate elements in given array: \n");
    for(int i=0;i<x;i++){
       printf("%d ", dup[i]);
    }
    return 0;    
}  