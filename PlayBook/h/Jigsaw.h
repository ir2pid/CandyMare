
#ifndef JIGSAW_H_
#define JIGSAW_H_

using namespace std;

class Jigsaw
{
	CIw2DImage *img;



public:
	int m; //height
	int n; //width

	int row;	//9 (n)
	int column;	//5 (m)
	int code;
	int id;
	//int delta_x;
	//int delta_y;
	bool isMovable;
	bool up;
	bool down;
	bool left;
	bool right;

	int cMatrix[4][4];

	~Jigsaw()
	{
    	
	}

	void clearCollisions()
	{
		up = false;
		down = false;
		left = false;
		right = false;
	}

	inline void construct(int code, int c, int r, int touchkey,bool editable) //,int c,int r,bool movable,Bitmap *bitmap,int id)
	{
		this->code = code;
		this->id = touchkey;
		this->column = c;
		this->row = r;

		up = false;
		down = false;
		left = false;
		right = false;

		img = NULL;

		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++)
				cMatrix[i][j] = 0;
		}
		switch(code)
		{

		//mexico
			case 3:
			{//hero
				setM(1);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				break;
			}

			case 4:
			{//destination
				setM(1);
				setN(2);
				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);


				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;

				break;
			}
			case 5:
			{
				setM(1);
				setN(1);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 6:
			{
				setM(1);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				break;
			}
			case 7:
			{
				setM(2);
				setN(1);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				break;
			}
			case 8:
			{
				setM(1);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				break;
			}
			case 9:
			{
				setM(3);
				setN(1);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[2][0] = 1;
				break;
			}
			case 10:
			{
				setM(1);
				setN(4);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				cMatrix[0][3] = 1;
				break;
			}
			case 11:
			{
				setM(4);
				setN(1);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[2][0] = 1;
				cMatrix[3][0] = 1;
				break;
			}
			case 12:
			{
				setM(2);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				break;
			}
			case 13:
			{
				setM(2);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				break;
			}
			case 14:
			{
				setM(2);
				setN(3);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				break;
			}
			case 15:
			{
				setM(3);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][1] = 1;
				break;
			}
			case 16:
			{
				setM(3);
				setN(2);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][0] = 1;
				cMatrix[2][0] = 1;
				break;
			}
			case 17:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				cMatrix[2][2] = 1;
				break;
			}
			case 18:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][1] = 1;
				cMatrix[2][2] = 1;
				break;
			}
			case 19:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][0] = 1;
				break;
			}
			case 20:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][2] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				cMatrix[2][0] = 1;
				cMatrix[2][1] = 1;
				break;
			}
			case 21:
			{
				setM(2);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][0] = 1;
				break;
			}
			case 22:
			{
				setM(2);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][1] = 1;
				break;
			}
			case 23:
			{
				setM(2);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				break;
			}
			case 24:
			{
				setM(2);
				setN(2);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				break;
			}

			case 25:
			{
				setM(2);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				cMatrix[1][1] = 1;
				break;
			}
			case 26:
			{
				setM(3);
				setN(2);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][0] = 1;
				break;
			}
			case 27:
			{
				setM(3);
				setN(2);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][1] = 1;
				break;
			}
			case 28:
			{
				setM(2);
				setN(3);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				break;
			}
			case 29:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][2] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				cMatrix[2][0] = 1;
				break;
			}
			case 30:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[1][0] = 1;
				cMatrix[1][1] = 1;
				cMatrix[1][2] = 1;
				cMatrix[2][2] = 1;
				break;
			}
			case 31:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][1] = 1;
				cMatrix[0][2] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][0] = 1;
				cMatrix[2][1] = 1;
				break;
			}
			case 32:
			{
				setM(3);
				setN(3);
				setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				cMatrix[1][1] = 1;
				cMatrix[2][1] = 1;
				cMatrix[2][2] = 1;
				break;
			}
			case 33:
			{
				//transparent wall
				setM(1);
				setN(1);
				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 34:
			{
				//star
				setM(1);
				setN(1);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 35:
			{
				//star
				setM(1);
				setN(1);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 36:
			{
				//star
				setM(1);
				setN(1);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 37:
			{
				//shroom evil
				setM(1);
				setN(1);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 38:
			{
				//shroom good
				setM(1);
				setN(1);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				break;
			}
			case 39:
			{
				//portal green
				setM(1);
				setN(2);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				break;
			}
			case 40:
			{
				//portal red
				setM(1);
				setN(2);

				if(!editable)
					setIsMovable(false);
				else
					setIsMovable(true);

				cMatrix[0][0] = 1;
				cMatrix[0][1] = 1;
				break;
			}
			default:
			{
				//cout<<"Unknown block id";
			}

		}
	}


	inline int getColumn() const
	{
		////cout<<"\ncolumn "<<column;
		return column;
	}

	inline bool setColumn(int column)
	{
		int t = getM();
		if((column >= 0) && (column + t - 1 <= 4))
		{
    		this->column = column;
    		return true;
		}
		else
		{
    		return false;
		}

	}
	
	inline bool addColumn()
	{
		int t = getM();
		if(column + t <= 4)
		{
    		if(isMovable)
			{	
				column++;
    			return true;
			}
		}
		else
		{
    		return false;
		}

	}
	inline bool subColumn()
	{
		if((column > 0))
		{
    		if(isMovable)
			{	
				column--;
    			return true;
			}
		}
		else
		{
    		return false;
		}

	}

	inline bool setRow(int row)
	{
		int t = getN();
		if((row >= 0) && (row+t-1 <= 8))
		{
			this->row = row;
			return true;
		}
		else
		{
			return false;
		}

	}

	inline bool addRow()
	{
		int t = getN();
		if((row+t <= 8))
		{
			if(isMovable)
			{	
				row++;
				return true;
			}
		}
		else
		{
			return false;
		}

	}

	inline bool subRow()
	{
		if((row > 0))
		{
			if(isMovable)
			{	
				row--;
				return true;
			}
		}
		else
		{
			return false;
		}

	}
	inline CIw2DImage *getImg() const
	{
		return img;
	}

	inline int getRow() const
	{
		////cout<<"\nrow "<<row;
		return row;
	}

	inline int getCode() const
	{
		return code;
	}

	inline void setCode(int code)
	{
		this->code = code;
	}

	inline int getId() const
	{
		return id;
	}

	inline void setId(int id)
	{
		this->id = id;
	}


	inline int getM() const
	{
		return m;
	}

	inline int getN() const
	{
		return n;
	}

	inline void setM(int m)
	{
		this->m = m;
	}

	inline void setN(int n)
	{
		this->n = n;
	}
	inline bool getIsMovable() const
	{
		return isMovable;
	}

	inline void setIsMovable(bool isMovable)
	{
		this->isMovable = isMovable;
	}

	inline void setImg(CIw2DImage *img)
	{
		this->img = img;
	}

	void renderAll(int x,int y)
	{
		/*if(code == 33)
			return;
		else  */
			Iw2DDrawImage(img,CIwSVec2(x,y));
	}
	void render(int x,int y)
	{
		//if(code == 33)
		//	return;
		//else  
			Iw2DDrawImage(img,CIwSVec2(x,y));
	}
	void render(int x,int y,CIwSVec2 regionOffset,CIwSVec2 regionSize)
	{	
		Iw2DDrawImageRegion(img,CIwSVec2(x,y),regionOffset,regionSize);
	}



	void resetDelta()
	{

	}

};	


#endif /* JIGSAW_H_ */