

#include "Levenshtein Damerau.hpp"
int DamerauLevenshteinDistance(S: char[1..M], T: char[1..N]; deleteCost, insertCost, replaceCost, transposeCost: int):
d: int[0..M][0..N]
  
// База динамики
d[0][0] = 0
for i = 1 to M
    d[i][0] = d[i - 1][0] + deleteCost
for j = 1 to N
    d[0][j] = d[0][j - 1] + insertCost

for i = 1 to M
    for j = 1 to N
        // Стоимость замены
        if S[i] == T[j]
           d[i][j] = d[i - 1][j - 1]
        else
           d[i][j] = d[i - 1][j - 1] + replaceCost
        d[i][j] = min(
                         d[i][j],                                     // замена
                         d[i - 1][j    ] + deleteCost,                // удаление
                         d[i    ][j - 1] + insertCost                 // вставка
                     )
        if(i > 1 and j > 1 and S[i] == T[j - 1] and S[i - 1] == T[j])
            d[i][j] = min(
                              d[i][j],
                              d[i - 2][j - 2] + transposeCost         // транспозиция
                         )
return d[M][N]
