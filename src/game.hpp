#pragma once

class game{
private:
	int field[16];
public:
	game(){
		for(int i = 0; i < 16; i++){
			field[i] = i;
		}
	}

	int getFieldCell(int x, int y){ return field[4 * y + x]}	
};