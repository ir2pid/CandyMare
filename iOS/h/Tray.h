#ifndef TRAY_H
#define TRAY_H

#include "util.h"
#include "Jigsaw.h"

class Tray{

	int blocki[10];
	int blockj[6];

public:

	
	//int blockSize;
	int tray[5][9];

	void construct(int blockSize,int anchorx,int anchory)
	{
		
		for(int i=0;i<10;i++)
		{
			blocki[i] = anchorx+(i*blockSize);
		}

		for(int i=0;i<6;i++)
		{
			blockj[i] = anchory+(i*blockSize);
		}


		//for(int i=0;i<10;i++)
			//cout<<"\ntray blocki "<<blocki[i];
		//for(int i=0;i<6;i++)
			//cout<<"\ntray blockj "<<blockj[i];
	}

	int getBlockID(int x,int y)
	{
		//cout<<"\n\nreturning id j:"<<getBlockj(y)<<" i:"<<getBlocki(x)<<" tray:"<<tray[getBlockj(y)][getBlocki(x)];		
		return tray[getBlockj(y)][getBlocki(x)];
	}
	inline int getBlocki(int x)//returns i of i,j/x,y returns 0-9 null is 255
	{

		if(x>=0 && x<=blocki[1])
			return 0;
		else if(x<=blocki[2] && x>blocki[1] )
			return 1;
		else if(x<=blocki[3] && x>blocki[2])
			return 2;
		else if(x<=blocki[4] && x>blocki[3])
			return 3;
		else if(x<=blocki[5] && x>blocki[4])
			return 4;
		else if(x<=blocki[6] && x>blocki[5])
			return 5;
		else if(x<=blocki[7] && x>blocki[6])
			return 6;
		else if(x<=blocki[8] && x>blocki[7])
			return 7;
		else if(x<=blocki[9] && x>blocki[8])
			return 8;
		else
			return 8;
	}

	inline int getBlockj(int y)//returns j of i,j/x,y returns 0-4 null is 255
	{
		if(y>=0 && y<=blockj[1])
			return 0;
		else if(y<=blockj[2] && y>=blockj[1])
			return 1;
		else if(y<=blockj[3] && y>=blockj[2])
			return 2;
		else if(y<=blockj[4] && y>=blockj[3])
			return 3;
		else if(y<=blockj[5] && y>=blockj[4])
			return 4;
		else
			return 4;
	}

	int getCordx(int i) //returns x axis of block i
	{
		if(i == 0)
		{
			return blocki[0];
		}
		else if(i == 1)
		{
			return blocki[1];
		}
		else if(i == 2)
		{
			return blocki[2];
		}
		else if(i == 3)
		{
			return blocki[3];
		}
		else if(i == 4)
		{
			return blocki[4];
		}
		else if(i == 5)
		{
			return blocki[5];
		}
		else if(i == 6)
		{
			return blocki[6];
		}
		else if(i == 7)
		{
			return blocki[7];
		}
		else if(i == 8)
		{
			return blocki[8];
		}
		/*else if(i == 9)
		{
			return 778;
		}*/
		else
			return 0;
	}

	int getCordy(int j) //returns y axis of block j
	{
		if(j == 0)
		{
			return blockj[0]-2;
		}
		else if(j == 1)
		{
			return blockj[1]-2;
		}
		else if(j == 2)
		{
			return blockj[2]-2;
		}
		else if(j == 3)
		{
			return blockj[3]-2;
		}
		else if(j == 4)
		{
			return blockj[4]-2;
		}
		else
			return 0;

	}

