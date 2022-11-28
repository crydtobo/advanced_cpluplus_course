#include <catch2/catch_test_macros.hpp>
#include "cart.h"

// Produkt* makeProdukt(std::string name) {
//     return new Produkt(name);
// }

Produkt::Ptr makeProduktPtr(std::string name) {
    return std::make_unique<Produkt>(name);
}

// TEST_CASE("empty") {
//     Koszyk koszyk;
//     REQUIRE(koszyk.size() == 0);
// }

TEST_CASE("dodaj") {
    Koszyk koszyk;
    auto maslo = makeProduktPtr("masło");
    auto masloPtr = koszyk.dodaj(std::move(maslo));
    REQUIRE(koszyk.size() == 1);
    CHECK(koszyk.front() == masloPtr);
}

// TEST_CASE("zabierz string") {
//     Koszyk koszyk;
//     auto maslo = makeProdukt("masło");
//     koszyk.dodaj(maslo);
//     REQUIRE(koszyk.size() == 1);
//     CHECK(koszyk.front() == maslo);
//     CHECK(koszyk.zabierz("masło") == true);
//     CHECK(koszyk.size() == 0);
// }

TEST_CASE("zabierz ptr") {
    Koszyk koszyk;
    auto masloUP = makeProduktPtr("masło");
    auto masloPtr = koszyk.dodaj(std::move(masloUP));
    REQUIRE(koszyk.size() == 1);
    CHECK(koszyk.front() == masloPtr);
    masloUP = koszyk.zabierz(masloPtr);
    CHECK(masloUP.get() == masloPtr);
    CHECK(koszyk.size() == 0);
}

// TEST_CASE("zobacz") {
//     Koszyk koszyk;
//     auto maslo = makeProdukt("masło");
//     koszyk.dodaj(maslo);
//     REQUIRE(koszyk.size() == 1);
//     CHECK(koszyk.front() == maslo);
//     CHECK(koszyk.zobacz("masło") == maslo);
// }

// TEST_CASE("dwa koszyki") {
//    Koszyk k1;
//    Koszyk k2;
//    auto maslo = makeProdukt("masło");
//    k1.dodaj(maslo);
//    k2.dodaj(maslo);
// }

// TEST_CASE("dwa razy") {
//    Koszyk k1;
//    auto maslo = makeProdukt("masło");
//    k1.dodaj(maslo);
//    k1.dodaj(maslo);
// }


