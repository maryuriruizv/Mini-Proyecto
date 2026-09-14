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

int main() {
    //Declaramos las variables
    string nombres[20];
    string razas[20];
    int edades[20];
    double pesos[20];
    int cantidadMascotas = 0;
    int opcion;

    //Utilizamos do while 
    do {
        cout << "===== REGISTRO DE MASCOTAS =====";
        cout << "1. Registrar mascota";
        cout << "2. Buscar mascota por nombre";
        cout << "3. Mostrar mascotas registradas";
        cout << "4. Salir";
        cout << "Seleccione una opcion por favor: ";
        cin >> opcion;

        //

        if 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                if (cantidadMascotas == MAX_MASCOTAS) {
                    cout << "Se alcanzo el limite de 20 mascotas. No se pueden agregar mas registros.\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nombre: ";
                getline(cin, nombres[cantidadMascotas]);
                cout << "Edad: ";
                cin >> edades[cantidadMascotas];
                cout << "Peso en kilogramos: ";
                cin >> pesos[cantidadMascotas];
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Raza: ";
                getline(cin, razas[cantidadMascotas]);
                cantidadMascotas++;
                cout << "Mascota registrada correctamente.\n";
                break;

            case 2: {
                string nombreBuscado;
                bool encontrada = false;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese el nombre de la mascota: ";
                getline(cin, nombreBuscado);

                for (int i = 0; i < cantidadMascotas; i++) {
                    if (nombres[i] == nombreBuscado) {
                        cout << "\nMascota encontrada:\n";
                        cout << "Nombre: " << nombres[i] << '\n';
                        cout << "Edad: " << edades[i] << " anos\n";
                        cout << "Peso: " << pesos[i] << " kg\n";
                        cout << "Raza: " << razas[i] << '\n';
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada) {
                    cout << "No se encontro una mascota con ese nombre.\n";
                }
                break;
            }

            case 3:
                if (cantidadMascotas == 0) {
                    cout << "No hay mascotas registradas.\n";
                    break;
                }

                cout << "\nMascotas registradas:\n";
                for (int i = 0; i < cantidadMascotas; i++) {
                    cout << i + 1 << ". " << nombres[i]
                         << " | Edad: " << edades[i]
                         << " anos | Peso: " << pesos[i]
                         << " kg | Raza: " << razas[i] << '\n';
                }
                break;

            case 4:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}