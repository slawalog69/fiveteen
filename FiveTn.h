
#ifndef FIVE_TN 
#define FIVE_TN


extern void Run();
/** @brief внешняя функция,
 возвращающая номер зоны, в которой было произведено нажатие.
 */
extern unsigned char ftouch(void);

/** @brief внешние функции,
 каждая из которых выводит цифру от 1 до 15 или «пробел» в текущую зону экрана.
 При выполнении любой из функций «fpicture_x» номер текущей зоны экрана 
 автоматически инкрементируется 
 */
extern void fpicture_1(void);
extern void fpicture_2(void);
extern void fpicture_3(void);
extern void fpicture_4(void);
extern void fpicture_5(void);
extern void fpicture_6(void);
extern void fpicture_7(void);
extern void fpicture_8(void);
extern void fpicture_9(void);
extern void fpicture_10(void);
extern void fpicture_11(void);
extern void fpicture_12(void);
extern void fpicture_13(void);
extern void fpicture_14(void);
extern void fpicture_15(void);
extern void fpicture_spase(void);
#endif // FIVE_TN

