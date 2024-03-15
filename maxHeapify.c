// MAX-HEAPIFY ALGORITHM

#include<stdio.h>

void show(int x[],int n,int i){
	
	int l=i*2+1;
	int r=i*2+2;
	int max=i;
	
	if(r<n){
		if(x[l]>x[r]){
			max=l;
		}
		else{
			max=r;
		}
	}
	else if(l<n){
		max=l;
	}
	
	if(x[max]>x[i]){
		int temp=x[i];
		x[i]=x[max];
		x[max]=temp;
		
		show(x,n,max);
	}
	
}

void showloop(int x[],int n){
	for(int i=n/2-1;i>=0;i--){
		show(x,n,i);
	}
}

void main()
{
	int x[]={1,2,3,4,5,6,7,8,9,10};
	showloop(x,10);
	
	for(int i=0;i<10;i++){
		printf("%d ",i[x]);
	}
}


