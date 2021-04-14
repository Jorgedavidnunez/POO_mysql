#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"
using namespace std;
class Cliente :
    public Persona
{
	//atributos 
private: string nit;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	//METODOS
	//set(modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	//metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);
			string insert = "insert into clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) values('"+ nit +"', '"+ nombres +"', '"+ apellidos +"', '"+ direccion +"', "+ t +", '"+ fecha_nacimiento +"')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
					cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "-----------------------------Clientes-----------------------------\n";
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << endl;
				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
	void modificar(int id_cliente) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);
			string cl = to_string(id_cliente);
			string modificar = "update clientes set nit = '" + nit + "', nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono=" + t + ", fecha_nacimiento='" + fecha_nacimiento + "' where id_cliente =" + cl + "";
			const char* m = modificar.c_str();
			q_estado = mysql_query(cn.getconectar(), m);
			if (!q_estado) {
				cout << "Modificacion exitosa\n";
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
	void eliminar(int id_cliente) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string cl = to_string(id_cliente);
			string eliminar = "delete from clientes where id_cliente =" + cl + "";
			const char* d = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), d);
			if (!q_estado) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al eliminar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
};

