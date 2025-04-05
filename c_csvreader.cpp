#include "./c_csvreader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CSVreader::CSVreader(const std::string& p_narchivo, char p_delimitador)
{
    m_narchivo = p_narchivo;
    m_delimitador = p_delimitador;
}

std::vector<std::vector<std::string>> CSVreader::getData() const
{
    return m_data;
}

/* read()
    Seb encarga de leer linea por linea el CSV y guardar dicha linea en un vector
    Ignora la primera fila siempre
*/
bool CSVreader::read()
{
    std::ifstream file(m_narchivo);
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line); // ignora la primer linea

    while (std::getline(file, line)) {
        if (!line.empty()){
            m_data.push_back(m_split(line, m_delimitador));
        }  
    }

    file.close();
    return true;
}

/* m_split()
    Se para las lineas y devuelve un vector de tokens
    ARGS: line: linea a separar; delimiter: puede ser ; o , o lo que sea
*/
std::vector<std::string> CSVreader::m_split(const std::string& line, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

/* clearData()
    Libera el vector luego de pasarlo al hashtable, no hay necesidad de mantenerlo en memoria
*/
void CSVreader::clearData(){
    m_data.clear();                 
    m_data.shrink_to_fit();        
}