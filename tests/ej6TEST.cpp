#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(obtenerRegionConectadaTest, imagenActivadaSoloSemillaPueboMatSalida) {
    int iteraciones = -1;
	
	imagen img = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    pixel semilla = {3, 2};

    iteraciones = obtenerRegionConectada(img, semilla);

    EXPECT_EQ(img, img);
	
}

TEST(obtenerRegionConectadaTest, imagenActivadaSoloSemillaPueboQIteraciones) {
    int iteraciones = -1;
	
	imagen img = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    pixel semilla = {3, 2};

    iteraciones = obtenerRegionConectada(img, semilla);

    EXPECT_EQ(iteraciones, 1);	
}

TEST(obtenerRegionConectadaTest, imagenEjemploPrueboMat) {
	int iteraciones = -1;
    imagen img = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    pixel semilla = {6, 3};
    imagen esperada = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    iteraciones = obtenerRegionConectada(img, semilla);

    EXPECT_EQ(esperada, img);
}

TEST(obtenerRegionConectadaTest, imagenEjemploPrueboQIteraciones) {
	int iteraciones = -1;
    imagen img = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    pixel semilla = {6, 3};

    iteraciones = obtenerRegionConectada(img, semilla);

    EXPECT_EQ(6, iteraciones);
}
