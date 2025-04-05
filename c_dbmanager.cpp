#include "./c_dbmanager.h"


#include <iostream>
#include <cstring>

DBManager::DBManager(const std::string& p_archivoCSV, char p_delimitador, size_t p_hashSize)
: m_csvReader(p_archivoCSV, p_delimitador), m_hashTable(p_hashSize), m_genReporte() {}
  
s_interbank_data* DBManager::m_parseRow(const std::vector<std::string>& fila) {
    if (fila.size() < 3) return nullptr;

    s_interbank_data* data = new s_interbank_data;

    data->id = std::stoul(fila[0]);

    strncpy(data->tipo_transaccion, fila[1].c_str(), sizeof(data->tipo_transaccion) - 1);
    data->tipo_transaccion[sizeof(data->tipo_transaccion) - 1] = '\0';

    data->monto = std::stod(fila[2]);

    return data;
}

bool DBManager::loadData() {
    if (!m_csvReader.read()) { std::cout << "No se pudo leer el archivo\n"; return false;}
    for (const auto& fila : m_csvReader.getData()) {
        s_interbank_data* dato = m_parseRow(fila);
        if (dato) {
            m_genReporte.evaluar_data(dato);
            m_hashTable.insertDataChunk(dato);
        } else {
            std::cout << "No se pudo interpretar la fila!\n";
        }
    }
    m_csvReader.clearData();
    return true;
}

void DBManager::genReporte(){
    m_genReporte.generar_reporte();
}
void DBManager::searchID(unsigned long id) {
    s_interbank_data* data = m_hashTable.searchData(id);
    if(data){
        m_genReporte.imprimir_registro(data);
    } else {
        std::cout<<"No se encontró el registro con el ID: "<< id << std::endl;
    }
}
