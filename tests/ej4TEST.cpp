#include "gtest/gtest.h"
#include "../ejercicios.h"
#include <algorithm>

bool sonLosActivos(const imagen &A, const sqPixel &sp){
    sqPixel activosImagen;
    for (int i = 0; i < A.size() ; ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j]){
                pixel px = {i,j};
                activosImagen.push_back(px);
            }
        }

    }
    sort(activosImagen.begin(),activosImagen.end());
    sqPixel sp2 = sp;
    sort(sp2.begin(),sp2.end());
    return sp2 == activosImagen;
}

TEST(calcularContornoTest, CalcularContornoTodoActivo4Ady) {
    imagen imagenIn = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
    };
    imagen imagenOut = {
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
    };
    EXPECT_TRUE(sonLosActivos(imagenOut, calcularContorno(imagenIn, 4)));
}

TEST(calcularContornoTest, CalcularContornoTodoActivo8Ady) {
    imagen imagenIn = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
    };
    imagen imagenOut = {
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
    };
    EXPECT_TRUE(sonLosActivos(imagenOut, calcularContorno(imagenIn, 8)));
}

TEST(calcularContornoTest, CalcularContornoCruz4Ady) {
    imagen imagenIn = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };
    imagen imagenOut = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 0, 0, 1, 0},
            {0, 1, 0, 0, 1, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };
    EXPECT_TRUE(sonLosActivos(imagenOut, calcularContorno(imagenIn, 4)));
}

TEST(calcularContornoTest, CalcularContornoCruz8Ady) {
    imagen imagenIn = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };
    imagen imagenOut = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };
    EXPECT_TRUE(sonLosActivos(imagenOut, calcularContorno(imagenIn, 8)));
}