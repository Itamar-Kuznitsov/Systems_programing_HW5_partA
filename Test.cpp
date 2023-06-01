#include "doctest.h"
#include <sstream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;


/**
 * @about: This is a test file thats responsible for chaecking the correctness of MagicalContainer.cpp program.
 *         - Systems programing course N.2
 * @author: Itamar Kuznitsov.
 * @since: Jun. 2023
*/




// check containers and iterators initializtion
TEST_CASE("check containers and iterators initializtion") {
    // valid cotainer
    CHECK_NOTHROW(MagicalContainer container_);
    MagicalContainer container;
    
    // valid operation
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.removeElement(17));
    // invalid operation should throw
    CHECK_THROWS(container.addElement(7));
    
    // valid iterator init
    CHECK_NOTHROW(MagicalContainer:: AscendingIterator ascIter(container));
    CHECK_NOTHROW(MagicalContainer:: PrimeIterator ascIter(container));
    CHECK_NOTHROW(MagicalContainer:: SideCrossIterator ascIter(container));
}


// tests for AscendingIterator
TEST_CASE("MagicalContainer AscendingIterator Test") {
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));

    // check the order of the items
    SUBCASE("Check for elements in ascending order") {
        std::stringstream output;
        MagicalContainer:: AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "2 3 9 17 25 ");
    }

    // check AscendingIterator's operators: ==, !=     
    SUBCASE("AscendingIterator comparisons") {
        MagicalContainer:: AscendingIterator it1(container);
        MagicalContainer:: AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it1
        ++it1;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));
        // promote it2
        ++it2;
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it12
        ++it2;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));

        // test comparison end iterator
        MagicalContainer:: AscendingIterator it3(container);
        // reset the iterator to the beginning
        it3.begin();  
        auto itEnd = it3.end();
        CHECK(it1 != itEnd);
        CHECK(!(it1 == itEnd));
    }

    // check iterators location in empty container
    SUBCASE("check iterators location in empty container") {
        // Create an empty container
        MagicalContainer emptyContainer;
        MagicalContainer:: AscendingIterator it(emptyContainer);
        auto beginIt = it.begin();
        auto endIt = it.end();
        CHECK(beginIt == endIt);
    }
}


// tests for PrimeIterator
TEST_CASE("MagicalContainer PrimeIterator Test") {
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(3));
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    
    // check the order of the items
    SUBCASE("Check for prime numbers") {
        std::stringstream output;
        MagicalContainer:: PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "2 3 17 ");
    }

    // check PrimeIterator's operators: ==, !=     
    SUBCASE("PrimeIterator comparisons") {
        MagicalContainer:: PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it1
        ++it1;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));
        // promote it2
        ++it2;
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it12
        ++it2;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));

        // test comparison end iterator
        MagicalContainer:: PrimeIterator it3(container);
        // reset the iterator to the beginning
        it3.begin();  
        auto itEnd = it3.end();
        CHECK(it1 != itEnd);
        CHECK(!(it1 == itEnd));
    }

    // check iterators location in empty container
    SUBCASE("check iterators location in empty container") {
        // Create an empty container
        MagicalContainer emptyContainer;
        MagicalContainer:: PrimeIterator it(emptyContainer);
        auto beginIt = it.begin();
        auto endIt = it.end();
        CHECK(beginIt == endIt);
    }
}


// tests for SideCrossIterator
TEST_CASE("MagicalContainer SideCrossIterator Test") {
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(3));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(25));

    // check the order of the items
    SUBCASE("Check for elements in cross order") {
        std::stringstream output;
        MagicalContainer:: SideCrossIterator crossIter(container);
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "2 25 3 17 9 ");
    }

    // check SideCrossIterator's operators: ==, !=     
    SUBCASE("SideCrossIterator comparisons") {
        MagicalContainer:: SideCrossIterator it1(container);
        MagicalContainer:: SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it1
        ++it1;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));
        // promote it2
        ++it2;
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        // promote it12
        ++it2;
        CHECK(it1 != it2);
        CHECK(!(it1 == it2));

        // test comparison end iterator
        MagicalContainer:: SideCrossIterator it3(container);
        // reset the iterator to the beginning
        it3.begin();  
        auto itEnd = it3.end();
        CHECK(it1 != itEnd);
        CHECK(!(it1 == itEnd));
    }

    // check iterators location in empty container
    SUBCASE("check iterators location in empty container") {
        // Create an empty container
        MagicalContainer emptyContainer;
        MagicalContainer:: SideCrossIterator it(emptyContainer);
        auto beginIt = it.begin();
        auto endIt = it.end();
        CHECK(beginIt == endIt);
    }
}


// tests for updating containers
TEST_CASE("MagicalContainer Iterator after update - Test") {
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));
    CHECK(container.size() == 5);

    SUBCASE("adding elements and iterator update") {
        MagicalContainer:: AscendingIterator ascIter(container);
        CHECK_NOTHROW(container.addElement(8));
        // check container new size
        CHECK(container.size() == 6);

        // check if the iterator is updated
        std::stringstream output;
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "2 3 8 9 17 25 ");
    }

    SUBCASE("removing elements and iterator update") {
        MagicalContainer:: SideCrossIterator crossIter(container);
        container.removeElement(9);
        // check container new size
        CHECK(container.size() == 5);

        // check if the iterator is updated
        std::stringstream output;
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "2 25 3 17 ");

        container.removeElement(2);
        // check if the iterator is updated
        output.str("");
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
            output << *it << ' ';
        }
        CHECK_EQ(output.str(), "25 3 17 ");
    }
}



// tests for iterator content operator*
TEST_CASE("check iterators content operator(*)") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("check SideCrossIterator") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 4);
    }

    SUBCASE("check SideCrossIterator") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 14);
    }

    SUBCASE("check SideCrossIterator") {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
    }
}

// end of tests file