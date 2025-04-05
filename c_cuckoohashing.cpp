#include "./s_data.h"
#include "./c_cuckoohashing.h"

#include <vector>
#include <utility>

CuckooHashing::CuckooHashing(size_t sizeTabla) : m_sizeTabla(sizeTabla)
{
    m_tabla.resize(sizeTabla, nullptr);
}

CuckooHashing::~CuckooHashing(){
    for (auto& ptr : m_tabla) {
        if (ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
    m_tabla.clear();
}

unsigned long CuckooHashing::m_firstHash(unsigned long id)
{
    return hashFunction(id, m_sizeTabla);
}

unsigned long CuckooHashing::m_secondHash(unsigned long id)
{
    return hashFunction(id * 37, m_sizeTabla); 
}

size_t CuckooHashing::getSize()
{
    return this->m_sizeTabla;
}

void CuckooHashing::m_rehash(s_interbank_data* data, unsigned long pos)
{
    uint32_t loopCount = 0;
    while (loopCount < m_sizeTabla)
    {
        std::swap(data, m_tabla[pos]);

        unsigned long posCheck = m_firstHash(data->id);
        if (pos == posCheck)
        {
            posCheck = m_secondHash(data->id);
        }

        if (m_tabla[posCheck] == nullptr)
        {
            m_tabla[posCheck] = data;
            return;
        }

        pos = posCheck;
        loopCount++;
    }
    m_rehashAll();
    insertDataChunk(data);
}

void CuckooHashing::m_rehashAll()
{
    std::vector<s_interbank_data*> oldTable = m_tabla;
    m_sizeTabla = m_sizeTabla * 2;
    m_tabla.clear();
    m_tabla.resize(m_sizeTabla, nullptr);

    for (s_interbank_data* key : oldTable)
    {
        if (key != nullptr)
        {
            insertDataChunk(key);
        }
    }
    oldTable.resize(0);
}

bool CuckooHashing::insertDataChunk(s_interbank_data* data)
{
    s_interbank_data* check = searchData(data->id);
    if (check != nullptr)
    {
        return false;
    }

    uint32_t pos1 = m_firstHash(data->id);
    if (m_tabla[pos1] == nullptr)
    {
        m_tabla[pos1] = data;
        return true;
    }

    s_interbank_data* oldKey = m_tabla[pos1];
    m_tabla[pos1] = data;

    uint32_t posCheck = m_firstHash(oldKey->id);

    if (posCheck == pos1)
    {
        posCheck = m_secondHash(oldKey->id);
    }

    if (m_tabla[posCheck] == nullptr)
    {
        m_tabla[posCheck] = oldKey;
        return true;
    }

    m_rehash(oldKey, posCheck);
    return true;
}

s_interbank_data* CuckooHashing::searchData(unsigned long id)
{
    int pos1 = m_firstHash(id);
    if (m_tabla[pos1] != nullptr && m_tabla[pos1]->id == id)
    {
        return m_tabla[pos1];
    }

    int pos2 = m_secondHash(id);
    if (m_tabla[pos2] != nullptr && m_tabla[pos2]->id == id)
    {
        return m_tabla[pos2];
    }

    return nullptr;
}

bool CuckooHashing::deleteDataChunk(unsigned long id)
{
    s_interbank_data* data = searchData(id);
    if (data == nullptr)
    {
        return false;
    }

    unsigned long pos1 = m_firstHash(data->id);
    if (m_tabla[pos1] != nullptr && m_tabla[pos1]->id == id)
    {
        m_tabla[pos1] = nullptr;
    }
    else
    {
        unsigned long pos2 = m_secondHash(data->id);
        if (m_tabla[pos2] != nullptr && m_tabla[pos2]->id == id)
        {
            m_tabla[pos2] = nullptr;
        }
        else
        {
            return false;
        }
    }
    return true;
}