#include "gtest/gtest.h"
#include "../HashMap/HashMap.h"


using namespace std;

HashMap<int, string> *miHash;

TEST(test_HashMap, nuevaTablaVacia) {
    miHash = new HashMap<int, string>(20);
    EXPECT_EQ(miHash->esVacio(), true);
}

TEST(test_HashMap, agregoTres_noVacia) {
    miHash->put(3,"Tres");
    miHash->put(2,"Dos");
    miHash->put(1,"Uno");
    EXPECT_EQ(miHash->esVacio(), false);
}

TEST(test_HashMap, obtengoDato) {
    EXPECT_EQ(miHash->get(3), "Tres");
    EXPECT_EQ(miHash->get(2), "Dos");
    EXPECT_EQ(miHash->get(1), "Uno");
    EXPECT_ANY_THROW(miHash->get(4));
}

TEST(test_HashMap, borroDato) {
    EXPECT_NO_THROW(miHash->remove(3));
    EXPECT_ANY_THROW(miHash->get(3)) << "Remover no tira exepcion";
}
