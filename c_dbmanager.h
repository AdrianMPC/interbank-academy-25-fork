#ifndef C_DBMANAGER_H
#define C_DBMANAGER_H

#include "./c_csvreader.h"
#include "./c_cuckoohashing.h"
#include "./s_data.h"
#include "./c_logicareporte.h"

#include <iostream>
#include <cstring>

class DBManager {
    private:
        CSVreader m_csvReader;
        CuckooHashing m_hashTable;
        LogicaNegocio m_genReporte;
        s_interbank_data* m_parseRow(const std::vector<std::string>& fila);
    public:
        DBManager(const std::string& archivoCSV, char delimitador = ';', size_t hashSize = 2500);
        bool loadData();
        void genReporte();
        void searchID(unsigned long id);
};

#endif //C_DBMANAGER_H