#ifndef C_CSVREADER_H
#define C_CSVREADER_H

#include <string>
#include <vector>
/* CSVreader
    Lector de CSV adaptado al caso
*/
class CSVreader {
    private:
        std::string m_narchivo;
        char m_delimitador;
        std::vector<std::vector<std::string>> m_data;
        std::vector<std::string> m_split(const std::string& p_linea, char p_delimitador);
    public:
        CSVreader(const std::string& p_narchivo, char p_delimitador = ';');
        bool read();
        void clearData();        
        std::vector<std::vector<std::string>> getData() const;
};
#endif // C_CSVREADER_H