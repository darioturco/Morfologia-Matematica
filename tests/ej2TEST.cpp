#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(sonPixelesConectadosTest, PixelesEnDiagonalNoEstanConectadosAdy4) {
    imagen img = {
		{1, 0},
		{0, 1}
	};
    pixel p = {0, 0};
    pixel q = {1, 1};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnHorizontalEstanConectadosAdy4) {
    imagen img = {{1, 1}};
    pixel p = {0, 0};
    pixel q = {0, 1};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnHorizontalSeparadosNoEstanConectadosAdy4) {
    imagen img = {{1, 0, 1}};
    pixel p = {0, 0};
    pixel q = {0, 2};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnVerticalSeparadosNoEstanConectadosAdy4) {
    imagen img = {{1}, {0}, {1}};
    pixel p = {0, 0};
    pixel q = {2, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnHorizontalAlRevesSeparadosNoEstanConectadosAdy4) {
    imagen img = {{1, 0, 1}};
    pixel p = {0, 2};
    pixel q = {0, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnVerticalAlRevesSeparadosNoEstanConectadosAdy4) {
    imagen img = {{1}, {0}, {1}};
    pixel p = {2, 0};
    pixel q = {0, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesConectadosPorUnPixelVerticalAdy4) {
    imagen img = {{1}, {1}, {1}};
    pixel p = {2, 0};
    pixel q = {0, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesConectadosPorMuchosPixelesVerticalesAdy4) {
    imagen img = {{0}, {1}, {1}, {1}, {1}};
    pixel p = {1, 0};
    pixel q = {4, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesConectadosPorMuchosPixelesParaTodosLadosAdy4) {
    imagen img = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1},
        {0, 1, 1},
    };
    pixel p = {0, 1};
    pixel q = {4, 1};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnDiagonalEstanConectadosAdy8) {
    imagen img = {
        {0, 1},
        {1, 0},
    };
    pixel p = {0, 1};
    pixel q = {1, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesSeparadosNoEstanConectadosAdy8) {
    imagen img = {
        {1, 0},
        {0, 0},
        {0, 1},
    };
    pixel p = {0, 1};
    pixel q = {2, 1};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesEnAdy4EstanConectadosAdy8) {
    imagen img = {
        {1, 1},
    };
    pixel p = {0, 1};
    pixel q = {0, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoAdy4EstanConectadosAdy8) {
    imagen img = {
        {1, 1},
        {0, 1},
        {0, 1},
    };
    pixel p = {0, 0};
    pixel q = {2, 1};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoAdy8EstanConectadosAdy8) {
    imagen img = {
        {1, 0},
        {0, 1},
        {0, 1},
    };
    pixel p = {0, 0};
    pixel q = {2, 1};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy8EstanConectadosAdy8) {
    imagen img = {
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 3};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy8NoEstanConectadosAdy4) {
    imagen img = {
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 3};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy4EstanConectadosAdy4) {
    imagen img = {
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 6};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

//***Test Nuevos***//

TEST(sonPixelesConectadosTest, NoConectadosSiPrimerPixelEstaInactivoAdy4) {
    imagen img = {{0}, {1}};
    pixel p = {0, 0};
    pixel q = {1, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, NoConectadosSiSegundoPixelEstaInactivoAdy4) {
    imagen img = {{1}, {0}};
    pixel p = {0, 0};
    pixel q = {1, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesRomboAdy8ActivoYNoActivoNoEstanConectadosAdy8) {
    imagen img = { {0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, };
    pixel p = {0, 1};
    pixel q = {4, 2};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelNoActivadoEstaConectadoConsigoMismoAdy8) {
    imagen img = { {0} };
    pixel p = {0, 0};
    pixel q = {0, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}

TEST(sonPixelesConectadosTest, PixelNoActivadoEstaConectadoConsigoMismoAdy4) {
    imagen img = { {0} };
    pixel p = {0, 0};
    pixel q = {0, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, NoConectadosUnPixelNoActivadoAdy8) {
    imagen img = { {1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 1, 1}, {1, 1, 0, 1, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 0, 0}, };
    pixel p = {0, 1};
    pixel q = {0, 0};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 8));
}
