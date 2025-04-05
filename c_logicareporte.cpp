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

/*  LogicaNegocio::evaluar_data
    LOGICA PRINCIPAL DEL PROBLEMA:
-   Si nuestra transaccion es de tipo credito, no debería afectar nuestro balance, pero como nuestro balance final es 0 al inicio, sumamos el monto para el reporte
-   Si nuestra transaccion es tipo debito, afecta a nuestro balance, debido a eso restamos el balance final
-   Tenemos 2 variables de conteo, uno para credito y otro para debido. Se aumenta un contador depiendo la condicionales definidas en el programa
-   Para mantener track del monto mayor, comparamos con el monto_mayor anterior, si este monto mayor es mayor al antiguo: actualizamos la variable global
-   Grabamos la id para facilidad nuestra a la hora de imprimir el reporte (tambien solo podriamos grabar la id y compara haciendo una consulta pero resulta a nuestro hash table)
*/
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
    