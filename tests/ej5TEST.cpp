#include "gtest/gtest.h"
#include "../ejercicios.h"
#include "../auxiliares.h"


TEST(cerrarFormaTest, tapandooHuecosDeUnPixel) {
    imagen A = {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
    };
    imagen esperada = {
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 0},
            {1, 1, 1, 1, 0, 0},
            {1, 1, 1, 1, 0, 0},
            {1, 1, 1, 1, 1, 1},
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}


TEST(cerrarFormaTest, cierreConCruz) {
    imagen A = {
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1},
    };
    imagen B = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };
    imagen esperada = {
        { 0, 0, 0, 0, 1, 1 },
        { 0, 1, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1 },
        { 0, 0, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 1 },
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(cerrarFormaTest, soloUnPixelPrendidoConElemSinCentro) {
    imagen A = { {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, };
    imagen B = { {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0},}
    imagen esperada = {
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(cerrarFormaTest, cierreConElementoSinCentroActivadoYConDosPixelesActivados) {
    imagen A = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, };
    imagen B = { {0, 1, 0}, {0, 0, 0}, {0, 1, 0}, };
    imagen esperada = {
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 1, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 1, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}

TEST(cerrarFormaTest, cierreConElementoEstructuranteAsimetrico) {
     imagen A = { {0, 0, 0}, {0, 0, 0}, {0, 1, 0}, {0, 0, 0}, {0, 0, 0}, };
     imagen B = { {0, 1, 0}, {0, 1, 0}, {0, 0, 0}, };
    imagen esperada = {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 1, 0},
        { 0, 0, 0},
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}
