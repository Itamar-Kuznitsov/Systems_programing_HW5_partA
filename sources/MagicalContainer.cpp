#include <iostream>
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

/**
 * @about: This is the MagicalContainer.cpp implemantation file - Task 5 | part A.
 *         - Systems programing course N.2
 * @author: Itamar Kuznitsov.
 * @since: Jun. 2023
*/


MagicalContainer:: MagicalContainer(){}
MagicalContainer:: ~MagicalContainer(){}

void MagicalContainer:: addElement(int element) {
    this->main_container.push_back(element);
    update_ascending_container();

}

void MagicalContainer:: removeElement(int element) {
    for (auto it = this->main_container.begin(); it != this->main_container.end(); ++it) {
        if (*it == element) {
            this->main_container.erase(it);
            break;
        }
    }
}

int MagicalContainer:: size() const {
    return this->main_container.size();
}


void MagicalContainer:: update_ascending_container(){}
void MagicalContainer:: update_prime_container(){}
void MagicalContainer:: update_cross_container(){}

// return true if num is prime otherwise false. 
bool MagicalContainer:: isPrime(int num){
    if(num < 2) return false;
    if(num == 2) return true;
    if(num%2 == 0) return false;

    for(int i= 3; (i*i)<= num; i+= 2){
        if(num % i == 0)
            return false;
    }
    return true;
}



// AscendingIterator
MagicalContainer::AscendingIterator:: AscendingIterator(const MagicalContainer& cont): container(cont){}
MagicalContainer::AscendingIterator:: AscendingIterator(const AscendingIterator& other): container(other.container){}
MagicalContainer::AscendingIterator:: ~AscendingIterator(){}
bool MagicalContainer::AscendingIterator:: operator==(const AscendingIterator& other) const{return 0;}
bool MagicalContainer::AscendingIterator:: operator!=(const AscendingIterator& other) const{return 0;}
bool MagicalContainer::AscendingIterator:: operator>(const AscendingIterator& other) const{return 0;}
bool MagicalContainer::AscendingIterator:: operator<(const AscendingIterator& other) const{return 0;}
int MagicalContainer::AscendingIterator:: operator*() const{return 0;}
MagicalContainer:: AscendingIterator& MagicalContainer::AscendingIterator:: operator=(const AscendingIterator& other){return *this;}
MagicalContainer:: AscendingIterator& MagicalContainer::AscendingIterator:: operator++(){return *this;}
MagicalContainer:: AscendingIterator MagicalContainer::AscendingIterator:: begin(){return AscendingIterator(container);}
MagicalContainer:: AscendingIterator MagicalContainer::AscendingIterator:: end(){return AscendingIterator(container);}

// PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& cont): container(cont){}
MagicalContainer::PrimeIterator:: PrimeIterator(const PrimeIterator& other): container(other.container){}
MagicalContainer::PrimeIterator::~PrimeIterator() {}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {return 0;}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {return 0;}
bool MagicalContainer::PrimeIterator:: operator>(const PrimeIterator& other) const{return 0;}
bool MagicalContainer::PrimeIterator:: operator<(const PrimeIterator& other) const{return 0;}
int MagicalContainer::PrimeIterator::operator*() const {return 0;}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {return *this;}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {return *this;}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {return PrimeIterator(container);}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {return PrimeIterator(container);}

// SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& cont): container(cont){}
MagicalContainer::SideCrossIterator:: SideCrossIterator(const SideCrossIterator& other): container(other.container){}
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}
MagicalContainer:: SideCrossIterator& MagicalContainer::SideCrossIterator:: operator=(const SideCrossIterator& other){return *this;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {return 0;}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {return 0;}
bool MagicalContainer::SideCrossIterator:: operator>(const SideCrossIterator& other) const{return 0;}
bool MagicalContainer::SideCrossIterator:: operator<(const SideCrossIterator& other) const{return 0;}
int MagicalContainer::SideCrossIterator::operator*() const {return 0;}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {return *this;}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {return SideCrossIterator(container);}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {return SideCrossIterator(container);}

// end of program