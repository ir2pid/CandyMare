
#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{

public:

	uint16 array1[5][9];
	uint16 array2[5][9];
	uint16 jigSize;
	//uint16 time;
	uint16 move;
	//uint16 checksum;

    /*uint16 getChecksum() const
    {
        return checksum;
    }

    void setChecksum(uint16 checksum)
    {
    	this->checksum = checksum;
    }

    bool Checksum()
    {
        if(checksum != genChecksum())
        	return false;
        else
        	return true;
    }

    uint16 genChecksum()
    {
    	uint16 check=0;
        for(uint16 i=0;i<5;i++)
        {
        	for(uint16 j=0;j<9;j++)
        	{
        		//check = check+array1[i][j]+array2[i][j];
        	}
        }
       // AppLog("Got checksum: %i",check);
        check = check%37;
        //AppLog("Final checksum: %i",check);

        return check;
    }*/

    /*	String sMusic;
	String sCanvas;*/



    Level()
	{
		//checksum = 0;
		jigSize = 0;
		//time = 0;
		move = 0;

		for(uint16 i=0;i<5;i++)
			for(uint32 j=0;j<9;j++)
				array1[i][j] = 0;

		for(uint16 i=0;i<5;i++)
			for(uint32 j=0;j<9;j++)
				array2[i][j] = 0;

	}

    /*uint16 getTime() const
    {
    	//AppLog("return %i",canvasID);
        return time;
    }*/

    uint16 getMove() const
    {
    	//AppLog("return %i",musicID);
        return move;
    }

    /*void setTime(uint16 time)
    {
        this->time = time;
    }*/

    void setMove(uint move)
    {
        this->move = move;
    }

};

#endif