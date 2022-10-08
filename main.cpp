#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include <fstream>
#include "tsp.h"
#include <time.h>
#include <math.h>
using namespace std;
int noOfCities;
double **dist_matrix = NULL;
double **cordinate = NULL;
/**
 * Purpose :To compute euclidean distance between cities
 * Input Arguments: Coordinates of two cities-x1,y1 and x2,y2
 * Return : Distance computed
**/
double distance(double x1,double y1, double x2,double y2)
{
	double dist;
	dist = sqrt((((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))));
//	dist = abs(x2-x1)+abs(y2-y1);
	return dist;
}
/**
 * Purpose:to find shortest path between two cities using floyd warshall algorithm
 * Input Argument:Original Distance Matrix
 * Output:Distance matrix after finding shortest path
 * */
void noneuc_shortest(double ** dist)
{
	int i,j,k;
	for(k=0;k<noOfCities;k++)
	{
		for(i=0;i<noOfCities;i++)
		{
			for(j=0;j<noOfCities;j++)
			{
				if(dist[i][k]+dist[k][j] <dist[i][j])
					{
					dist[i][j] =dist[i][k] +dist[k][j];
					}
			}
		}
	}
	
}

/**
 * Purpose :To compute the distance matrix
 * Input Arguments:File having city coordinates and distance between every pair of cities
 *
 * **/

void computeDistance()
{
	bool euclidean;
	int i,j,len,pos1,pos2;
	string line,subline;		
	char euc[100];	
	gets(euc);
	///Check whether distance measure is euclidean or non euclidean
	if(euc =="euclidean")
		euclidean = true;
	else
		euclidean = false;
	cin>>noOfCities;
	dist_matrix =new double *[noOfCities];
	for(i=0;i<noOfCities;i++){
		dist_matrix[i] =new double [noOfCities];
	}
	i=0;
	
        while(i<=noOfCities)
        {
		gets(euc);
		i++;
	}
	i=0;
        while(i<noOfCities)
        {
		for(j=0;j<noOfCities;++j)
		{
			cin>>dist_matrix[i][j];
	
		}
		i++;
	}
	
	if(euclidean ==false)
		noneuc_shortest(dist_matrix);
}

int main(int argc, char **argv)
{
	double e1,e2;
	int i;
	char in[100];
	computeDistance();///to calculate distance matrix
	Solution sol(noOfCities,dist_matrix);
	Simulated sim(noOfCities,dist_matrix);
	int *ipath =(int*) malloc(noOfCities);
	ipath=sim.Anneal();///calling simulated annealing
	sim.Display(ipath);///displays best path found so far(5 minutes)
	e2=sol.Evaluate(ipath);
cout<<e2<<"\n";
}
