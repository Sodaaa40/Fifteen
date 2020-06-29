#pragma once

class game{
private:
	int field[16];
	int swapmove(int a, int b) {
		if(check(a,b) == 1){
			swap(a, b);
			return 0;
		}else{
			return 1;
		}
	}
	void swap(int a, int b) {
	int temp = field[b];
	field[b] = field[a];
	field[a] = temp;
	}
	int check(int space, int num) {
	if(((space - 1) >= 0) && (field[space-1] == field[num]) && (space%4 != 0)) return 1;
	if(((space + 1) <= 15) && (field[space+1] == field[num]) && (space%4 != 3)) return 1;
	if(((space - 4) >= 0) && (field[space-4] == field[num])) return 1;
	if(((space + 4) <= 15) && (field[space+4] == field[num])) return 1;	
	return 0;
}
public:
	int move(int num){
	int pos;
	int pos1;

	for(int i = 0; i<16; i++) {
		if(field[i] == 16) {
			pos = i;
		}	
		if(field[i] ==num)
			pos1 = i;
	}
	if(check(pos,pos1) == 1) {
		swap(pos,pos1);
		return 0;
	} else {
	return 1;
	}
}
	game(){
		for(int i = 0; i < 16; i++){
			field[i] = i + 1;
		}
	}

	int getFieldCell(int x, int y) {
		return field[4 * y + x]; 
	}	
	int checkWin() {
	int flag = 1;
	for(int i = 0; i<16; i++) {
		if(field[i] != ( i + 1)) flag = 0;
	}	
	if(flag == 1) {
		return 0;
	} else {
		return 1;
	}
	}

	void shuffle() {
	int n;
	srand(time(NULL));
	int spacepos = 15;
	for(int i = 0; i<100; i++) {
		n = rand()%4;
		if( n == 0){
				if(swapmove(spacepos, spacepos-1) ==0)
				spacepos=spacepos-1;
		}	
		if( n ==1){
				if(swapmove(spacepos, spacepos-4) ==0)
				spacepos = spacepos-4;
		}
		if( n ==2){
				if(swapmove(spacepos, spacepos+1) ==0)
				spacepos= spacepos  + 1;
	}	
		if( n ==3){
		
				if(swapmove(spacepos, spacepos+4) == 0)
				spacepos = spacepos+4;
		}
	}
}
};