#include "gtest/gtest.h"
#include "../ejercicios.h"

double abs_error = 0.00001;

// Matriz apagada y ninguna region en adyacencia 4

TEST(devolverPromedioAreasTest, matrizApagada_enAdy4_1) {
    imagen A = {{0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 0.0, abs_error);
}

TEST(devolverPromedioAreasTest, matrizApagada_enAdy4_4) {
    imagen A = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 0.0, abs_error);
}

// Matriz apagada y ninguna region en adyacencia 8

TEST(devolverPromedioAreasTest, matrizApagada_enAdy8_1) {
    imagen A = {{0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 0.0, abs_error);
}

TEST(devolverPromedioAreasTest, matrizApagada_enAdy8_2) {
    imagen A = {{0}, {0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 0.0, abs_error);
}

// Regiones de un pixel segun adyacencia 4

TEST(devolverPromedioAreasTest, regionesDeUnPixel_EnAdy4_1) {
    imagen A = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 1.0, abs_error);
}

TEST(devolverPromedioAreasTest, regionesDeUnPixel_EnAdy4_2) {
    imagen A = {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 1.0, abs_error);
}

TEST(devolverPromedioAreasTest, regionesDeUnPixel_EnAdy4_3) {
    imagen A = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 1.0, abs_error);
}

// Regiones de un pixel segun adyacencia 8

TEST(devolverPromedioAreasTest, regionesDeUnPixel_EnAdy8_1) {
    imagen A = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 1.0, abs_error);
}


// Matriz activada de una sola region segun adyacencia 4


TEST(devolverPromedioAreasTest, MatrizActivaEnAdy4_3) {
    imagen A = {{1}, {1}, {1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 3.0, abs_error);
}


// Matriz activada de una sola region segun adyacencia 8

TEST(devolverPromedioAreasTest, MatrizActivaEnAdy8_1) {
    imagen A = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 9.0, abs_error);
}

// Casos de promedio entero en adyacencia 4
TEST(devolverPromedioAreasTest, regionEnteraEnAdy4_1) {
    imagen A = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 3.0, abs_error);
}

TEST(devolverPromedioAreasTest, regionEnteraEnAdy4_3) {
    imagen A = {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 3.0, abs_error);
}
// Casos de promedio entero en adyacencia 8
TEST(devolverPromedioAreasTest, regionEnteraEnAdy8_1) {
    imagen A = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 3.0, abs_error);
}

TEST(devolverPromedioAreasTest, regionEnteraEnAdy8_3) {
    imagen A = {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 3.0, abs_error);
}

// Casos de promedio con coma en adyacencia 4

TEST(devolverPromedioAreasTest, promedioDecimalEnAdy4_2) {
    imagen A = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 2.5, abs_error);
}

TEST(devolverPromedioAreasTest, promedioDecimalEnAdy4_3) {
    imagen A = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0},{0, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 4), 1.25, abs_error);
}

// Casos de promedio con coma en adyacencia 8

TEST(devolverPromedioAreasTest, promedioDecimalEnAdy8_1) {
    imagen A = {{1, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 1.5, abs_error);
}

TEST(devolverPromedioAreasTest, promedioDecimalEnAdy8_3) {
    imagen A = {{1, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 1},{1, 0, 0, 0}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 1.25, abs_error);
}
