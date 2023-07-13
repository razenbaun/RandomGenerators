#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <random>


int midSquareGenerator() {
	// Инициализация зерна (используется текущее время)
    static unsigned long long int seed = time(NULL);

	// Возведение зерна в квадрат
    unsigned long long int squaredSeed = seed * seed; 

	// Преобразование квадрата в строку
    std::string seedString = std::to_string(squaredSeed); 
    int seedLength = seedString.length();

    // Добавление ведущих нулей, если длина строки меньше 16
    while (seedLength < 16)
    {
        seedString = "0" + seedString;
        seedLength++;
    }

    // Выделение средних 8 цифр в квадрате и преобразование их в число
    std::string middleDigits = seedString.substr(4, 8);
    unsigned long long int randomNum = std::stoull(middleDigits);

    // Обновление зерна для следующего вызова
    seed = randomNum;

    return (unsigned int) randomNum;
}


int mersonMethod() {
	static unsigned long long int seed = time(NULL);
    static std::mt19937 gen(seed);
	std::uniform_int_distribution<> uid(1, RAND_MAX);
    return (unsigned int) uid(gen);
}

int PRNG()
{
  static unsigned long long int seed = time(NULL); // зерно не должно быть 0
  seed = (seed * 73129 + 95121) % 100000;
  return (unsigned int) seed;
}

int oldRand() {
	static unsigned long long int seed = time(NULL);
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed / 65536) % 32768;
}