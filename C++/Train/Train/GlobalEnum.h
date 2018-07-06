#pragma once

enum MONTH { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
enum menu { ADD = 1, SHOW, SEARCH, EXIT };//меню

#define MAXYEAR 2022//максимальный год в расписании
#define MINYEAR 2012//текущий год в расписании
#define SIZEANSWER 30//размер строки ответа
#define LINE 50//длина линии разделителя
#define FIRSTDAYMONTH 1//первый день месяца
#define LASTDAYLONGMONTH 31//последний день длинного месяца
#define LASTDAYSHOTMONTH 30//последний день короткого месяца
#define LASTLONGFEBRUARY 29//длинный февраль
#define LASTSHOTFEBRUARY 28//короткий февраль
#define MINHOUR 0//минимальное число часов в сутках
#define MAXHOUR 23//максимальное число часов в сутках
#define MINMINUTS 0//минимальное число минут в часу
#define MAXMINUTS 59//максимальное число минут в часу