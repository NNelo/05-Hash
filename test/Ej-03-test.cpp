#include "gtest/gtest.h"
#include "../Ej-03/ReHashMap.h"

using std::string;

ReHashMap<int, string> *miReHash;

TEST(test_Ej03, RenuevaTablaVacia) {
    miReHash = new ReHashMap<int, string>(20);
    EXPECT_EQ(miReHash->esVacio(), true);
}

TEST(test_Ej03, ReagregoTres_noVacia) {
    miReHash->put(3, "Tres");
    miReHash->put(2, "Dos");
    miReHash->put(1, "Uno");
    EXPECT_EQ(miReHash->esVacio(), false);
}

TEST(test_Ej03, ReobtengoDato) {
    EXPECT_EQ(miReHash->get(3), "Tres");
    EXPECT_EQ(miReHash->get(2), "Dos");
    EXPECT_EQ(miReHash->get(1), "Uno");
    EXPECT_ANY_THROW(miReHash->get(4));
}

TEST(test_Ej03, ReborroDato) {
    EXPECT_NO_THROW(miReHash->remove(3));
    EXPECT_ANY_THROW(miReHash->get(3)) << "Remover no tira exepcion";
}

TEST(test_Ej03, ReHasheo){
    miReHash->reHashing(50);
    EXPECT_EQ(miReHash->get(2), "Dos");
    EXPECT_EQ(miReHash->get(1), "Uno");
    miReHash->put(108, "Ciento Ocho");
    EXPECT_EQ(miReHash->get(108), "Ciento Ocho");
}