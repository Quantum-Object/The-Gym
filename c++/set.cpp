#include <iostream>
#include <unordered_set>

class CustomSet {
private:
    std::unordered_set<int> elements;

public:
    // Add an element to the set
    void add(int element) {
        elements.insert(element);
    }

    // Remove an element from the set
    void remove(int element) {
        elements.erase(element);
    }

    // Check if the set contains an element
    bool contains(int element) const {
        return elements.find(element) != elements.end();
    }

    // Check if the set is a subset of another set
    bool isSubset(const CustomSet& other) const {
        for (const int& elem : elements) {
            if (!other.contains(elem)) {
                return false;
            }
        }
        return true;
    }

    // Return the union of two sets
    CustomSet setUnion(const CustomSet& other) const {
        CustomSet result = *this;
        for (const int& elem : other.elements) {
            result.add(elem);
        }
        return result;
    }

    // Return the intersection of two sets
    CustomSet intersection(const CustomSet& other) const {
        CustomSet result;
        for (const int& elem : elements) {
            if (other.contains(elem)) {
                result.add(elem);
            }
        }
        return result;
    }

    // Return the difference of two sets
    CustomSet difference(const CustomSet& other) const {
        CustomSet result;
        for (const int& elem : elements) {
            if (!other.contains(elem)) {
                result.add(elem);
            }
        }
        return result;
    }

    // Print the elements of the set
    void print() const {
        std::cout << "{ ";
        for (const int& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }
};

// Example usage
int main() {
    CustomSet setA;
    setA.add(1);
    setA.add(2);
    setA.add(3);

    CustomSet setB;
    setB.add(3);
    setB.add(4);
    setB.add(5);

    std::cout << "Set A: ";
    setA.print();

    std::cout << "Set B: ";
    setB.print();

    CustomSet unionSet = setA.setUnion(setB);
    std::cout << "Union: ";
    unionSet.print();

    CustomSet intersectionSet = setA.intersection(setB);
    std::cout << "Intersection: ";
    intersectionSet.print();

    CustomSet differenceSet = setA.difference(setB);
    std::cout << "Difference (A - B): ";
    differenceSet.print();

    std::cout << "Is A a subset of B? " << (setA.isSubset(setB) ? "Yes" : "No") << std::endl;
    std::cout << "Does A contain 2? " << (setA.contains(2) ? "Yes" : "No") << std::endl;

    return 0;
}