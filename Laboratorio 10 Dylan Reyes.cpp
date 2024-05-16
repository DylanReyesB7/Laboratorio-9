#include <iostream>
#include <stack>
#include <queue>
#include <windows.h> // Para utilizar colores en la consola

using namespace std;

// Estructura para representar una tarea
struct Task {
    string description;
    // Puedes añadir más campos según sea necesario, como fecha de vencimiento, prioridad, etc.
};

// Función para establecer el color del texto en la consola
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Función para limpiar la pantalla de la consola
void clearScreen() {
    system("cls"); // En sistemas Windows
    // Puedes agregar otras implementaciones para otros sistemas operativos si es necesario
}

int main() {
    stack<Task> taskStack; // Pila para gestionar las tareas
    queue<Task> taskQueue; // Cola para gestionar las tareas

    int choice;
    do {
        // Limpiar la pantalla antes de mostrar el menú
        clearScreen();
        // Cambiar el color del texto para resaltar el menú
        setColor(15); // Texto blanco
        // Menú de opciones
        cout << "==============================" << endl;
        setColor(14); // Texto amarillo
        cout << "       MENU PRINCIPAL       " << endl;
        setColor(15); // Texto blanco
        cout << "==============================" << endl;
        setColor(10); // Texto verde
        cout << "1. Agregar una tarea" << endl;
        cout << "2. Completar ultima tarea" << endl;
        cout << "3. Atender tarea mas antigua" << endl;
        cout << "4. Mostrar todas las tareas" << endl;
        cout << "5. Salir" << endl;
        setColor(15); // Texto blanco
        cout << "==============================" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                // Agregar una tarea
                Task newTask;
                cout << "Ingrese la descripcion de la tarea: ";
                cin.ignore(); // Limpiar el buffer del teclado
                getline(cin, newTask.description);
                taskStack.push(newTask); // Agregar a la pila
                taskQueue.push(newTask); // Agregar a la cola
                break;
            }
            case 2: {
                // Completar la ultima tarea agregada (funcion de la pila)
                if (!taskStack.empty()) {
                    cout << "Tarea completada: " << taskStack.top().description << endl;
                    taskStack.pop();
                } else {
                    cout << "No hay tareas pendientes." << endl;
                }
                break;
            }
            case 3: {
                // Atender la tarea mas antigua (funcion de la cola)
                if (!taskQueue.empty()) {
                    cout << "Tarea atendida: " << taskQueue.front().description << endl;
                    taskQueue.pop();
                } else {
                    cout << "No hay tareas pendientes." << endl;
                }
                break;
            }
            case 4: {
                // Mostrar todas las tareas
                cout << "Tareas pendientes (pila):" << endl;
                stack<Task> tempStack = taskStack;
                while (!tempStack.empty()) {
                    cout << "- " << tempStack.top().description << endl;
                    tempStack.pop();
                }
                cout << "Tareas pendientes (cola):" << endl;
                queue<Task> tempQueue = taskQueue;
                while (!tempQueue.empty()) {
                    cout << "- " << tempQueue.front().description << endl;
                    tempQueue.pop();
                }
                break;
            }
            case 5: {
                // Salir del programa
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:
                setColor(12); // Texto rojo para opciones inválidas
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        // Esperar a que el usuario presione una tecla antes de continuar
        cout << "Presione Enter para continuar...";
        cin.ignore(); // Limpiar el buffer del teclado
        cin.get(); // Esperar a que el usuario presione Enter

    } while (choice != 5);

    // Restaurar el color original de la consola antes de salir
    setColor(15); // Texto blanco

    return 0;
}

