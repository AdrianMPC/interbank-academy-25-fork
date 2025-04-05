#include "./c_logicareporte.h"
#include "iostream"
#include <cstring>

LogicaNegocio::LogicaNegocio()
{
    m_balance_final = 0;
    m_monto_mayor = 0;
    m_id_montomayor = 0;
    m_conteo_credito = 0;
    m_conteo_debito= 0;
}

void LogicaNegocio::evaluar_data(s_interbank_data* data){
    if(std::strcmp(data->tipo_transaccion, "Crédito") == 0){
        m_conteo_credito++;
        m_balance_final += data->monto;
    } 

    if(std::strcmp(data->tipo_transaccion, "Débito") == 0){
        m_conteo_debito++;
        m_balance_final -= data->monto;
    } 
    
    if(data->monto > m_monto_mayor){
        m_monto_mayor = data->monto;
        m_id_montomayor = data->id;
    }
}

void LogicaNegocio::generar_reporte()
{
    std::cout<<"Reporte de Transacciones\n";
    std::cout<<"---------------------------------------------\n";
    std::cout<<"Balance Final: " << m_balance_final << std::endl;
    std::cout<<"Transacción de Mayor Monto: ID " << m_id_montomayor << " - " << m_monto_mayor << std::endl;
    std::cout<<"Conteo de Transacciones: Crédito: " << m_conteo_credito << " Débito: " << m_conteo_debito << std::endl;
}

void LogicaNegocio::imprimir_registro(s_interbank_data* data){
    std::cout<<"ID: " << data->id << std::endl;
    std::cout<<"Tipo_transaccion: " << data->tipo_transaccion << std::endl;
    std::cout<<"Monto: " << data->monto << std::endl;
}
    