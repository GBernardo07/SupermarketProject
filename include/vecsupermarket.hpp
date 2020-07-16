#ifndef VECSUPERMARKET_HPP
#define VECSUPERMARKET_HPP

template <typename tipo>
class vector_supermercado {

    private:

    int capacity, size;
    tipo *elements;

    void doubleCapacity() {

        capacity *= 2;
        tipo *moreElements = new tipo[capacity];

        for (int i = 0; i < size; i++)
            moreElements[i] = elements[i];

        delete[] elements;
        elements = moreElements;

    }

    public:

    vector_supermercado() : capacity(1), size(0) {

        elements = new tipo[capacity];
    }

    ~vector_supermercado() {

        delete[] elements;
    }

    int getSize() {

        return size;
    }

    tipo at(int n) {

        return elements[n];
    }

    void push_back(tipo object) {

        if (size == capacity)
            doubleCapacity();

        elements[size] = object;
        size++;
    }

    void pop_back() {

        tipo lixo;
        elements[--size] = lixo;
    }

};


#endif