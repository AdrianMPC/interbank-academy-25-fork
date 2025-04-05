#ifndef C_CUCKOOHASHING_H
#define C_CUCKOOHASHING_H

#include "./s_data.h"

#include <vector>
#include <cstdint>
#include <fstream>
#include <cstddef>

/*  CuckooHashing
    Impleentacion de una sola tabla de la estructura de dato cuckoo-hashing
    Esto no permite una velocidad de busqueda de datos, lectura, y eliminacion de estos: constante O(1), no importa cuantos datos ingresemos la velocidad será la misma
    La insercion tiene una complejidad en el peor de los casos de o(n), esto debido a que el peor caso requiera rehashear toda la tabla con el fin de resolver colisiones
*/

class CuckooHashing {
    private:
        std::vector<s_interbank_data*> m_tabla;
        size_t m_sizeTabla;
        unsigned long m_firstHash(unsigned long id);
        unsigned long m_secondHash(unsigned long id);
        void m_rehash(s_interbank_data* columna_data, unsigned long pos);
        void m_rehashAll();

        static unsigned long hashFunction(unsigned long key, size_t tableSize) {
            const uint32_t prime = 0x9e3779b1; // A large prime number (Knuth's constant for mixing)
            key ^= (key >> 21);
            key *= prime;
            key ^= (key >> 24);
            key += (key << 3);
            key ^= (key >> 11);
            key += (key << 15);
            key ^= (key >> 17);
            return key % tableSize;
        }

    public:
        CuckooHashing(size_t sizeTabla);
        ~CuckooHashing();
        bool insertDataChunk(s_interbank_data* data);
        s_interbank_data* searchData(unsigned long id);
        bool deleteDataChunk(unsigned long id);
        size_t getSize();
};

#endif // C_CUCKOOHASHING_H