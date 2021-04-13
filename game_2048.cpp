#include<iostream>
#include<stdio.h>
#include<ctime>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

const int size = 4;
const int num = 2;
int plot[size][size];
int score;


void init() {
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			plot[i][j] = 0;
	score = 0;
}

void displayPlot() {
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			cout<<plot[i][j]<<"\t";
		}
		if(i==0)
			cout<<"\t\t SCORE: "<<score;
		cout<<"\n";
	}
}

void random(int nZero[], int z) {
	int x,y;
	int s;
	int n = size;
	
	s = rand() % z;
	x = nZero[s] / n;
	y = nZero[s] % n;
	
	plot[x][y] = num;
}

int processGamePlot(char direction)
{
	int similarVal[size];
	int count;
	int change;
	int i, j;
	switch(tolower(direction))
	{
		case 'w' :
			for(j=0;j<size;j++)
			{
				count = 0;
				change = -1;
				for(i=0;i<size;i++)	
				{
					if(plot[i][j] != 0) 
						similarVal[count++] = plot[i][j];
					if(count > 1) {
						if((similarVal[count-1] == similarVal[count - 2]) && ((count-1) != change)){
							similarVal[count - 2] = similarVal[count - 2] + similarVal[count-1];
							score += similarVal[count - 2];
							count--;
							change = count-1;
						}
					}
				}
				for(i=0;i<size;i++) {
					if(i < count) 
						plot[i][j] = similarVal[i];
					else
						plot[i][j] = 0;
				}
			}
			break;
		case 'a' :
			for(i=0;i<size;i++)
			{
				count = 0;
				change = -1;
				for(j=0;j<size;j++)	
				{
					if(plot[i][j] != 0) 
						similarVal[count++] = plot[i][j];
					if(count > 1) {
						if((similarVal[count-1] == similarVal[count - 2]) && ((count-1) != change)){
							similarVal[count - 2] = similarVal[count - 2] + similarVal[count-1];
							score += similarVal[count - 2];
							change = count-1;
							count--;
						}
					}
				}
				for(j=0;j<size;j++) {
					if(j < count) 
						plot[i][j] = similarVal[j];
					else
						plot[i][j] = 0;
				}
			}
			break;
		case 's' :
			for(j=0;j<size;j++)
			{
				count = 0;
				change = -1;
				for(i=size-1;i>=0;i--)	
				{
					if(plot[i][j] != 0) 
						similarVal[count++] = plot[i][j];
					if(count > 1) {
						if((similarVal[count-1] == similarVal[count - 2]) && ((count-1) != change)){
							similarVal[count - 2] = similarVal[count - 2] + similarVal[count-1];
							score += similarVal[count - 2];
							count--;
							change = count-1;
						}
					}
				}
				for(i=size-1;i>=0;i--) {
					if(i > size - 1 - count) 
						plot[i][j] = similarVal[size - i - 1];
					else
						plot[i][j] = 0;
				}
			}
			break;
		case 'd' :
			for(i=0;i<size;i++)
			{
				count = 0;
				change = -1;
				for(j=size-1;j>=0;j--)	
				{
					if(plot[i][j] != 0) 
						similarVal[count++] = plot[i][j];
					if(count > 1) {
						if((similarVal[count-1] == similarVal[count - 2]) && ((count-1) != change)){
							similarVal[count - 2] = similarVal[count - 2] + similarVal[count-1];
							score += similarVal[count - 2];
							change = count-1;
							count--;
						}
					}
				}
				for(j=size-1;j>=0;j--) {
					if(j > size - 1 - count) 
						plot[i][j] = similarVal[size - j - 1];
					else
						plot[i][j] = 0;
				}
			}
			break;
		default :
			cout<<"\nInvalid Move Please TRY AGAIN!\n";
			return -1;
	}
	score += 1;
	return 1;
}

int main()
{
	srand(time(0));
	bool isOver = false;
	int flag;
	char direction;
	cout<<size<<"X"<<size<<" PLOT 2048 GAME Design!\n\n";
	init();
	int i,j;
	int correct = 1;
	int nZero[size*size], z;
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			if(plot[i][j]==0)
				nZero[z++] = i*size + j;
		}
	}
	do{
		if(correct == 1)
			random(nZero, z);
		displayPlot();
		cout<<"\nEnter Direction W, A, S, D, [Q: quit]: ";
		direction = getche();
		correct = processGamePlot(direction);
		cout<<"\n";
		z = 0;
		for(i=0;i<size;i++) {
			for(j=0;j<size;j++) {
				if(plot[i][j]==0)
					nZero[z++] = i*size + j;
			}
		}
		if(z==0)
			isOver = true;
	}while((!isOver) && (tolower(direction) != 'q'));
	if(direction=='q'||direction=='Q')
		cout<<"\n\n\t\t\tGame Terminated by user!\n";
	else
		cout<<"\n\n\t\t\tGame Over\n";
		cout<<"\t\t\tSCORE: "<<score<<"\n";
	return 0;	
	
}
