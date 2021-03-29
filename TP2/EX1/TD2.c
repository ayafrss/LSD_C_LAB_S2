#include <stdio.h>
#include <stdlib.h>
struct tpoint
{
	int x ;
	int y;
};
typedef struct tpoint point;

void saisie(point *p)
{ 
	scanf("%d%d",&p->x ,&p->y);
}
char** array(point p)
{
	int i , j ;
	char **arr;
	arr=(char**)malloc(p.x*sizeof(char*));
	for (i=0 ; i<p.x ; i++)
	{
		arr[i]=(char*)malloc(p.y*sizeof(char));
	}
	return arr;
	
}
void rmpl(point p , char**arr)
{
	int i, j;
	for(i=0; i<p.x ;i++)
	{
		for(j=0 ; j<p.y ; j++)
		{
			scanf(" %c",&arr[i][j] );
		}
	}
} 

void printarray(point p , char**arr)
{	int j,i ;
	for(i=0 ;i<p.x ; i++)
	{  
		printf("\n");
		for(j=0 ; j<p.y ;j++)
		{
			printf("%c",arr[i][j]);
		} 
	}
	printf("\n");
}
void flood_fill(char**arr,point q , point p, char new,char old)
{
	if(q.x >= 0 && q.x <p.x && q.y < p.y && q.y >= 0 && arr[q.x][q.y] != new)
	{
		if(arr[q.x][q.y] == old)
		{
			arr[q.x][q.y] = new;
			flood_fill(arr, (point){q.x + 1, q.y}, p, new, old);
			flood_fill(arr, (point){q.x - 1, q.y}, p, new, old);
			flood_fill(arr, (point){q.x, q.y + 1}, p, new, old);
			flood_fill(arr, (point){q.x, q.y - 1}, p, new, old);
		}
	}
}

int main()
{
	point p;
	int i , j;
	char **arr;
	char a;
	printf("entrer x et y \n");
	saisie(&p);
	printf("(%d , %d)\n", p.x,p.y);
	arr=array(p);
	printf("entrer les valeurs\n");
	rmpl(p,arr);
	printarray(p,arr);
	point q;
	printf("entrer x et y du point q \n");
	saisie(&q);
	printf("(%d , %d)\n",q.x,q.y);
	printf("entrer le nouveau caractère : \n");
	scanf(" %c", &a);
	flood_fill(arr,q,p,a,arr[q.x][q.y]);
	printarray(p,arr);
	return 0 ;
}
