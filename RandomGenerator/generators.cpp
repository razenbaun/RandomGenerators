#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <random>


int midSquareGenerator() {
	// ������������� ����� (������������ ������� �����)
    static unsigned long long int seed = time(NULL);

	// ���������� ����� � �������
    unsigned long long int squaredSeed = seed * seed; 

	// �������������� �������� � ������
    std::string seedString = std::to_string(squaredSeed); 
    int seedLength = seedString.length();

    // ���������� ������� �����, ���� ����� ������ ������ 16
    while (seedLength < 16)
    {
        seedString = "0" + seedString;
        seedLength++;
    }

    // ��������� ������� 8 ���� � �������� � �������������� �� � �����
    std::string middleDigits = seedString.substr(4, 8);
    unsigned long long int randomNum = std::stoull(middleDigits);

    // ���������� ����� ��� ���������� ������
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
  static unsigned long long int seed = time(NULL); // ����� �� ������ ���� 0
  seed = (seed * 73129 + 95121) % 100000;
  return (unsigned int) seed;
}

int oldRand() {
	static unsigned long long int seed = time(NULL);
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed / 65536) % 32768;
}