// POO_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include "Cliente.h"
using namespace std;
void ingresar();
void ver();
void modificar();
void eliminar();
int main()
{
	int op;
	do {
		system("cls");
		cout << "Ingrese la accion que desa realizar\n";
		cout << "1. Ingresar registro\n";
		cout << "2. Ver registros\n";
		cout << "3. Modificar registros\n";
		cout << "4. Eliminar registro\n";
		cout << "5. Salir\n";
		cin >> op;
		cin.ignore();
		switch (op)
		{
		case 1:
			ingresar();
			break;
		case 2:
			ver();
			break;
		case 3:
			modificar();
			break;
		case 4:
			eliminar();
			break;
		default:
			break;
		}
	} while (op != 5);
	return 0;
}
void ingresar() {
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	system("cls");
	cout << "Ingrese el nit: ";
	getline(cin, nit);
	cout << "Ingrese el nombre: ";
	getline(cin, nombres);
	cout << "Ingrese el apellido: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion: ";
	getline(cin, direccion);
	cout << "Ingrese el telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese la fecha de nacimiento: ";
	getline(cin, fecha_nacimiento);
	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.crear();
	system("pause");
}
void ver() {
	system("cls");
	Cliente c = Cliente();
	c.leer();
	system("pause");
}

void modificar() {
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono, id_cliente;
	system("cls");
	cout << "Ingrese el id a modificar: ";
	cin >> id_cliente;
	cin.ignore();
	cout << "Ingrese el nit: ";
	getline(cin, nit);
	cout << "Ingrese el nombre: ";
	getline(cin, nombres);
	cout << "Ingrese el apellido: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion: ";
	getline(cin, direccion);
	cout << "Ingrese el telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese la fecha de nacimiento: ";
	getline(cin, fecha_nacimiento);
	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.modificar(id_cliente);
	system("pause");
}
void eliminar() {
	int id_cliente;
	system("cls");
	cout << "Ingrese el id a eliminar: ";
	cin >> id_cliente;
	cin.ignore();
	Cliente c = Cliente();
	c.eliminar(id_cliente); 
	system("pause");
}