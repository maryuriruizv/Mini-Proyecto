/*
MINI PROYECTO
Autor: Maryuri Ruiz
Fecha: 14 de septiembre de 2026

Enunciado:
    Desarrollar un programa de mascotas en C++ que permita registrar hasta 20 elementos utilizando arreglos.
    El programa debe permitir al usuario ingresar informacion sobre cada mascotas,incluyendo nombre, edad,
    peso en kilogramos y raza. Ademas el programa debe permitir al usuario realizar la busqueda de una mascota 
    por su nombre y buscar informacion de la mascota. Si se llega alcanzar el limite de registros, el sistema
    debe notificar al usuario y evitar el ingreso de datos adicionales.

E/P/S
*Entrada;
    - Ingreso del nombre de la mascota
*Proceso:
    - Leer el nombre de la mascota
    - Buscar la informacion de la mascota
    - Mostrar al usuario si se alcanza el limite o de datos adicionales

*Salida:
    -   Mostrar la informacion de la mascota
*/


#include <iostream>
#include <string>
using namespace std;


//Prototipos de funciones
void registrar();
void mostrar();
void buscar();
void reporteCreativo();

//Declaramos las variables
    string nombres[20];
    string razas[20];
    string nombreBuscar;
    int edad[20];
    double peso[20];
    int totalMascotas = 0;
    int opcion;



int main() {
    //Utilizamos do while 
    do {
        cout << "===== REGISTRO DE MASCOTAS =====";
        cout << "1. Registrar mascota";
        cout << "2. Mostrar  todas las mascota";
        cout << "3. Buscar mascotas por nombre";
        cout << "4. Reporte general";
        cout << "5. Componente creativo";
        cout << "6. Salir";
        cout << "Seleccione una opcion por favor: ";
        cin >> opcion;

        //Evaluamos la opcion elegida
        switch (opcion){
            case 1:{ 
                cout << "Nombre de la mascota: " << endl;
                break;
            }
            case 2:{
                cout << "Mostrar todas las mascotas: " << endl;
                break;
            }
            case 3:{
                cout << "Buscar mascota por nombre: " << endl;
                break; 
            }
            case 4:{
                cout << "Reporte general: " << endl;
                break;
            }
            case 5:{
                //Integramos el componente creativo
                if (totalMascotas == 0) {
                    bool encontrada = false;

                    for (int i = 0; i < totalMascotas; i++){
                        cout << "Componente creativo: " << endl;
                        if (nombres[i] == nombreBuscar) {
                            encontrada = true;

                            cout << "----RECOMENDACION NUTRICIONAL----";
                            cout << "Mascota: " << nombres[i] << ";" << "Peso: " << peso[i] << "kg";

                            if (peso[i] < 5.0){
                                cout << "Porcion sugerida para raza pequeña: 100 g de alimento diario";
                            }else if (peso[i] <= 15.5){
                                cout << "Porcion sugerida para raza mediana: 250g de alimento diario";
                            }else {
                                cout << "Porcion sugerida raza grande: 400g o mas de alimento diario";
                            }
                        }
                    }
                    if (!encontrada){
                        cout << "Mascota no encontrada.";
                    }
                    break;
                }
            }
            case 6:{
                cout << "Saliendo del programa.";
                break;
            }
            default:{
                cout << "Error: intente de nuevo";
                break;
            }

        }

    
    } while (opcion !=6);

    return 0;
}

//Esta funcion registra el nombre de la mascota
void registrar(){
    if (totalMascotas >=20){
        cout << "Limite de registro alcanzado.";
    }
    cout << "----REGISTRAR NUEVA MASCOTA----";
    cout << "Nombre: ";
    cin >> nombres[totalMascotas];

    do{
        cout << "Edad de la mascota: ";
        cin >> edad[totalMascotas];
        if (edad[totalMascotas] < 0)
        cout << "Edad invalida.";
    }while (edad[totalMascotas] < 0);

    do{
        cout << "Peso de la mascota: ";
        cin >> peso[totalMascotas];
        if (peso[totalMascotas] <= 0)
        cout << "Peso invalido.";
    }while (peso[totalMascotas] <=0);

    totalMascotas++;
    cout << "Mascota registrada con exito.";
}

// Función 2: Mostrar
void mostrar() {
    if (totalMascotas == 0) {
        cout << "No existen datos registrados todavia.";
        return;
    }
    cout << "--- LISTA DE MASCOTAS ---";
    for (int i = 0; i < totalMascotas; i++) {
        cout << i + 1 << ". Nombre: " << nombres[i] 
             << " | Edad: " << edad[i] << " años" 
             << " | Peso: " << peso[i] << " kg";
    }
}

// Función 3: Buscar
void buscar() {
    if (totalMascotas == 0) {
        cout << "No hay registros para buscar.";
        return;
    }
    string nombreBuscado;
    cout << "Ingrese el nombre de la mascota a buscar: ";
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < totalMascotas; i++) {
        if (nombres[i] == nombreBuscado) {
            cout << "¡Encontrado!\n";
            cout << "Nombre: " << nombres[i] << " | Edad: " << edad[i] << " | Peso: " << peso[i] << " kg";
            encontrado = true;
            break; // Salimos del bucle al hallar la coincidencia
        }
    }
    if (!encontrado) {
        cout << "La mascota '" << nombreBuscado << "' no se encuentra registrada.";
    }
}

// Función 4: Reporte General
void reporteCreativo() {
    if (totalMascotas == 0) {
        cout << "No hay datos para generar el reporte.";
        return;
    }
    double sumaPeso = 0;
    double mayorPeso = peso[0];
    string mascotaMayorPeso = nombres[0];

    for (int i = 0; i < totalMascotas; i++) {
        sumaPeso += peso[i];
        if (peso[i] > mayorPeso) {
            mayorPeso = peso[i];
            mascotaMayorPeso = nombres[i];
        }
    }
    double promedioPeso = sumaPeso / totalMascotas;

    cout << "--- REPORTE GENERAL ---";
    cout << "Total de mascotas registradas: " << totalMascotas << endl;
    cout << "Promedio de peso de las mascotas: " << promedioPeso << " kg";
    cout << "Mascota con mayor peso: " << mascotaMayorPeso << " (" << mayorPeso << " kg)";
}