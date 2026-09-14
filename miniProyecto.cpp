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
void reporte();
void componente();

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
        cout << "===== REGISTRO DE MASCOTAS =====" << endl;
        cout << "1. Registrar mascota" << endl;
        cout << "2. Mostrar todas las mascota" << endl;
        cout << "3. Buscar mascotas por nombre" << endl;
        cout << "4. Reporte general" << endl;
        cout << "5. Componente creativo" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion por favor: " << endl;
        cin >> opcion;

        //Evaluamos la opcion elegida
        switch (opcion){
            case 1:{ 
                registrar();
                break;
            }
            case 2:{
                mostrar(); 
                break;
            }
            case 3:{
                buscar();
                break; 
            }
            case 4:{
                reporte();
                break;
            }
            case 5:{
                componente();
                break;
            }
            case 6:{
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:{
                cout << "Error: intente de nuevo" << endl;
                break;
            }

        }

    
    } while (opcion !=6);

    return 0;
}

//funcion 1: Registrar
void registrar(){
    if (totalMascotas >=20){
        cout << "Limite de registro alcanzado." << endl;
        return;
    }
    cout << "----REGISTRAR NUEVA MASCOTA----" << endl;
    cout << "Nombre: " << endl;
    cin >> nombres[totalMascotas];

    do{
        cout << "Edad de la mascota: " << endl;
        cin >> edad[totalMascotas];
        if (edad[totalMascotas] < 0)
        cout << "Edad invalida." << endl;
    }while (edad[totalMascotas] < 0);

    do{
        cout << "Peso de la mascota: " << endl;
        cin >> peso[totalMascotas];
        if (peso[totalMascotas] <= 0)
        cout << "Peso invalido." << endl;
    }while (peso[totalMascotas] <=0);

    totalMascotas++;
    cout << "Mascota registrada con exito." << endl;
}

// Función 2: Mostrar
void mostrar() {
    if (totalMascotas == 0) {
        cout << "No existen datos registrados todavia." << endl;
        return;
    }
    cout << "--- LISTA DE MASCOTAS ---" << endl;
    for (int i = 0; i < totalMascotas; i++) {
        cout << i + 1 << ". Nombre: " << nombres[i] 
             << " | Edad: " << edad[i]  << " | Peso: " << peso[i] << " kg" << endl;
    }
}

// Función 3: Buscar
void buscar() {
    if (totalMascotas == 0) {
        cout << "No hay registros para buscar." << endl;
        return;
    }
    string nombreBuscado;
    cout << "Ingrese el nombre de la mascota por favor: " << endl;
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < totalMascotas; i++) {
        if (nombres[i] == nombreBuscado) {
            cout << "Encontrado" << endl;
            cout << "Nombre: " << nombres[i] << " | Edad: " << edad[i] << " | Peso: " << peso[i] << " kg" 
            << endl;
            encontrado = true;
            break; // Salimos del bucle al hallar la coincidencia
        }
    }
    if (!encontrado) {
        cout << "La mascota '" << nombreBuscado << "' no se encuentra registrada." << endl;
    }
}

// Función 4: Reporte General
void reporte() {
    if (totalMascotas == 0) {
        cout << "No hay datos para generar el reporte." << endl;
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

    cout << "--- REPORTE GENERAL ---" << endl;
    cout << "Total de mascotas registradas: " << totalMascotas << endl;
    cout << "Promedio de peso de las mascotas: " << promedioPeso << " kg" << endl;
    cout << "Mascota con mayor peso: " << mascotaMayorPeso << " (" << mayorPeso << " kg)" << endl;
}

//Funcion 5: Componente
void componente(){
    if (totalMascotas == 0) {
        cout << "No hay registros para generar una recomendacion." << endl;
        return;
    }
    string nombreBuscar;
    cout << "Componente creativo: " << endl;
    cout << "Ingrese el nombre de la mascota: ";
    cin >> nombreBuscar;

    bool encontrada = false;
    for (int i = 0; i < totalMascotas; i++){
        if (nombres[i] == nombreBuscar) {
            encontrada = true;

            cout << "----RECOMENDACION NUTRICIONAL----" << endl;
            cout << "Mascota: " << nombres[i] << "; Peso: " << peso[i] << " kg" << endl;

            if (peso[i] < 5.0){
                cout << "Porcion sugerida para raza pequena: 100 g de alimento diario" << endl;
            } else if (peso[i] <= 15.5){
                cout << "Porcion sugerida para raza mediana: 250 g de alimento diario" << endl;
            } else {
                cout << "Porcion sugerida para raza grande: 400 g o mas de alimento diario" << endl;
            }
            break;
        }
    }
    if (!encontrada){
        cout << "Mascota no encontrada." << endl;
    }
}