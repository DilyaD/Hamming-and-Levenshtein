

#include "Hamming.hpp"
#include<bits/stdc++.h>

using namespace std;

  
// функция для вычисления расстояния Хэмминга для двух строк

int hammingDist(char *str1, char *str2)

{

    int i = 0, count = 0;

    while (str1[i] != '\0')

    {

        if (str1[i] != str2[i])

            count++;

        i++;

    }

    return count;

