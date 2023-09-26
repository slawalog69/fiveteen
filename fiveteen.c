

#include "FiveTn.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void find_avlbl_touch(void);
void getRandom(void);

/** @brief массив значений зон экрана*/
union matrix{
int Buttons[16];
int row_col[4][4];
}u;

/** @brief  массив доступных для перемещения фишек*/
int avlbl_touch[5] = { 0 };

typedef void (*f_pic)(void);

/**@brief массив функций вывода*/
f_pic fpicture_x[16] =
{
fpicture_1,
fpicture_2,
fpicture_3,
fpicture_4,
fpicture_5,
fpicture_6,
fpicture_7,
fpicture_8,
fpicture_9,
fpicture_10,
fpicture_11,
fpicture_12,
fpicture_13,
fpicture_14,
fpicture_15,
fpicture_spase
};


/** @brief отрисовка игры  */
void showFiveTnPole(void) {
	for (int r = 0; r < 16; r++) {
		int t = u.Buttons[r] - 1; 
		fpicture_x[t]();
	}

}

/** @brief сброс и перемешивание */
void FiveTn_Reset(void) {
	getRandom();
	showFiveTnPole();
	find_avlbl_touch();
 
}

/** @brief генератор случайной последовательности кнопок */
void getRandom(void) {
	/* Intializes random number generator */
///       для параметра генератора используется время системы Win  
///		в  RISC процессорах можно использовать время любого таймера	
	__int64 t;
	srand((unsigned)time(&t));

	for (unsigned i = 0; i < 16; ++i) {
		unsigned j = rand() % (i + 1);
		u.Buttons[i] = u.Buttons[j];
		u.Buttons[j] = i + 1;
	}
}

/** @brief определение доступных зон(фишек) */
void find_avlbl_touch(void) { 
	memset(avlbl_touch, 0, sizeof(avlbl_touch));
printf("avalable : ");
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			if (u.row_col[r][c] == 16) {
				int i = 0; 
				if (r > 0) {
					avlbl_touch[i] = (r-1) * 4 + c+1;
					i++;
				}
				if(r < 3){
					avlbl_touch[i] =  (r + 1)* 4 + c+1;
					i++;
				}
				if (c > 0) {
					avlbl_touch[i] = r * 4  + c;
					i++;
				}
				if(c < 3){
					avlbl_touch[i] = r * 4  + c + 2;
				}

				avlbl_touch[4] = r * 4  + c + 1; 
				printf("\n space %d  \n", avlbl_touch[4]);
			}
		}
	}

}

/** @brief определение возможности движения */
int IsAvailable(int tch) {
	for (int i = 0; i < 4; i++){
		if (tch == avlbl_touch[i]) return avlbl_touch[i];
	}
	return 0;
}


/** @brief передвижение фишек */
void swapButt(int tch) {
	int posSpce = avlbl_touch[4];
	int bckUp = u.Buttons[tch];
	u.Buttons[tch] = u.Buttons[posSpce - 1];
	u.Buttons[posSpce - 1] = bckUp;
}



/** @brief цикл игры */
void Run() {
	FiveTn_Reset();
	while (1){
		int tch = ftouch();
		if (tch == avlbl_touch[4])
			FiveTn_Reset();

		else if (IsAvailable(tch)){
			swapButt(tch-1); 
			showFiveTnPole();
			find_avlbl_touch();
		}
	}

}