#include<iostream>
#include <stdlib.h>

class Solution
{
	public:
	int no;
	double** dist_matrix;
	Solution(int n,double** dist){
		no =n;
		dist_matrix =dist;
	}

	int* Initialize();
	double Evaluate(int *);
	int* twooptswap(int *tour,int *copy);
	int* randomgen(int *tour);

	
};
class Simulated
{
   public:
	int no;
	double** dist_matrix;
	Simulated(int n,double** dist){
		no =n;
		dist_matrix =dist;
	}
	double cooling(int index, int flag,double initialTemp,double finalTemp,int numTemp);
	int* Anneal() ;
	void Display(int*);
	void Copy(int* tour1,int* tour2);

};
