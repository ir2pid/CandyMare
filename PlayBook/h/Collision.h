#ifndef COLLISION_H
#define COLLISION_H

#include "Tray.h"
#include "../layout/Layout.h"
//#include "Calculations.h"

class Collision
{

public:

	inline void endLevel()
	{
		//tray.genCollisionMap(layout.jigSaw);
		//if((layout.jigSaw[0].row ) == layout.jigSaw[1].row )
		layout.gameLayout->isComplete = true;
	}
	
	inline void writeExpBlock(int id)
	{
		id--;
		if(layout.jigSaw[id].cMatrix[0][0] != 0)
		{
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[0][1]!=0 )
		{
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[0][2]!=0)
		{
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[0][3]!=0)
		{
			tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[1][0]!=0)
		{
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[1][1]!=0)
		{
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[1][2]!=0)
		{
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[1][3]!=0)
		{
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[2][0]!=0)
		{
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[2][1]!=0)
		{
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[2][2]!=0)
		{
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2] = layout.jigSaw[id].id;
		}


		if(layout.jigSaw[id].cMatrix[2][3]!=0)
		{
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[3][0]!=0)
		{
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[3][1]!=0)
		{
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[3][2]!=0)
		{
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2] = layout.jigSaw[id].id;
		}

		if(layout.jigSaw[id].cMatrix[3][3]!=0)
		{
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3] = layout.jigSaw[id].id;
		}
	
	}


	inline void clearExpBlock(int id)
	{

		//cout<<"\n"<<id;
		//cout<<"\n"<<id;
		id--;
		//cout<<"\n"<<id;
		//cout<<"\n"<<id;

		if(layout.jigSaw[id].cMatrix[0][0] != 0)
		{
			if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row] = 0;//layout.jigSaw[id].cMatrix[0][0];
			}
		}
		//tray.showExpTouchMatrix();

		if(layout.jigSaw[id].cMatrix[0][1]!=0 )
		{
			if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1] = 0;//layout.jigSaw[id].cMatrix[1][0];
			}
		}
		
		//tray.showExpTouchMatrix();

		if(layout.jigSaw[id].cMatrix[0][2]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] = 0;//layout.jigSaw[id].cMatrix[2][0];
			}
		}

		if(layout.jigSaw[id].cMatrix[0][3]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3] = 0;//layout.jigSaw[id].cMatrix[2][0];
			}
		}

		if(layout.jigSaw[id].cMatrix[1][0]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] = 0;//layout.jigSaw[id].cMatrix[0][1];
			}
		}

		if(layout.jigSaw[id].cMatrix[1][1]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] = 0;//layout.jigSaw[id].cMatrix[1][1];
			}
		}

		if(layout.jigSaw[id].cMatrix[1][2]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2] = 0;//layout.jigSaw[id].cMatrix[2][1];
			}
		}

		if(layout.jigSaw[id].cMatrix[1][3]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3] = 0;//layout.jigSaw[id].cMatrix[2][1];
			}
		}

		if(layout.jigSaw[id].cMatrix[2][0]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row] = 0;//layout.jigSaw[id].cMatrix[0][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[2][1]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1] = 0;//layout.jigSaw[id].cMatrix[1][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[2][2]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2] = 0;//layout.jigSaw[id].cMatrix[2][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[2][3]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3] = 0;//layout.jigSaw[id].cMatrix[2][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[3][0]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row] = 0;//layout.jigSaw[id].cMatrix[0][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[3][1]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1] = 0;//layout.jigSaw[id].cMatrix[1][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[3][2]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2] = 0;//layout.jigSaw[id].cMatrix[2][2];
			}
		}

		if(layout.jigSaw[id].cMatrix[3][3]!=0)
		{
			if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]==layout.jigSaw[id].id)
			{
				//AppLog("hit");
				tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3] = 0;//layout.jigSaw[id].cMatrix[2][2];
			}
		}
	}

	bool checkCollisionEdit(int id,int side)
	{//1.right/2.left/3.up/4.down
		id--;

		
		if(side == 2)
		{

			if(layout.jigSaw[id].row == 0)
				return true;
			else 
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
							
						//if(layout.jigSaw[id].getCode() == 3 || tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1] == )
						if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1] == 2)
						{
							if((layout.jigSaw[0].row - 1) == layout.jigSaw[1].row )
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring"<<layout.jigSaw[0].row<<"and"<<layout.jigSaw[1].row;
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						/*if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row] == 1)
						{
						}
						else*/
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}		
		if(side == 1)
		{
			if(layout.jigSaw[id].row+layout.jigSaw[id].getN() == 9)
				return true;
			else
			{
				

				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
						
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{	
						if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] == 2)
						{
							if((layout.jigSaw[0].row+1) == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
							//	//cout<<"\n ignoring";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		if(side == 3)
		{
			if(layout.jigSaw[id].column == 0)
				return true;
			else
			{
				
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						if(id == 0 && tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1] == 2)
						{
							if(layout.jigSaw[0].row == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		if(side == 4)
		{
			if(layout.jigSaw[id].column +layout.jigSaw[id].getM() == 5)
				return true;
			else
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
						if(id == 0 && tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] == 2)
						{
							if(layout.jigSaw[0].row == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						if(id == 0 && tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] == 2)
						{
							//cout<<"\n ignoring";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{		
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{		
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		return false;
	}


	//edit_exp

	
	bool checkCollision(int id,int side)
	{//1.right/2.left/3.up/4.down
		id--;

		
		if(side == 2)
		{

			if(layout.jigSaw[id].row == 0)
				return true;
			else 
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1] == 2)
						{
							if((layout.jigSaw[0].row - 1) == layout.jigSaw[1].row )
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring"<<layout.jigSaw[0].row<<"and"<<layout.jigSaw[1].row;
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						/*if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row] == 1)
						{
						}
						else*/
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row-1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}		
		if(side == 1)
		{
			if(layout.jigSaw[id].row+layout.jigSaw[id].getN() == 9)
				return true;
			else
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
						
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{	
						if(id == 0 && tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] == 2)
						{
							if((layout.jigSaw[0].row+1) == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring";
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+4]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		if(side == 3)
		{
			if(layout.jigSaw[id].column == 0)
				return true;
			else
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
						if(id == 0 && tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row] == 2)
						{
							if(layout.jigSaw[0].row == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring";
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						if(id == 0 && tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1] == 2)
						{
							
								//cout<<"\n ignoring";
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		if(side == 4)
		{
			if(layout.jigSaw[id].column +layout.jigSaw[id].getM() == 5)
				return true;
			else
			{
				
				if(layout.jigSaw[id].cMatrix[0][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
							////cout<<"\n"<<tray.tray[layout.jigSaw[id].column-1][layout.jigSaw[id].row]<<" "<<layout.jigSaw[id].column-1<<" "<<layout.jigSaw[id].row;
						if(id == 0 && tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] == 2)
						{
							if(layout.jigSaw[0].row == layout.jigSaw[1].row)
							{
								endLevel();
								return false;
							}
							//else
								//cout<<"\n ignoring";
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						if(id == 0 && tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] == 2)
						{
							//cout<<"\n ignoring";
						}
						else if(id == 0 && layout.gameLayout->gObj.portals.size()>0 && (tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] == layout.gameLayout->gObj.portals[2].x || tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1] == layout.gameLayout->gObj.portals[2].y))
						{
							//cout<<"\n ignoring with portal";
						}
						else
							return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{		
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[0][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{		
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+1][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////
				if(layout.jigSaw[id].cMatrix[1][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[1][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+2][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[2][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[2][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+3][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}

				///////////////////////////////////////////////////////

				if(layout.jigSaw[id].cMatrix[3][0]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][1]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+1]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][2]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+2]=layout.jigSaw[id].id;
					}
				}
				if(layout.jigSaw[id].cMatrix[3][3]!=0)
				{
					if(tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]!=0&&tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]!=layout.jigSaw[id].id)
					{
						return true;
					}
					else
					{
							tray.tray[layout.jigSaw[id].column+4][layout.jigSaw[id].row+3]=layout.jigSaw[id].id;
					}
				}
				return false;
			}
		}
		return false;
	}

}collision;

#endif