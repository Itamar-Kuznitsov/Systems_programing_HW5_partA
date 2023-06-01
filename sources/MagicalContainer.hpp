#pragma once
#include <iostream>
#include <vector>
using namespace std;


/**
 * @about: This is the MagicalContainer.cpp header file - Task 5 | part A.
 *         - Systems programing course N.2
 * @author: Itamar Kuznitsov.
 * @since: Jun. 2023
*/



namespace ariel{

class MagicalContainer{
    private:
    vector<int> main_container;
    vector<int> ascending_container;
    vector<int> prime_container;
    vector<int> cross_container;

    public:
    MagicalContainer();
    ~MagicalContainer();
    void addElement(int);
    void removeElement(int);
    int size() const;

    // assistance functions 
    void update_ascending_container();
    void update_prime_container();
    void update_cross_container();
    bool isPrime(int num);

    // iterators:
    class AscendingIterator {
    private:
        const MagicalContainer& container;

    public:
        AscendingIterator(const MagicalContainer& cont);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();

        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();
        AscendingIterator begin();
        AscendingIterator end();
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;

    public:
        SideCrossIterator(const MagicalContainer& cont);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();

        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();
        SideCrossIterator begin();
        SideCrossIterator end();
    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;

    public:
        PrimeIterator(const MagicalContainer& cont);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();

        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();
        PrimeIterator begin();
        PrimeIterator end();
    };

};
}

// end of program