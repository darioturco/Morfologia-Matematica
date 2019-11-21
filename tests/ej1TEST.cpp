#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esImagenValidaTest, ImagenVaciaNoEsValida) {
    imagen img;
    EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenDeUnElementoEsValida) {
    imagen img = {{0}};
    EXPECT_TRUE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenDeDosFilasDeDiferenteTamanioEsInvalida) {
    imagen img = {{0}, {0, 1}};
    EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenConMuchosElementoDistintoDe0o1EsInvalida) {
    imagen img = {{0, 1, 0}, {1, 0, 0}, {0, 1, 2}};
    EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida) {
    imagen img = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 0, 1},
            {1, 0, 0},
            {1, 0, 0},
            {1, 1, 1},
    };
    EXPECT_TRUE(esImagenValida(img));
}