	void refreshTouchMatix(int val)
	{

		tray[0][0] = val;
		tray[0][1] = val;
		tray[0][2] = val;
		tray[0][3] = val;
		tray[0][4] = val;
		tray[0][5] = val;
		tray[0][6] = val;
		tray[0][7] = val;
		tray[0][8] = val;

		tray[1][0] = val;
		tray[1][1] = val;
		tray[1][2] = val;
		tray[1][3] = val;
		tray[1][4] = val;
		tray[1][5] = val;
		tray[1][6] = val;
		tray[1][7] = val;
		tray[1][8] = val;

		tray[2][0] = val;
		tray[2][1] = val;
		tray[2][2] = val;
		tray[2][3] = val;
		tray[2][4] = val;
		tray[2][5] = val;
		tray[2][6] = val;
		tray[2][7] = val;
		tray[2][8] = val;

		tray[3][0] = val;
		tray[3][1] = val;
		tray[3][2] = val;
		tray[3][3] = val;
		tray[3][4] = val;
		tray[3][5] = val;
		tray[3][6] = val;
		tray[3][7] = val;
		tray[3][8] = val;

		tray[4][0] = val;
		tray[4][1] = val;
		tray[4][2] = val;
		tray[4][3] = val;
		tray[4][4] = val;
		tray[4][5] = val;
		tray[4][6] = val;
		tray[4][7] = val;
		tray[4][8] = val;
	}

	
	inline void genCollisionMap(CIwArray<Jigsaw> &jigSaw)
	{
		refreshTouchMatix(0);

		IW_ARRAY_ITERATE(Jigsaw, it, jigSaw)
		{
		//it->render(tray.getCordx(it->row),tray.getCordy(it->column));
			int id = it->id;

			if(it->cMatrix[0][0] != 0)
			{

				if(tray[it->column][it->row]==0)
				{
					tray[it->column][it->row] = id;//it->cMatrix[0][0];
				}
			}

			if(it->cMatrix[0][1]!=0 )
			{
				if(tray[it->column][it->row+1]==0)
				{
					tray[it->column][it->row+1] = id;//it->cMatrix[1][0];
				}
			}

			if(it->cMatrix[0][2]!=0)
			{
				if(tray[it->column][it->row+2]==0)
				{
					tray[it->column][it->row+2] = id;//it->cMatrix[2][0];
				}
			}

			if(it->cMatrix[0][3]!=0)
			{
				if(tray[it->column][it->row+3]==0)
				{
					tray[it->column][it->row+3] = id;//it->cMatrix[2][0];
				}
			}


			if(it->cMatrix[1][0]!=0)
			{
				if(tray[it->column+1][it->row]==0)
				{
					tray[it->column+1][it->row] = id;//it->cMatrix[0][1];
				}
			}


			if(it->cMatrix[1][1]!=0)
			{
				if(tray[it->column+1][it->row+1]==0)
				{
					tray[it->column+1][it->row+1] = id;//it->cMatrix[1][1];
				}
			}


			if(it->cMatrix[1][2]!=0)
			{
				if(tray[it->column+1][it->row+2]==0)
				{
					tray[it->column+1][it->row+2] = id;//it->cMatrix[2][1];
				}
			}


			if(it->cMatrix[1][3]!=0)
			{
				if(tray[it->column+1][it->row+3]==0)
				{
					tray[it->column+1][it->row+3] = id;//it->cMatrix[2][1];
				}
			}





			if(it->cMatrix[2][0]!=0)
			{
				if(tray[it->column+2][it->row]==0)
				{
					tray[it->column+2][it->row] = id;//it->cMatrix[0][2];
				}
			}


			if(it->cMatrix[2][1]!=0)
			{
				if(tray[it->column+2][it->row+1]==0)
				{
					tray[it->column+2][it->row+1] = id;//it->cMatrix[1][2];
				}
			}


			if(it->cMatrix[2][2]!=0)
			{
				if(tray[it->column+2][it->row+2]==0)
				{
					tray[it->column+2][it->row+2] = id;//it->cMatrix[2][2];
				}
			}


			if(it->cMatrix[2][3]!=0)
			{
				if(tray[it->column+2][it->row+3]==0)
				{
					tray[it->column+2][it->row+3] = id;//it->cMatrix[2][2];
				}
			}




			if(it->cMatrix[3][0]!=0)
			{
				if(tray[it->column+3][it->row]==0)
				{
					tray[it->column+3][it->row] = id;//it->cMatrix[0][2];
				}
			}


			if(it->cMatrix[3][1]!=0)
			{
				if(tray[it->column+3][it->row+1]==0)
				{
					tray[it->column+3][it->row+1] = id;//it->cMatrix[1][2];
				}
			}


			if(it->cMatrix[3][2]!=0)
			{
				if(tray[it->column+3][it->row+2]==0)
				{
					tray[it->column+3][it->row+2] = id;//it->cMatrix[2][2];
				}
			}


			if(it->cMatrix[3][3]!=0)
			{
				if(tray[it->column+3][it->row+3]==0)
				{
					tray[it->column+3][it->row+3] = id;//it->cMatrix[2][2];
				}
			}
			
		}//for
		//showExpTouchMatrix();
	}

	//void showExpTouchMatrix()
/*	{
		//cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
		for(int i=0;i<5;i++)
		{
			//cout<<"\n<<<<<<<<<<<"<<i<<"- ";
			for(int j=0;j<9;j++)
			{
				//cout<<tray[i][j]<<"|";
			}
		}
		//cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	}*/


}tray;

#endif