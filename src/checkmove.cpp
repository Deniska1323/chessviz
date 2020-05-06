#include <iostream>
#include <stdlib.h>
#include "sp.hpp"
#include "checkmove.hpp"


int checkmove(int b, int b1, int b2, int b3, int b4, char** aa){
	int i, t = 1;
	if (b != 11 && b1 != 11 && b2 != 11 && b3 != 11 && b4 != 11) {
        	    t = 0;
        	    if(aa[b1][b] == aa[b3][b2] || aa[b1][b] == '.'){//то что нельзя
        	    	t = 1;
        	    }
        	    if (b4 == 0){ //justmove
        	    	if(aa[b1][b] == 'p' || aa[b1][b] == 'P'){ //пешки
        	    	//std::cout<<"|";
        	    		if(aa[b1][b] == 'P'){ //team1
        	    		//std::cout<<"|";
        	    			if(b1 == 6){//первый ход
        	    			//std::cout<<"|";
        	    				if(b3 >= b1 - 2 && b3 < b1 && b == b2){ //ход до 2
        	    				//std::cout<<"|";
        	    					if(!(aa[b1 - 1][b] == '.' && aa[b1 - 2][b] == '.')){ //если п-е
        	    					//std::cout<<"|";
        	    						t = 1;
        	    					}
        	    				}
        	    				else {t = 1;}
        	    			}
        	    			else {//не первый ход
        	    				if(b3 >= b1 - 1 && b3 < b1 && b == b2){ //ход до 1
        	    					if(!(aa[b1][b - 1] == '.')){ //если п-е
        	    						t = 1;
        	    					}
        	    				}
        	    				else {t = 1;}
        	    			}  
        	    		}
        	    		else if (aa[b1][b] == 'p'){ //team2
        	    			//std::cout<<"|";
        	    			if(b1 == 1){//первый ход
        	    			//std::cout<<"|";
        	    				if(b3 <= b1 + 2 && b3 > b1 && b == b2){ //ход до 2
        	    				//std::cout<<"|";
        	    					if(!(aa[b1 + 1][b] == '.' && aa[b1 + 2][b] == '.')){ //если п-е
        	    					//std::cout<<"|";
        	    						t = 1;
        	    					}
        	    				}
        	    				else {t = 1;}
        	    			}
        	    			else {//не первый ход
        	    				if(b3 <= b1 + 1 && b3 > b1 && b == b2){ //ход до 1
        	    					if(!(aa[b1][b + 1] == '.')){ //если п-е
        	    						t = 1;
        	    					}
        	    				}
        	    				else {t = 1;}
        	    			}
        	    		}
        	    	}
        	    if(aa[b1][b] == 'r' || aa[b1][b] == 'R'){ //лодья
        	    	if(b == b2){//вертикаль
        	    		//std::cout<<"|";
        	   			if(b1 > b3){ //вперед
        	   				//std::cout<<"|";
        	   				for(i = b1; i > b3; i--){ //вертикаль цыфры (b1 -- b3)
        	   					if(!(aa[i - 1][b] == '.')){ //есть п-е
            						//std::cout <<"-|";
       	    						t = 1;
       	    					}
       	    				}
        	    			if(!(b == b2)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    		if(b1 < b3){ //назад
        	    			//std::cout<<"|";
        	    			for(i = b1; i < b3; i++){ //вертикаль цыфры (b1 -- b3)
        	   					if(!(aa[i + 1][b] == '.')){ //есть п-е
        	   						//std::cout <<"-|";
        	   						t = 1;
        	   					}
            				}
        	    			if(!(b == b2)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    	}
        	    	if(b != b2){ //горизонт
        	    		//std::cout<<"|";
        	   			if(b > b2){ //влево
        	   				//std::cout<<"|";
        	   				for(i = b; i > b2; i--){ //горизонт (b -- b2)
        	   					if(!(aa[b1][i - 1] == '.')){ //есть п-е
            						//std::cout <<"-|";
       	    						t = 1;
       	    					}
       	    				}
        	    			if(!(b1 == b3)){ //проверка горизонт
        	    				t = 1;
        	    			}
        	    		}
        	    		if(b < b2){ //вправо
        	    			//std::cout<<"|";
        	    			for(i = b; i < b2; i++){ //горизонт (b -- b2)
        	   					if(!(aa[b1][i + 1] == '.')){ //есть п-е
        	   						//std::cout <<"-|";
        	   						t = 1;
        	   					}
            				}
        	    			if(!(b1 == b3)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    	} 
        	    } 
        	    if(aa[b1][b] == 'n' || aa[b1][b] == 'N'){//конь
        	    	//Sstd::cout<<"|";
        	    	if(b != b2 && b1 != b3){//проверка вертикали и горизонта
        	    		//std::cout<<"|";
        	    		if(b3 == b1 + 2 || b3 == b1 - 2){ //вертикаль
        	    			//std::cout<<"|";
        	    			if(b2 == b + 1 || b2 == b - 1){ //горизонт
        	    				//std::cout<<"|";
        	    				if(!(aa[b3][b2] == '.')){
        	    					//std::cout<<"j";
        	    					t = 1;
        	    				}
        	    			}
        	    			else{ t = 1; }
        	    		}
        	    		else if(b2 == b + 2 || b2 == b - 2){ //горизонт
        	    			//std::cout<<"+";
        	    			if(b3 == b1 + 1 || b3 == b1 - 1){ //вертикаль
        	    				//std::cout<<"+";
        	    				if(!(aa[b3][b2] == '.')){
        	    					t = 1;
        	    				}
        	    			}
        	    			else{ t = 1; }
        	    		}
        	    		else { t = 1; }
        	    	}
        	    	else { t = 1; }
        	    }
        	    if(aa[b1][b] == 'B' || aa[b1][b] == 'b'){//слон
        	    	//std::cout<<"s";
        	    	if(abs(b1 - b3) == abs(b - b2)){ //ход по диоганали
        	    		//std::cout<<"s";
        	    		for(i = 1; i <= abs(b - b2); i++){
        	    			if(b > b2 && b1 > b3){//лево-верх
        	    				//std::cout<<"slu";
        	   					if(!(aa[b1 - i][b - i] =='.')){
        	   					//std::cout<<"lu";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b > b2 && b1 < b3){//лево-низ
        	   					//std::cout<<"sld";
        	   					if(!(aa[b1 + i][b - i] =='.')){
        	   					//std::cout<<"ld";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b < b2 && b1 < b3){//право-низ
        	   					//std::cout<<"srd";
        	   					if(!(aa[b1 + i][b + i] =='.')){
        	   						std::cout<<"rd";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b < b2 && b1 > b3){//право-верх
        	   					//std::cout<<"sru";
        	   					if(!(aa[b1 - i][b + i] =='.')){
        	   						std::cout<<"ru";
        	   						t = 1;
        	   					}
        	   				}
        	   				else { t = 1; }
            			}	
        	    	}
        	    	else { t = 1; }
        	    }
        	    if(aa[b1][b] == 'K' || aa[b1][b] == 'k'){//король
        	    	if(abs(b - b2) <= 1 && abs(b1 - b3) <= 1){//не дальше шага
        	    		if (!(aa[b3][b2] == '.')) {
        	    			t = 1;
        	    		}
        	    	}
        	    	else { t = 1; }
        	    }
        	    if(aa[b1][b] == 'Q' || aa[b1][b] == 'q'){
        	    	if(b == b2){//вертикаль
        	    		//std::cout<<"|";
        	   			if(b1 > b3){ //вперед
        	   				//std::cout<<"|";
        	   				for(i = b1; i > b3; i--){ //вертикаль цыфры (b1 -- b3)
        	   					if(!(aa[i - 1][b] == '.')){ //есть п-е
            						//std::cout <<"-|";
       	    						t = 1;
       	    					}
       	    				}
        	    			if(!(b == b2)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    		if(b1 < b3){ //назад
        	    			//std::cout<<"|";
        	    			for(i = b1; i < b3; i++){ //вертикаль цыфры (b1 -- b3)
        	   					if(!(aa[i + 1][b] == '.')){ //есть п-е
        	   						//std::cout <<"-|";
        	   						t = 1;
        	   					}
            				}
        	    			if(!(b == b2)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    	}
        	    	else if(b != b2){ //горизонт
        	    		//std::cout<<"|";
        	   			if(b > b2){ //влево
        	   				//std::cout<<"|";
        	   				for(i = b; i > b2; i--){ //горизонт (b -- b2)
        	   					if(!(aa[b1][i - 1] == '.')){ //есть п-е
            						//std::cout <<"-|";
       	    						t = 1;
       	    					}
       	    				}
        	    			if(!(b1 == b3)){ //проверка горизонт
        	    				t = 1;
        	    			}
        	    		}
        	    		if(b < b2){ //вправо
        	    			//std::cout<<"|";
        	    			for(i = b; i < b2; i++){ //горизонт (b -- b2)
        	   					if(!(aa[b1][i + 1] == '.')){ //есть п-е
        	   						//std::cout <<"-|";
        	   						t = 1;
        	   					}
            				}
        	    			if(!(b1 == b3)){ //проверка вертикали
        	    				t = 1;
        	    			}
        	    		}
        	    	}
        	    	else if(abs(b1 - b3) == abs(b - b2)){ //ход по диоганали
        	    		//std::cout<<"s";
        	    		for(i = 1; i <= abs(b - b2); i++){
        	    			if(b > b2 && b1 > b3){//лево-верх
        	    				//std::cout<<"slu";
        	   					if(!(aa[b1 - i][b - i] =='.')){
        	   					//std::cout<<"lu";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b > b2 && b1 < b3){//лево-низ
        	   					//std::cout<<"sld";
        	   					if(!(aa[b1 + i][b - i] =='.')){
        	   					//std::cout<<"ld";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b < b2 && b1 < b3){//право-низ
        	   					//std::cout<<"srd";
        	   					if(!(aa[b1 + i][b + i] =='.')){
        	   						//std::cout<<"rd";
        	   						t = 1;
        	   					}
        	   				}
        	   				else if(b < b2 && b1 > b3){//право-верх
        	   					//std::cout<<"sru";
        	   					if(!(aa[b1 - i][b + i] =='.')){
        	   						//std::cout<<"ru";
        	   						t = 1;
        	   					}
        	   				}
        	   				else { t = 1; }
            			}	
        	    	}
        	    }
        	    }
        	
        	}
        	else {std::cout << "5:";}
        	return t;
        }
        
